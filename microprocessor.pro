TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt
CONFIG += c++11

SOURCES += main.cpp \
    output.cpp \
    bootloader.cpp \
    memory.cpp \
    ula.cpp \
    opcode.cpp \
    word.cpp \
    binary.cpp \
    pc.cpp \
    reg.cpp \
    regi.cpp

HEADERS += \
    output.h \
    bootloader.h \
    memory.h \
    ula.h \
    opcode.h \
    word.h \
    binary.h \
    pc.h \
    reg.h \
    regi.h

