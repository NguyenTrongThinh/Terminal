#-------------------------------------------------
#
# Project created by QtCreator 2015-10-03T22:53:10
#
#-------------------------------------------------

QT       += core gui
QT += serialport
QT += multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Terminal
TEMPLATE = app


SOURCES += main.cpp\
        terminal.cpp \
    setting.cpp \
    infosound.cpp \
    validinput.cpp \
    subclasslnsend.cpp

HEADERS  += terminal.h \
    setting.h \
    infosound.h \
    validinput.h \
    subclasslnsend.h

FORMS    += terminal.ui \
    setting.ui

RESOURCES += \
    resource.qrc
