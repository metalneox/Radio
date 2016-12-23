#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QFile"
#include "QTextStream"
#include <QMessageBox>
#include "player.h"
#include <iostream>
#include <QXmlStreamReader>
#include <QCloseEvent>

Player stream;
bool is_started = false;
bool trayico_activate = 1;
QSystemTrayIcon *trayIcon;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    MainWindow::radiolist();
    MainWindow::createActions();
    MainWindow::createTrayIcon();

    //Default valore
    ui->listWidget->item(0)->setSelected(true);
    ui->listWidget->setCurrentItem(ui->listWidget->item(0));

    //Setto Volume
    ui->AudioSlider->setValue(100);
    connect(ui->actionInformation,SIGNAL(triggered(bool)),this, SLOT(about()));
    connect(ui->actionUpdate,SIGNAL(triggered(bool)),this, SLOT(update()));

    /****************************************************************************************************/
}
//Sostituire con il trayico
void MainWindow::closeEvent (QCloseEvent *event)
{
    /*
    Ogni volta che arriva un segnale di chiusura se il flag trayico e attivo faccio chiudere se no
    passo in modalita trayico*/
    event->ignore();
    hide();
    trayIcon->show();
}


MainWindow::~MainWindow()
{
    delete ui;
    //delete stream;
}
void MainWindow::about(){
    QMessageBox messageBox;
    //messageBox.critical(0,"Error","An error has occured !");
    messageBox.information(0,"Informazioni","Semplice programma per la gestione di radio italiane");
}

void MainWindow::update(){
    QMessageBox messageBox;
    //messageBox.critical(0,"Error","An error has occured !");
    messageBox.information(0,"Aggiornamenti","Proprietà ancora non disponibile");
}


void MainWindow::iconActivated(QSystemTrayIcon::ActivationReason reason)
{
    if ( reason == QSystemTrayIcon::Trigger ){
              QWidget::showMaximized();
        }
}

void MainWindow::createActions()
{
    //QAction e connessioni
    maximizeAction = new QAction(tr("&Open"), this);
    connect(maximizeAction, &QAction::triggered, this, &QWidget::showMaximized);
    quitAction = new QAction(tr("&Quit"), this);
    connect(quitAction, &QAction::triggered, qApp, &QCoreApplication::quit);

}

void MainWindow::createTrayIcon()
{
    //Costruzione della TrayIcon
    trayIconMenu = new QMenu(this);
    trayIconMenu->addAction(maximizeAction);
    trayIconMenu->addSeparator();
    trayIconMenu->addAction(quitAction);

    trayIcon = new QSystemTrayIcon(this);
    trayIcon->setContextMenu(trayIconMenu);
    trayIcon->setIcon(QIcon("img/icona.ico"));
    trayIcon->setToolTip("Radio by MetalNeox");

    //showMaximized da click
    connect(trayIcon, SIGNAL(activated(QSystemTrayIcon::ActivationReason)), this, SLOT(iconActivated(QSystemTrayIcon::ActivationReason)));
}

void MainWindow::on_PlayButton_clicked()
{   
    if (is_started == false){
        ui->PlayButton->setIcon(QIcon("img/stop_audio.png"));

        stream.playFile(ui->listWidget->currentItem()->text());
        is_started = true;
    }
    else{
        ui->PlayButton->setIcon(QIcon("img/play_audio.png"));
        stream.stopFile();
        is_started = false;
    }
}
void MainWindow::radiolist(){
    /*********************************************************************************/
    // Leggere file da xml
      QFile current_file("radio.xml");
      if (!current_file.open(QIODevice::ReadOnly | QIODevice::Text))
      {
          std::cout << "Couldn't open file" << std::endl;
          //return 1;
      }
      else
      {
          std::cout << "File opened OK" << std::endl;
      }
      QXmlStreamReader xml(&current_file);
      //QXmlStreamReader xml(current_file.readAll());
      while (!xml.atEnd()) {
            //output+=xml.readElementText();
            xml.readNext();
            //xml.readNextStartElement()
            if(xml.name() == "Radio"){
                //controllo update e aggiorno il file se e una versione superiore
                foreach(const QXmlStreamAttribute &attr, xml.attributes()) {
                                    if (attr.name().toString() == QLatin1String("url")) {
                                        QString attribute_value = attr.value().toString();
                                        ui->listWidget->addItem(attribute_value);
                                    }
                                }
            }
            if(xml.name() == "Update"){
                //controllo update e aggiorno il file se e una versione superiore
                foreach(const QXmlStreamAttribute &attr, xml.attributes()) {
                                    if (attr.name().toString() == QLatin1String("version_sw")) {
                                        //Controllo versione
                                        //QString attribute_value = attr.value().toString();
                                        //std::cout << attribute_value.toStdString(); //1.0.2 currente
                                    }
                                }
            }
        }

      if (xml.hasError()) {
            // do error handling
      }
      current_file.close();
   /*********************************************************************************/
}
void MainWindow::on_listWidget_doubleClicked(const QModelIndex &index)
{
    if (is_started == true && stream.isPlayed()){
        ui->PlayButton->setIcon(QIcon("img/play_audio.png"));
        //ui->PlayButton->setIcon(QIcon("img/stop_audio.png"));
        /*****************************************************/
        stream.stopFile();
        is_started = false;
    }
    else{
        //ui->PlayButton->setIcon(QIcon("img/play_audio.png"));
        ui->PlayButton->setIcon(QIcon("img/stop_audio.png"));
        stream.playFile(ui->listWidget->currentItem()->text());
        is_started = true;
    }
}

void MainWindow::on_AudioSlider_sliderMoved(int position)
{
    stream.setAudio(position);
}
