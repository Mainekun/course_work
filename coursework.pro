CONFIG += c++20
QMAKE_CXXFLAGS += -std=c++20

TEMPLATE = app
QT += core gui widgets

SOURCES += \
    main.cpp \
    mainwindow.cpp \
    mathvectormodel.cpp \
    vecexceptions.cpp \
    vectordata.cpp \
    vectorinputdialog.cpp

FORMS += \
    mainwindow.ui \
    vectorinputdialog.ui

HEADERS += \
    geometryvectorlib.h \
    mainwindow.h \
    mathvectormodel.h \
    vecexceptions.h \
    vectordata.h \
    vectorinputdialog.h

TARGET = main.cpp

DISTFILES += \
    .gitignore
