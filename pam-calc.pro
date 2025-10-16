#-------------------------------------------------
#
# Project created by QtCreator 2017-03-05T15:54:45
#
#-------------------------------------------------

VERSION = 2024
DEFINES += APPVERSION=\\\"$$VERSION\\\"

QT       += core gui

QMAKE_LFLAGS_RELEASE += -static -static-libgcc

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = pam-calc
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


SOURCES += main.cpp\
        mainwindow.cpp \
    qlabstatustablewgt.cpp \
    qlabstructuretablewgt.cpp \
    qlabtransitiontablewgt.cpp \
    qwelcomewgt.cpp \
    qlabworkerwgt.cpp \
    qindwgt.cpp \
    qlabvarchosewgt.cpp \
    qlabcarnocardwgt.cpp \
    qtermedit.cpp \
    qlabreportwgt.cpp \
    qbasisedit.cpp \
    qfileworker.cpp \
    qlabdatabase.cpp \
    cardcarno.cpp \
    statemanager.cpp

HEADERS  += mainwindow.h \
    qlabstatustablewgt.h \
    qlabstructuretablewgt.h \
    qlabtransitiontablewgt.h \
    qwelcomewgt.h \
    qlabworkerwgt.h \
    qindwgt.h \
    qlabvarchosewgt.h \
    qlabcarnocardwgt.h \
    qtermedit.h \
    qlabreportwgt.h \
    qbasisedit.h \
    qfileworker.h \
    qlabdatabase.h \
    cardcarno.h \
    statemanager.h

FORMS    += mainwindow.ui \
    qlabstatustablewgt.ui \
    qlabstructuretablewgt.ui \
    qlabtransitiontablewgt.ui \
    qwelcomewgt.ui \
    qlabworkerwgt.ui \
    qlabvarchosewgt.ui \
    qlabcarnocardwgt.ui \
    qtermedit.ui \
    qlabreportwgt.ui \
    qbasisedit.ui

RESOURCES += \
    resources.qrc

