TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt
CONFIG += c++11
LIBS += -L"C:\Qt\SFML-2.3.2\lib"

CONFIG(release, debug|release):
LIBS += -lsfml-audio -lsfml-graphics -lsfml-main -lsfml-network -lsfml-window -lsfml-system

CONFIG(debug, debug|release):
LIBS += -lsfml-audio-d -lsfml-graphics-d -lsfml-main-d -lsfml-network-d -lsfml-window-d -lsfml-system-d

INCLUDEPATH += "C:\Qt\SFML-2.3.2\include"

SOURCES += main.cpp \
    player.cpp \
    entity.cpp \
    enemy.cpp \
    bullet.cpp \
    enemies.cpp \
    game.cpp
include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    globals.h \
    player.h \
    entity.h \
    bullet.h \
    enemy.h \
    enemies.h \
    game.h
