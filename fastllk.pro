#-------------------------------------------------
#
# Project created by QtCreator 2020-07-04T13:58:39
#
#-------------------------------------------------

QT       += core gui multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = fastllk
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
        main.cpp \
        mainwindow.cpp \
    settings.cpp \
    help.cpp \
    game.cpp \
    ranklist.cpp \
    gamemap.cpp \
    cellbtn.cpp \
    msgbox.cpp

HEADERS += \
        mainwindow.h \
    settings.h \
    help.h \
    game.h \
    ranklist.h \
    gamemap.h \
    cellbtn.h \
    msgbox.h

FORMS += \
        mainwindow.ui \
    settings.ui \
    help.ui \
    game.ui \
    ranklist.ui \
    msgbox.ui

RESOURCES += \
    resourse.qrc

DISTFILES += \
    resource/image/myicon.rc \
    resource/image/xxb.ico

RC_FILE+= resource/image/myicon.rc
