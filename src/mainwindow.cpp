#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QFile"
#include "QTextStream"
#include "QMessageBox"
#include "QtMultimedia/QMediaPlayer"
#include <iostream>
#include <QDebug>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->AudioSlider->setValue(100);
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
    /***************************************************************************************************/
    ui->listWidget->item(0)->setSelected(true);
    player = new QMediaPlayer(this, QMediaPlayer::StreamPlayback);
    player->setVolume(100);
    //Questo worka anche con un piccolo difetto di riproduzione al inizio
    player->setMedia(QUrl("http://a.tumblr.com/tumblr_ljza0ntBOS1qhr5ujo1.mp3"));
    player->play();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_PlayButton_clicked()
{
    //ui->listWidget->currentItem()->text();
    //player->setMedia(QUrl(ui->listWidget->currentItem()->text()));
    /*
    if(ui->listWidget->currentItem()->text() != ""){
        QMessageBox::information(0, "error", ui->listWidget->currentItem()->text());
    }
    else{
        QMessageBox::information(0, "error", "Nessun oggetto selezionato");
    }
    */
    //QMessageBox::information(0, "error", ui->listWidget->currentItem()->text());
}

void MainWindow::on_listWidget_doubleClicked(const QModelIndex &index)
{
    //Worka il messagebox
    //QMessageBox::information(0, "error", ui->listWidget->currentItem()->text());
    player->setMedia(QUrl(ui->listWidget->currentItem()->text()));
}
