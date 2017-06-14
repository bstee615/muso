#-------------------------------------------------
#
# Project created by QtCreator 2017-04-02T13:42:23
#
#-------------------------------------------------

QT       += widgets multimedia core gui

TARGET = Muso
TEMPLATE = app


SOURCES += main.cpp\
        startwidget.cpp \
    gamewidget.cpp \
    movablelabel.cpp

HEADERS  += startwidget.h \
    gamewidget.h \
    movablelabel.h

FORMS    += startwidget.ui \
    gamewidget.ui

RESOURCES += \
    resources.qrc
