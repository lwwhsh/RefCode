######################################################################
# Automatically generated by qmake (2.01a) Tue Jan 23 16:13:55 2007
######################################################################

CONFIG += uitools qt assistant
TEMPLATE = app
DEPENDPATH += ../include
INCLUDEPATH += ../include

# XML-RPC
#INCPATH     += /usr/local/xerces-c-src2_4_0/include
#LIBS        += -L/usr/local/lib -lxerces-c -lxmlrpc -lxmlrpc++ -lxmlrpc_abyss -lxmlrpc_client -lxmlrpc_client++ -lxmlrpc_cpp -lxmlrpc_server -lxmlrpc_server++ -lxmlrpc_server_abyss -lxmlrpc_server_cgi -lxmlrpc_util -lxmlrpc_xmlparse -lxmlrpc_xmltok

#EPICS lib
EPICS_DIR = /usr/local/epics/base
INCPATH     += $$EPICS_DIR/include $$EPICS_DIR/include/os/Linux
LIBS        += -L$$EPICS_DIR/lib/linux-x86 -lasHost -lcas -ldbStaticHost -lgdd -lrecIoc -lsoftDevIoc -lasIoc -lCom -ldbStaticIoc -lregistryIoc -ltestDevIoc -lca -ldbIoc -ldbtoolsIoc -lmiscIoc -lrsrvIoc

# EPICS Extensions
EPICS_EXT_DIR = /usr/local/epics/extensions
INCPATH     += $$EPICS_EXT_DIR/src/ChannelArchiver/Tools/ $$EPICS_EXT_DIR/src/ChannelArchiver/Storage/
LIBS        += -L$$EPICS_EXT_DIR/src/ChannelArchiver/Tools/O.linux-x86 -lTools -L$$EPICS_EXT_DIR/src/ChannelArchiver/Storage/O.linux-x86 -lStorage

#QWT LIBS
INCPATH += /usr/local/qwt/include
LIBS += -L/usr/local/qwt/lib -lqwt


#KWT LIBS
INCPATH += /usr/local/opisrc/kwt/include
LIBS += -L/usr/local/opi/lib -lkwt

# Shared lib
INCPATH += /usr/local/opisrc/include
# LIBS += -L/usr/local/opi/lib -lmultiplot
LIBS += -L/usr/local/opi/lib -lmultiplot -lpvlistviewer

# mysql
INCPATH += /usr/include/mysql

# mysql++ lib
INCPATH += /usr/local/include/mysql++
LIBS += -L/usr/local/lib -lmysqlpp


# Input
SOURCES += ../MainWindow.cpp ../main.cpp 
HEADERS += ../include/MainWindow.h
RESOURCES += ../fuel.qrc


# Install
TARGET = Fuel
target.path = /usr/local/opi/bin
forms.files = ../ui/*.ui
forms.path = /usr/local/opi/ui
images.files = ../images/*.png
images.files += ../images/*.xpm
images.path = /usr/local/opi/images
resources.files = /usr/local/opi/ui/
doc.files = ../doc/*
docimage.files = ../doc/images/*
doc.path = /usr/local/opi/doc
docimage.path = /usr/local/opi/doc/images
INSTALLS += target forms images doc docimage resources