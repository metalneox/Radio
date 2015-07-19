#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QFile"
#include "QTextStream"
#include "QMessageBox"
#include <QDebug>
#include "player.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    bool is_started = false;

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
    /***************************************************************************************************/
    // Creo QMediaPlayer e setto volume e slide volume
    /***************************************************************************************************/
    //ui->listWidget->item(0)->setSelected(true);
    //player = new QMediaPlayer(this, QMediaPlayer::StreamPlayback);
    //player->setVolume(100);
    ui->AudioSlider->setValue(100);
    //Questo worka anche con un piccolo difetto di riproduzione al inizio
    //player->setMedia(QUrl("http://a.tumblr.com/tumblr_ljza0ntBOS1qhr5ujo1.mp3"));
    //player->play();
    /***************************************************************************************************/
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_PlayButton_clicked()
{
    if (is_started == false){
        ui->PlayButton->setIcon(QIcon("img/stop_audio.png"));
        /*****************************************************/
        is_started = true;
    }
    else{
        ui->PlayButton->setIcon(QIcon("img/play_audio.png"));
        is_started = false;
    }
    //ui->listWidget->currentItem()->text();
    //player->setMedia(QUrl(ui->listWidget->currentItem()->text()));
    Player stream;
    stream.playFile(ui->listWidget->currentItem()->text());

}

void MainWindow::on_listWidget_doubleClicked(const QModelIndex &index)
{
    //Worka il messagebox
    //QMessageBox::information(0, "error", ui->listWidget->currentItem()->text());
    //player->setMedia(QUrl(ui->listWidget->currentItem()->text()));
    //Player test();
    Player stream;
    stream.playFile(ui->listWidget->currentItem()->text());
}

void MainWindow::on_AudioSlider_sliderMoved(int position)
{
    //player->setVolume(position);
}
