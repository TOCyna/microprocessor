TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt
CONFIG += c++11

SOURCES += main.cpp \
    bootloader.cpp \
    memory.cpp \
    ula.cpp \
    word.cpp \
    binary.cpp \
    pc.cpp \
    reg.cpp \
    regi.cpp \
    cu.cpp

HEADERS += \
    bootloader.h \
    memory.h \
    ula.h \
    word.h \
    binary.h \
    pc.h \
    reg.h \
    regi.h \
    cu.h

