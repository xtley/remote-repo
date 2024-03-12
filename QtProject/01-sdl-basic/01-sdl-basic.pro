TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.c

win32 {
INCLUDEPATH += $$PWD/SDL2-2.28.1/include
LIBS += $$PWD/SDL2-2.28.1/lib/x86/SDL2.lib
}
