#-------------------------------------------------
#
# Project created by QtCreator 2015-07-24T21:31:04
#
#-------------------------------------------------

QT       += core

QT       -= gui

TARGET = ZOO
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    zoo_file_util.cpp \
    bidir_list.cpp \
    zoo_animal.cpp \
    bidir_list_element.cpp

HEADERS += \
    zoo_file_util.h \
    bidir_list_element.h \
    bidir_list.h \
    zoo_animal.h
