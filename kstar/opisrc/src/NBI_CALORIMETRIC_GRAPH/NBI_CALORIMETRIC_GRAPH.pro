#-------------------------------------------------
#
# Project created by QtCreator 2012-09-05T20:33:26
#
#-------------------------------------------------

TARGET = NB1_CAL_G
TEMPLATE = app
CONFIG += uitools \
    qt

# EPICS Lib
EPICS_DIR = /usr/local/epics/R3.14.12.2/base
INCPATH += $$EPICS_DIR/include \
    $$EPICS_DIR/include/os/Linux

# QWT Lib
INCPATH += /usr/local/qwt-5.0.2/include
LIBS += -L/usr/local/qwt-5.0.2/lib \
    -lqwt

# KWT Lib
KWTDIR = /usr/local/epics/extensions/src/kwt-r826
#KWTDIR = /usr/local/opisrc/kwt
INCPATH += $$KWTDIR/include
#INCPATH += /usr/local/opi/include
LIBS += -L/$$KWTDIR/lib \
    -lkwt

SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h

FORMS    += mainwindow.ui

ui.files = *.ui
INSTALLBASE    = /usr/local/opi
target.path    = $$INSTALLBASE/bin
ui.path        = $$INSTALLBASE/ui
INSTALLS       = target ui