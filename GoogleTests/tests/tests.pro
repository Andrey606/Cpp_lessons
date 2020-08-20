include(gtest_dependency.pri)

TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG += thread
CONFIG -= qt


INCLUDEPATH += ../Lab9

HEADERS += \
        ../Lab9/IKeypad.h \
        ../Lab9/ILatch.h \
        ../Lab9/lockcontroller.h \
        ../Lab9/my_class.h \
        tst_testdivisionbyzero.h

SOURCES += \
        ../Lab9/lockcontroller.cpp \
        ../Lab9/my_class.cpp \
        main.cpp
