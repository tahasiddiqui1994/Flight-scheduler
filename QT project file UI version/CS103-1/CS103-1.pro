#-------------------------------------------------
#
# Project created by QtCreator 2016-06-01T14:14:20
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = CS103-1
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    pilot.cpp \
    plane.cpp \
    flight.cpp \
    airline.cpp \
    inputdialog.cpp \
    flightstaff.cpp \
    flightengineer.cpp

HEADERS  += mainwindow.h \
    pilot.h \
    plane.h \
    flight.h \
    airline.h \
    inputdialog.h \
    flightstaff.h \
    flightengineer.h

FORMS    += mainwindow.ui \
    inputdialog.ui
