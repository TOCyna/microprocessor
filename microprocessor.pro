TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt
CONFIG += c++11

SOURCES += main.cpp \
    output.cpp \
    bootloader.cpp \
    memory.cpp \
    binary.cpp

HEADERS += \
    output.h \
    bootloader.h \
    memory.h \
    binary.h

