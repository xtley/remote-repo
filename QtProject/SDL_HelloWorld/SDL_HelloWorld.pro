TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp
win32 {
INCLUDEPATH += $$PWD/SDL2-2.0.10/include
LIBS += $$PWD/SDL2-2.0.10/lib/x86/SDL2.lib
}
