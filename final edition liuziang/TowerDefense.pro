#-------------------------------------------------
#
# Project created by QtCreator 2020-05-28T11:20:54
#
#-------------------------------------------------

QT       += core gui
QT       += multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = TowerDefense
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
    Bullet.cpp \
        main.cpp \
        mainwindow.cpp \
    monster.cpp \
    selectionbox.cpp \
    defetowerparent.cpp \
    startfrom.cpp \
    tower1.cpp \
    tower2.cpp \
    tower3.cpp \
    tower4.cpp \
    towerposition.cpp

HEADERS += \
        mainwindow.h \
    monster.h \
    selectionbox.h \
    globalstruct.h \
    defetowerparent.h \
    startfrom.h \
    tower1.h \
    tower2.h \
    tower3.h \
    tower4.h \
    towerposition.h

FORMS += \
    startfrom.ui

RESOURCES += \
    image.qrc
