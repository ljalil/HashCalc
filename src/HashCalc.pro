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

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = HashCalc
TEMPLATE = app

SOURCES += main.cpp\
        widget.cpp \
    qhashcalc.cpp

HEADERS  += widget.h \
    qhashcalc.h

FORMS    += widget.ui

OTHER_FILES += \
    CHANGELOG
