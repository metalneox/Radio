#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QFile"
#include "QTextStream"
#include "QMessageBox"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // Leggo il file e populo widget
    /***************************************************************************************************/
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
}

MainWindow::~MainWindow()
{
    delete ui;
}
