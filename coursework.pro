CONFIG += c++20
QMAKE_CXXFLAGS += -std=c++20

TEMPLATE = app
QT += core gui widgets

SOURCES += \
    main.cpp \
    mainwindow.cpp \
    vectordata.cpp \
    vectorinputdialog.cpp \
    vectormodel.cpp

FORMS += \
    mainwindow.ui \
    vectorinputdialog.ui

HEADERS += \
    geometryvectorlib.h \
    mainwindow.h \
    vectordata.h \
    vectorexceptions.h \
    vectorinputdialog.h \
    vectormodel.h

TARGET = main.cpp
