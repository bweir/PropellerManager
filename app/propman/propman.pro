include(../../common.pri)
include(../../include.pri)

TEMPLATE = app
TARGET = propman
DESTDIR = $$TOP_PWD/bin/

CONFIG += console

SOURCES += \
    main.cpp

target.path   = $$PREFIX/bin
INSTALLS += target
