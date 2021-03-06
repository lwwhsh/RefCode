######################################################################
# Project file to make Makefile for KWT example
# Written by Sulhee Baek <shbaek@nfri.re.kr> (20 Jan 2010)
######################################################################

CONFIG += uitools qt
TEMPLATE = app
TARGET = 
DEPENDPATH += ..
INCLUDEPATH += ..

# Input
SOURCES += ../main.cpp ../MainWindow.cpp
HEADERS += MainWindow.h

KWTDIR = /usr/local/opisrc/kwt
INCPATH     += $$KWTDIR/include
LIBS        += -L$$KWTDIR/lib -lkwt

#EPICS lib
INCPATH     += $(EPICS_BASE)/include $(EPICS_BASE)/include/os/Linux

#QWT
INCPATH		+= $(QWT_HOME)/include

# Output
TARGET = example
target.path = .
forms.files = ../ui/*.ui
forms.path = /usr/local/opi/ui
images.files = ../images/*.png
images.path = /usr/local/opi/images
sources.files = $$SOURCES $$HEADERS *.ui *.pro
sources.path = ../
# install
# INSTALLS += target forms
