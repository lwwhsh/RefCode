#############################################################################
# Makefile for building: CyberLogViewer
# Generated by qmake (2.01a) (Qt 4.3.2) on: Wed Mar 5 17:55:52 2014
# Project:  cyberlogviewer.pro
# Template: app
# Command: /usr/local/Trolltech/Qt-4.3.2/bin/qmake -unix -o Makefile cyberlogviewer.pro
#############################################################################

####### Compiler, tools and options

CC            = gcc
CXX           = g++
DEFINES       = -DQT_NO_DEBUG -DQT_GUI_LIB -DQT_CORE_LIB -DQT_SHARED
CFLAGS        = -pipe -O2 -D_REENTRANT -Wall -W $(DEFINES)
CXXFLAGS      = -pipe -O2 -D_REENTRANT -Wall -W $(DEFINES)
INCPATH       = -I../../../../Trolltech/Qt-4.3.2/mkspecs/linux-g++ -I. -I../../../../Trolltech/Qt-4.3.2/include/QtUiTools -I../../../../Trolltech/Qt-4.3.2/include/QtCore -I../../../../Trolltech/Qt-4.3.2/include/QtCore -I../../../../Trolltech/Qt-4.3.2/include/QtGui -I../../../../Trolltech/Qt-4.3.2/include/QtGui -I../../../../Trolltech/Qt-4.3.2/include -I../include -I/usr/include/mysql -I../../../../include/mysql++ -I../../../include -I../../../../qwt/include -I.moc -I.
LINK          = g++
LFLAGS        = -Wl,-rpath,/usr/local/Trolltech/Qt-4.3.2/lib
LIBS          = $(SUBLIBS)  -L/usr/local/Trolltech/Qt-4.3.2/lib -L/usr/local/lib -lmysqlpp -L/usr/local/opi/lib -laccesskstardb -L/usr/local/qwt/lib -lqwt -L/usr/local/Trolltech/Qt-4.3.2/lib -L/usr/X11R6/lib -pthread -pthread -pthread -lQtUiTools -L/usr/local/src/qt-x11-opensource-src-4.3.2/lib -lQtXml -pthread -pthread -pthread -pthread -lQtGui -pthread -pthread -lpng -lSM -lICE -pthread -pthread -lXi -lXrender -lXrandr -lXfixes -lXcursor -lXinerama -lfreetype -lfontconfig -lXext -lX11 -lQtCore -pthread -lz -lm -pthread -lgthread-2.0 -lglib-2.0 -lrt -lpthread -ldl
AR            = ar cqs
RANLIB        = 
QMAKE         = /usr/local/Trolltech/Qt-4.3.2/bin/qmake
TAR           = tar -cf
COMPRESS      = gzip -9f
COPY          = cp -f
SED           = sed
COPY_FILE     = $(COPY)
COPY_DIR      = $(COPY) -r
INSTALL_FILE  = install -m 644 -p
INSTALL_DIR   = $(COPY_DIR)
INSTALL_PROGRAM = install -m 755 -p
DEL_FILE      = rm -f
SYMLINK       = ln -sf
DEL_DIR       = rmdir
MOVE          = mv -f
CHK_DIR_EXISTS= test -d
MKDIR         = mkdir -p

####### Output directory

OBJECTS_DIR   = .obj/

####### Files

SOURCES       = ../main.cpp \
		../cyberlogview.cpp .moc/moc_cyberlogview.cpp
OBJECTS       = .obj/main.o \
		.obj/cyberlogview.o \
		.obj/moc_cyberlogview.o
DIST          = ../../../../Trolltech/Qt-4.3.2/mkspecs/common/g++.conf \
		../../../../Trolltech/Qt-4.3.2/mkspecs/common/unix.conf \
		../../../../Trolltech/Qt-4.3.2/mkspecs/common/linux.conf \
		../../../../Trolltech/Qt-4.3.2/mkspecs/qconfig.pri \
		../../../../Trolltech/Qt-4.3.2/mkspecs/features/qt_functions.prf \
		../../../../Trolltech/Qt-4.3.2/mkspecs/features/qt_config.prf \
		../../../../Trolltech/Qt-4.3.2/mkspecs/features/exclusive_builds.prf \
		../../../../Trolltech/Qt-4.3.2/mkspecs/features/default_pre.prf \
		../../../../Trolltech/Qt-4.3.2/mkspecs/features/release.prf \
		../../../../Trolltech/Qt-4.3.2/mkspecs/features/default_post.prf \
		../../../../Trolltech/Qt-4.3.2/mkspecs/features/qt.prf \
		../../../../Trolltech/Qt-4.3.2/mkspecs/features/unix/thread.prf \
		../../../../Trolltech/Qt-4.3.2/mkspecs/features/moc.prf \
		../../../../Trolltech/Qt-4.3.2/mkspecs/features/uitools.prf \
		../../../../Trolltech/Qt-4.3.2/mkspecs/features/warn_on.prf \
		../../../../Trolltech/Qt-4.3.2/mkspecs/features/resources.prf \
		../../../../Trolltech/Qt-4.3.2/mkspecs/features/uic.prf \
		../../../../Trolltech/Qt-4.3.2/mkspecs/features/yacc.prf \
		../../../../Trolltech/Qt-4.3.2/mkspecs/features/lex.prf \
		cyberlogviewer.pro
QMAKE_TARGET  = CyberLogViewer
DESTDIR       = 
TARGET        = CyberLogViewer

first: all
####### Implicit rules

.SUFFIXES: .o .c .cpp .cc .cxx .C

.cpp.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.cc.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.cxx.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.C.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.c.o:
	$(CC) -c $(CFLAGS) $(INCPATH) -o "$@" "$<"

####### Build rules

all: Makefile $(TARGET)

$(TARGET):  $(OBJECTS)  
	$(LINK) $(LFLAGS) -o $(TARGET) $(OBJECTS) $(OBJCOMP) $(LIBS)

Makefile: cyberlogviewer.pro  ../../../../Trolltech/Qt-4.3.2/mkspecs/linux-g++/qmake.conf ../../../../Trolltech/Qt-4.3.2/mkspecs/common/g++.conf \
		../../../../Trolltech/Qt-4.3.2/mkspecs/common/unix.conf \
		../../../../Trolltech/Qt-4.3.2/mkspecs/common/linux.conf \
		../../../../Trolltech/Qt-4.3.2/mkspecs/qconfig.pri \
		../../../../Trolltech/Qt-4.3.2/mkspecs/features/qt_functions.prf \
		../../../../Trolltech/Qt-4.3.2/mkspecs/features/qt_config.prf \
		../../../../Trolltech/Qt-4.3.2/mkspecs/features/exclusive_builds.prf \
		../../../../Trolltech/Qt-4.3.2/mkspecs/features/default_pre.prf \
		../../../../Trolltech/Qt-4.3.2/mkspecs/features/release.prf \
		../../../../Trolltech/Qt-4.3.2/mkspecs/features/default_post.prf \
		../../../../Trolltech/Qt-4.3.2/mkspecs/features/qt.prf \
		../../../../Trolltech/Qt-4.3.2/mkspecs/features/unix/thread.prf \
		../../../../Trolltech/Qt-4.3.2/mkspecs/features/moc.prf \
		../../../../Trolltech/Qt-4.3.2/mkspecs/features/uitools.prf \
		../../../../Trolltech/Qt-4.3.2/mkspecs/features/warn_on.prf \
		../../../../Trolltech/Qt-4.3.2/mkspecs/features/resources.prf \
		../../../../Trolltech/Qt-4.3.2/mkspecs/features/uic.prf \
		../../../../Trolltech/Qt-4.3.2/mkspecs/features/yacc.prf \
		../../../../Trolltech/Qt-4.3.2/mkspecs/features/lex.prf \
		/usr/local/Trolltech/Qt-4.3.2/lib/libQtGui.prl \
		/usr/local/Trolltech/Qt-4.3.2/lib/libQtCore.prl \
		/usr/local/Trolltech/Qt-4.3.2/lib/libQtUiTools.prl \
		/usr/local/Trolltech/Qt-4.3.2/lib/libQtXml.prl
	$(QMAKE) -unix -o Makefile cyberlogviewer.pro
../../../../Trolltech/Qt-4.3.2/mkspecs/common/g++.conf:
../../../../Trolltech/Qt-4.3.2/mkspecs/common/unix.conf:
../../../../Trolltech/Qt-4.3.2/mkspecs/common/linux.conf:
../../../../Trolltech/Qt-4.3.2/mkspecs/qconfig.pri:
../../../../Trolltech/Qt-4.3.2/mkspecs/features/qt_functions.prf:
../../../../Trolltech/Qt-4.3.2/mkspecs/features/qt_config.prf:
../../../../Trolltech/Qt-4.3.2/mkspecs/features/exclusive_builds.prf:
../../../../Trolltech/Qt-4.3.2/mkspecs/features/default_pre.prf:
../../../../Trolltech/Qt-4.3.2/mkspecs/features/release.prf:
../../../../Trolltech/Qt-4.3.2/mkspecs/features/default_post.prf:
../../../../Trolltech/Qt-4.3.2/mkspecs/features/qt.prf:
../../../../Trolltech/Qt-4.3.2/mkspecs/features/unix/thread.prf:
../../../../Trolltech/Qt-4.3.2/mkspecs/features/moc.prf:
../../../../Trolltech/Qt-4.3.2/mkspecs/features/uitools.prf:
../../../../Trolltech/Qt-4.3.2/mkspecs/features/warn_on.prf:
../../../../Trolltech/Qt-4.3.2/mkspecs/features/resources.prf:
../../../../Trolltech/Qt-4.3.2/mkspecs/features/uic.prf:
../../../../Trolltech/Qt-4.3.2/mkspecs/features/yacc.prf:
../../../../Trolltech/Qt-4.3.2/mkspecs/features/lex.prf:
/usr/local/Trolltech/Qt-4.3.2/lib/libQtGui.prl:
/usr/local/Trolltech/Qt-4.3.2/lib/libQtCore.prl:
/usr/local/Trolltech/Qt-4.3.2/lib/libQtUiTools.prl:
/usr/local/Trolltech/Qt-4.3.2/lib/libQtXml.prl:
qmake:  FORCE
	@$(QMAKE) -unix -o Makefile cyberlogviewer.pro

dist: 
	@$(CHK_DIR_EXISTS) .obj/CyberLogViewer1.0.0 || $(MKDIR) .obj/CyberLogViewer1.0.0 
	$(COPY_FILE) --parents $(SOURCES) $(DIST) .obj/CyberLogViewer1.0.0/ && $(COPY_FILE) --parents ../include/cyberlogview.h .obj/CyberLogViewer1.0.0/ && $(COPY_FILE) --parents ../main.cpp ../cyberlogview.cpp .obj/CyberLogViewer1.0.0/ && (cd `dirname .obj/CyberLogViewer1.0.0` && $(TAR) CyberLogViewer1.0.0.tar CyberLogViewer1.0.0 && $(COMPRESS) CyberLogViewer1.0.0.tar) && $(MOVE) `dirname .obj/CyberLogViewer1.0.0`/CyberLogViewer1.0.0.tar.gz . && $(DEL_FILE) -r .obj/CyberLogViewer1.0.0


clean:compiler_clean 
	-$(DEL_FILE) $(OBJECTS)
	-$(DEL_FILE) *~ core *.core


####### Sub-libraries

distclean: clean
	-$(DEL_FILE) $(TARGET) 
	-$(DEL_FILE) Makefile


mocclean: compiler_moc_header_clean compiler_moc_source_clean

mocables: compiler_moc_header_make_all compiler_moc_source_make_all

compiler_moc_header_make_all: .moc/moc_cyberlogview.cpp
compiler_moc_header_clean:
	-$(DEL_FILE) .moc/moc_cyberlogview.cpp
.moc/moc_cyberlogview.cpp: ../include/cyberlogview.h
	/usr/local/Trolltech/Qt-4.3.2/bin/moc $(DEFINES) $(INCPATH) ../include/cyberlogview.h -o .moc/moc_cyberlogview.cpp

compiler_rcc_make_all:
compiler_rcc_clean:
compiler_image_collection_make_all: qmake_image_collection.cpp
compiler_image_collection_clean:
	-$(DEL_FILE) qmake_image_collection.cpp
compiler_moc_source_make_all:
compiler_moc_source_clean:
compiler_uic_make_all:
compiler_uic_clean:
compiler_yacc_decl_make_all:
compiler_yacc_decl_clean:
compiler_yacc_impl_make_all:
compiler_yacc_impl_clean:
compiler_lex_make_all:
compiler_lex_clean:
compiler_clean: compiler_moc_header_clean 

####### Compile

.obj/main.o: ../main.cpp ../include/cyberlogview.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o .obj/main.o ../main.cpp

.obj/cyberlogview.o: ../cyberlogview.cpp ../include/cyberlog.h \
		../include/cyberlogview.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o .obj/cyberlogview.o ../cyberlogview.cpp

.obj/moc_cyberlogview.o: .moc/moc_cyberlogview.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o .obj/moc_cyberlogview.o .moc/moc_cyberlogview.cpp

####### Install

install_target: first FORCE
	@$(CHK_DIR_EXISTS) $(INSTALL_ROOT)/usr/local/opi/bin/ || $(MKDIR) $(INSTALL_ROOT)/usr/local/opi/bin/ 
	-$(INSTALL_PROGRAM) "$(QMAKE_TARGET)" "$(INSTALL_ROOT)/usr/local/opi/bin/$(QMAKE_TARGET)"
	-strip "$(INSTALL_ROOT)/usr/local/opi/bin/$(QMAKE_TARGET)"

uninstall_target:  FORCE
	-$(DEL_FILE) "$(INSTALL_ROOT)/usr/local/opi/bin/$(QMAKE_TARGET)"
	-$(DEL_DIR) $(INSTALL_ROOT)/usr/local/opi/bin/ 


install_forms: first FORCE
	@$(CHK_DIR_EXISTS) $(INSTALL_ROOT)/usr/local/opi/ui/ || $(MKDIR) $(INSTALL_ROOT)/usr/local/opi/ui/ 
	-$(INSTALL_FILE) /usr/local/opisrc/src/CyberLogViewer/ui/CyberLogViewer.ui $(INSTALL_ROOT)/usr/local/opi/ui/
	-$(INSTALL_FILE) /usr/local/opisrc/src/CyberLogViewer/ui/Logdetail.ui $(INSTALL_ROOT)/usr/local/opi/ui/
	-$(INSTALL_FILE) /usr/local/opisrc/src/CyberLogViewer/ui/Loglist.ui $(INSTALL_ROOT)/usr/local/opi/ui/


uninstall_forms:  FORCE
	-$(DEL_FILE) -r $(INSTALL_ROOT)/usr/local/opi/ui/CyberLogViewer.ui 
	 -$(DEL_FILE) -r $(INSTALL_ROOT)/usr/local/opi/ui/Logdetail.ui 
	 -$(DEL_FILE) -r $(INSTALL_ROOT)/usr/local/opi/ui/Loglist.ui
	-$(DEL_DIR) $(INSTALL_ROOT)/usr/local/opi/ui/ 


install:  install_target install_forms  FORCE

uninstall: uninstall_target uninstall_forms   FORCE

FORCE:

