#include "mainwindow.h"
#include <QApplication>
#import "player.h"
#include <QSystemTrayIcon>
#include <QMessageBox>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    //Player stream;
    //Player* stream;
    //QObject::connect(&a, SIGNAL(aboutToQuit()), &w, SLOT(hide()));
    w.show();

    return a.exec();
}
