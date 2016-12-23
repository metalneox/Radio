#-------------------------------------------------
#
# Project created by QtCreator 2015-06-13T21:55:37
#
#-------------------------------------------------

QT       += core gui multimedia
LIBS     += -lvlc

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Radio
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    player.cpp

HEADERS  += mainwindow.h \
    player.h

FORMS    += mainwindow.ui

OTHER_FILES += \
    ../LICENSE \
    ../README.md


DISTFILES += \
    img/icona.png \
    img/speaker.png \
    img/play_audio.png \
    img/stop_audio.png \
    radio.xml \
    img/icona.ico
