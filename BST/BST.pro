QT += core
QT -= gui

CONFIG += c++11

TARGET = BST
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    tree_node.cpp

HEADERS += \
    tree_node.h
