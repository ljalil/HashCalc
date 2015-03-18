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

SOURCES += Core/main.cpp\
        Window/widget.cpp \
    Core/HashCalcer/qhashcalc.cpp \
    Core/HashCracker/qhashcracker.cpp

HEADERS  += Window/widget.h \
    Core/HashCalcer/qhashcalc.h \
    Core/HashCracker/qhashcracker.h

FORMS    += Window/widget.ui

RESOURCES += Resources/Resources.qrc
OTHER_FILES += \
    CHANGELOG
