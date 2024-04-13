include(gtest_dependency.pri)

TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG += thread
CONFIG += qt
CONFIG += gcov

SOURCES += \
        ../model.cpp \
        tests.cpp \

HEADERS += \
    ../model.h
