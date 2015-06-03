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
    line.cpp \
    opcode.cpp \
    word.cpp \
    binary.cpp

HEADERS += \
    output.h \
    bootloader.h \
    memory.h \
    ula.h \
    line.h \
    opcode.h \
    word.h \
    binary.h

