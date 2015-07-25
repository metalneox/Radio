#include "mainwindow.h"
#include <QApplication>
#import "player.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    //Player stream;
    Player* stream;
    w.show();

    return a.exec();
}
