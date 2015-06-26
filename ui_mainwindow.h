/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionEsci;
    QAction *actionInformation;
    QWidget *centralWidget;
    QLabel *imgLeft;
    QLabel *imgRight;
    QPushButton *playButton;
    QSlider *soundSlider;
    QListWidget *listWidget;
    QToolBar *mainToolBar;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menu;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->setEnabled(true);
        MainWindow->resize(465, 340);
        QIcon icon;
        icon.addFile(QStringLiteral("img/favicon.ico"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        actionEsci = new QAction(MainWindow);
        actionEsci->setObjectName(QStringLiteral("actionEsci"));
        actionInformation = new QAction(MainWindow);
        actionInformation->setObjectName(QStringLiteral("actionInformation"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        imgLeft = new QLabel(centralWidget);
        imgLeft->setObjectName(QStringLiteral("imgLeft"));
        imgLeft->setGeometry(QRect(30, 20, 91, 81));
        imgLeft->setPixmap(QPixmap(QString::fromUtf8("img/speaker.jpg")));
        imgLeft->setScaledContents(true);
        imgRight = new QLabel(centralWidget);
        imgRight->setObjectName(QStringLiteral("imgRight"));
        imgRight->setGeometry(QRect(340, 20, 91, 81));
        imgRight->setPixmap(QPixmap(QString::fromUtf8("img/speaker.jpg")));
        imgRight->setScaledContents(true);
        playButton = new QPushButton(centralWidget);
        playButton->setObjectName(QStringLiteral("playButton"));
        playButton->setGeometry(QRect(130, 50, 31, 27));
        QIcon icon1;
        icon1.addFile(QStringLiteral("img/play_audio.png"), QSize(), QIcon::Normal, QIcon::Off);
        playButton->setIcon(icon1);
        soundSlider = new QSlider(centralWidget);
        soundSlider->setObjectName(QStringLiteral("soundSlider"));
        soundSlider->setGeometry(QRect(170, 50, 160, 29));
        soundSlider->setOrientation(Qt::Horizontal);
        listWidget = new QListWidget(centralWidget);
        listWidget->setObjectName(QStringLiteral("listWidget"));
        listWidget->setGeometry(QRect(30, 111, 401, 181));
        MainWindow->setCentralWidget(centralWidget);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 465, 25));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        menu = new QMenu(menuBar);
        menu->setObjectName(QStringLiteral("menu"));
        MainWindow->setMenuBar(menuBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menu->menuAction());
        menuFile->addAction(actionEsci);
        menu->addAction(actionInformation);

        retranslateUi(MainWindow);
        QObject::connect(actionEsci, SIGNAL(triggered()), MainWindow, SLOT(close()));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        actionEsci->setText(QApplication::translate("MainWindow", "Esci", 0));
        actionInformation->setText(QApplication::translate("MainWindow", "Information", 0));
        imgLeft->setText(QString());
        imgRight->setText(QString());
        playButton->setText(QString());
        menuFile->setTitle(QApplication::translate("MainWindow", "File", 0));
        menu->setTitle(QApplication::translate("MainWindow", "?", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
