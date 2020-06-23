QT = core network

CONFIG += c++14


DEFINES += QT_DEPRECATED_WARNINGS QT_DISABLE_DEPRECATED_BEFORE=0x060000

SOURCES += \
        clientconnection.cpp \
        main.cpp \
        webserver.cpp

HEADERS += \
    clientconnection.h \
    webserver.h
