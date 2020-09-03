TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
QT       += core
QT       += network
QT       += sql


SOURCES += \
        lockcontroller.cpp \
        main.cpp \
        my_class.cpp

HEADERS += \
    IKeypad.h \
    ILatch.h \
    lockcontroller.h \
    my_class.h
