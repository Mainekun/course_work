CONFIG += c++20
QMAKE_CXXFLAGS += -std=c++20

TEMPLATE = app
QT += core gui widgets

SOURCES += \
    main.cpp \
    mainwindow.cpp \
    vecexceptions.cpp \
    vectorinputdialog.cpp

FORMS += \
    mainwindow.ui \
    vectorinputdialog.ui

HEADERS += \
    geometryvectorlib.h \
    mainwindow.h \
    vecexceptions.h \
    vectorinputdialog.h

TARGET = main.cpp

DISTFILES += \
    .gitignore
