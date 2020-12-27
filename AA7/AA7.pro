TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        dictionary.cpp \
        main.cpp \
        segdictionary.cpp \
        tests.cpp

HEADERS += \
    consts.h \
    dictionary.h \
    segdictionary.h \
    segment.h \
    tests.h \
    word.h
