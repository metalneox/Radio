#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QFile"
#include "QTextStream"
#include "QMessageBox"
#include "player.h"
#include <iostream>

Player stream;
bool is_started = false;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    /****************************************************************************************************/
    // Leggo il file e populo widget
    /****************************************************************************************************/
    QFile file("radio.txt");
    if(!file.open(QIODevice::ReadOnly)) {
        QMessageBox::information(0, "error", file.errorString());
    }

    QTextStream in(&file);

    while(!in.atEnd()) {
        QString line = in.readLine();
        ui->listWidget->addItem(line);
    }
    file.close();

    //Default valore
    ui->listWidget->item(0)->setSelected(true);
    ui->listWidget->setCurrentItem(ui->listWidget->item(0));

    //Setto Volume
    ui->AudioSlider->setValue(100);
    connect(ui->actionInformation,SIGNAL(triggered(bool)),this, SLOT(about()));
    /****************************************************************************************************/
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
