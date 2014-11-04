#*****************************************************************************************
#                                                                                        *
#                                                                                        *
#         ██╗  ██╗ █████╗ ███████╗██╗  ██╗ ██████╗ █████╗ ██╗      ██████╗               *
#         ██║  ██║██╔══██╗██╔════╝██║  ██║██╔════╝██╔══██╗██║     ██╔════╝               *
#         ███████║███████║███████╗███████║██║     ███████║██║     ██║                    *
#         ██╔══██║██╔══██║╚════██║██╔══██║██║     ██╔══██║██║     ██║                    *
#         ██║  ██║██║  ██║███████║██║  ██║╚██████╗██║  ██║███████╗╚██████╗               *
#         ╚═╝  ╚═╝╚═╝  ╚═╝╚══════╝╚═╝  ╚═╝ ╚═════╝╚═╝  ╚═╝╚══════╝ ╚═════╝               *
#                                                                                        *
# Project : HashCalc                                                                     *
# Purpose : Calculate hashes for files and texte with different algorithms               *
# Author  : Abdeljalil Letrache                                                          *
# License : LGPL v3.0                                                                    *
# Version : 0.2                                                                          *
#                                                                                        *
#****************************************************************************************/

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = HashCalc
TEMPLATE = app

SOURCES += main.cpp\
        widget.cpp \
    qhashcalc.cpp \
    qhashcracker.cpp

HEADERS  += widget.h \
    qhashcalc.h \
    qhashcracker.h

FORMS    += widget.ui

RESOURCES += Resources.qrc
OTHER_FILES += \
    CHANGELOG
