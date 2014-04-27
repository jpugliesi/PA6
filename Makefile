#############################################################################
# Makefile for building: simponopoly.app/Contents/MacOS/simponopoly
# Generated by qmake (2.01a) (Qt 4.8.6) on: Sun Apr 27 14:53:32 2014
# Project:  simponopoly.pro
# Template: app
# Command: /usr/local/bin/qmake -o Makefile simponopoly.pro
#############################################################################

####### Compiler, tools and options

CC            = clang
CXX           = clang++
DEFINES       = -DQT_NO_DEBUG -DQT_GUI_LIB -DQT_CORE_LIB -DQT_SHARED
CFLAGS        = -pipe -mmacosx-version-min=10.7 -O2 -arch x86_64 -Wall -W $(DEFINES)
CXXFLAGS      = -pipe -stdlib=libc++ -mmacosx-version-min=10.7 -O2 -arch x86_64 -Wall -W $(DEFINES)
INCPATH       = -I/usr/local/Cellar/qt/4.8.5/mkspecs/unsupported/macx-clang-libc++ -I. -I/usr/local/Cellar/qt/4.8.5/lib/QtCore.framework/Versions/4/Headers -I/usr/local/Cellar/qt/4.8.5/lib/QtCore.framework/Versions/4/Headers -I/usr/local/Cellar/qt/4.8.5/lib/QtGui.framework/Versions/4/Headers -I/usr/local/Cellar/qt/4.8.5/lib/QtGui.framework/Versions/4/Headers -I/usr/local/Cellar/qt/4.8.5/include -I. -I. -F/usr/local/Cellar/qt/4.8.5/lib
LINK          = clang++
LFLAGS        = -headerpad_max_install_names -stdlib=libc++ -mmacosx-version-min=10.7 -arch x86_64
LIBS          = $(SUBLIBS) -F/usr/local/Cellar/qt/4.8.5/lib -L/usr/local/Cellar/qt/4.8.5/lib -framework QtGui -L/opt/X11/lib -L/usr/local/Cellar/qt/4.8.5/lib -F/usr/local/Cellar/qt/4.8.5/lib -framework QtCore 
AR            = ar cq
RANLIB        = ranlib -s
QMAKE         = /usr/local/bin/qmake
TAR           = tar -cf
COMPRESS      = gzip -9f
COPY          = cp -f
SED           = sed
COPY_FILE     = cp -f
COPY_DIR      = cp -f -R
STRIP         = 
INSTALL_FILE  = $(COPY_FILE)
INSTALL_DIR   = $(COPY_DIR)
INSTALL_PROGRAM = $(COPY_FILE)
DEL_FILE      = rm -f
SYMLINK       = ln -f -s
DEL_DIR       = rmdir
MOVE          = mv -f
CHK_DIR_EXISTS= test -d
MKDIR         = mkdir -p
export MACOSX_DEPLOYMENT_TARGET = 10.7

####### Output directory

OBJECTS_DIR   = ./

####### Files

SOURCES       = Action.cpp \
		Bank.cpp \
		Card.cpp \
		CardAction.cpp \
		CentralWidget.cpp \
		ConsoleWidget.cpp \
		Deck.cpp \
		Die.cpp \
		Game_Board.cpp \
		GoToAction.cpp \
		GUIChestSpace.cpp \
		GUIDockPlayer.cpp \
		GUIPlayer.cpp \
		GUIPropertySpace.cpp \
		GUISpace.cpp \
		IconDialog.cpp \
		main.cpp \
		MainWindow.cpp \
		MoneyAction.cpp \
		MoveAction.cpp \
		Player.cpp \
		PlayerDock.cpp \
		PropertyAction.cpp \
		Space.cpp moc_CentralWidget.cpp \
		moc_ConsoleWidget.cpp \
		moc_GUIPlayer.cpp \
		moc_GUIPropertySpace.cpp \
		moc_GUISpace.cpp \
		moc_IconDialog.cpp \
		moc_MainWindow.cpp \
		qrc_application.cpp
OBJECTS       = Action.o \
		Bank.o \
		Card.o \
		CardAction.o \
		CentralWidget.o \
		ConsoleWidget.o \
		Deck.o \
		Die.o \
		Game_Board.o \
		GoToAction.o \
		GUIChestSpace.o \
		GUIDockPlayer.o \
		GUIPlayer.o \
		GUIPropertySpace.o \
		GUISpace.o \
		IconDialog.o \
		main.o \
		MainWindow.o \
		MoneyAction.o \
		MoveAction.o \
		Player.o \
		PlayerDock.o \
		PropertyAction.o \
		Space.o \
		moc_CentralWidget.o \
		moc_ConsoleWidget.o \
		moc_GUIPlayer.o \
		moc_GUIPropertySpace.o \
		moc_GUISpace.o \
		moc_IconDialog.o \
		moc_MainWindow.o \
		qrc_application.o
DIST          = /usr/local/Cellar/qt/4.8.5/mkspecs/common/unix.conf \
		/usr/local/Cellar/qt/4.8.5/mkspecs/common/mac.conf \
		/usr/local/Cellar/qt/4.8.5/mkspecs/common/gcc-base.conf \
		/usr/local/Cellar/qt/4.8.5/mkspecs/common/gcc-base-macx.conf \
		/usr/local/Cellar/qt/4.8.5/mkspecs/common/clang.conf \
		/usr/local/Cellar/qt/4.8.5/mkspecs/qconfig.pri \
		/usr/local/Cellar/qt/4.8.5/mkspecs/modules/qt_webkit_version.pri \
		/usr/local/Cellar/qt/4.8.5/mkspecs/features/qt_functions.prf \
		/usr/local/Cellar/qt/4.8.5/mkspecs/features/qt_config.prf \
		/usr/local/Cellar/qt/4.8.5/mkspecs/features/exclusive_builds.prf \
		/usr/local/Cellar/qt/4.8.5/mkspecs/features/default_pre.prf \
		/usr/local/Cellar/qt/4.8.5/mkspecs/features/mac/default_pre.prf \
		/usr/local/Cellar/qt/4.8.5/mkspecs/features/release.prf \
		/usr/local/Cellar/qt/4.8.5/mkspecs/features/default_post.prf \
		/usr/local/Cellar/qt/4.8.5/mkspecs/features/mac/default_post.prf \
		/usr/local/Cellar/qt/4.8.5/mkspecs/features/mac/x86_64.prf \
		/usr/local/Cellar/qt/4.8.5/mkspecs/features/mac/objective_c.prf \
		/usr/local/Cellar/qt/4.8.5/mkspecs/features/shared.prf \
		/usr/local/Cellar/qt/4.8.5/mkspecs/features/warn_on.prf \
		/usr/local/Cellar/qt/4.8.5/mkspecs/features/qt.prf \
		/usr/local/Cellar/qt/4.8.5/mkspecs/features/unix/thread.prf \
		/usr/local/Cellar/qt/4.8.5/mkspecs/features/moc.prf \
		/usr/local/Cellar/qt/4.8.5/mkspecs/features/mac/rez.prf \
		/usr/local/Cellar/qt/4.8.5/mkspecs/features/mac/sdk.prf \
		/usr/local/Cellar/qt/4.8.5/mkspecs/features/resources.prf \
		/usr/local/Cellar/qt/4.8.5/mkspecs/features/uic.prf \
		/usr/local/Cellar/qt/4.8.5/mkspecs/features/yacc.prf \
		/usr/local/Cellar/qt/4.8.5/mkspecs/features/lex.prf \
		/usr/local/Cellar/qt/4.8.5/mkspecs/features/include_source_dir.prf \
		simponopoly.pro
QMAKE_TARGET  = simponopoly
DESTDIR       = 
TARGET        = simponopoly.app/Contents/MacOS/simponopoly

####### Custom Compiler Variables
QMAKE_COMP_QMAKE_OBJECTIVE_CFLAGS = -pipe \
		-O2 \
		-arch \
		x86_64 \
		-Wall \
		-W


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

all: Makefile simponopoly.app/Contents/PkgInfo simponopoly.app/Contents/Resources/empty.lproj simponopoly.app/Contents/Info.plist $(TARGET)

$(TARGET):  $(OBJECTS)  
	@$(CHK_DIR_EXISTS) simponopoly.app/Contents/MacOS/ || $(MKDIR) simponopoly.app/Contents/MacOS/ 
	$(LINK) $(LFLAGS) -o $(TARGET) $(OBJECTS) $(OBJCOMP) $(LIBS)

Makefile: simponopoly.pro  /usr/local/Cellar/qt/4.8.5/mkspecs/unsupported/macx-clang-libc++/qmake.conf /usr/local/Cellar/qt/4.8.5/mkspecs/common/unix.conf \
		/usr/local/Cellar/qt/4.8.5/mkspecs/common/mac.conf \
		/usr/local/Cellar/qt/4.8.5/mkspecs/common/gcc-base.conf \
		/usr/local/Cellar/qt/4.8.5/mkspecs/common/gcc-base-macx.conf \
		/usr/local/Cellar/qt/4.8.5/mkspecs/common/clang.conf \
		/usr/local/Cellar/qt/4.8.5/mkspecs/qconfig.pri \
		/usr/local/Cellar/qt/4.8.5/mkspecs/modules/qt_webkit_version.pri \
		/usr/local/Cellar/qt/4.8.5/mkspecs/features/qt_functions.prf \
		/usr/local/Cellar/qt/4.8.5/mkspecs/features/qt_config.prf \
		/usr/local/Cellar/qt/4.8.5/mkspecs/features/exclusive_builds.prf \
		/usr/local/Cellar/qt/4.8.5/mkspecs/features/default_pre.prf \
		/usr/local/Cellar/qt/4.8.5/mkspecs/features/mac/default_pre.prf \
		/usr/local/Cellar/qt/4.8.5/mkspecs/features/release.prf \
		/usr/local/Cellar/qt/4.8.5/mkspecs/features/default_post.prf \
		/usr/local/Cellar/qt/4.8.5/mkspecs/features/mac/default_post.prf \
		/usr/local/Cellar/qt/4.8.5/mkspecs/features/mac/x86_64.prf \
		/usr/local/Cellar/qt/4.8.5/mkspecs/features/mac/objective_c.prf \
		/usr/local/Cellar/qt/4.8.5/mkspecs/features/shared.prf \
		/usr/local/Cellar/qt/4.8.5/mkspecs/features/warn_on.prf \
		/usr/local/Cellar/qt/4.8.5/mkspecs/features/qt.prf \
		/usr/local/Cellar/qt/4.8.5/mkspecs/features/unix/thread.prf \
		/usr/local/Cellar/qt/4.8.5/mkspecs/features/moc.prf \
		/usr/local/Cellar/qt/4.8.5/mkspecs/features/mac/rez.prf \
		/usr/local/Cellar/qt/4.8.5/mkspecs/features/mac/sdk.prf \
		/usr/local/Cellar/qt/4.8.5/mkspecs/features/resources.prf \
		/usr/local/Cellar/qt/4.8.5/mkspecs/features/uic.prf \
		/usr/local/Cellar/qt/4.8.5/mkspecs/features/yacc.prf \
		/usr/local/Cellar/qt/4.8.5/mkspecs/features/lex.prf \
		/usr/local/Cellar/qt/4.8.5/mkspecs/features/include_source_dir.prf \
		/usr/local/Cellar/qt/4.8.5/lib/QtGui.framework/QtGui.prl \
		/usr/local/Cellar/qt/4.8.5/lib/QtCore.framework/QtCore.prl
	$(QMAKE) -o Makefile simponopoly.pro
/usr/local/Cellar/qt/4.8.5/mkspecs/common/unix.conf:
/usr/local/Cellar/qt/4.8.5/mkspecs/common/mac.conf:
/usr/local/Cellar/qt/4.8.5/mkspecs/common/gcc-base.conf:
/usr/local/Cellar/qt/4.8.5/mkspecs/common/gcc-base-macx.conf:
/usr/local/Cellar/qt/4.8.5/mkspecs/common/clang.conf:
/usr/local/Cellar/qt/4.8.5/mkspecs/qconfig.pri:
/usr/local/Cellar/qt/4.8.5/mkspecs/modules/qt_webkit_version.pri:
/usr/local/Cellar/qt/4.8.5/mkspecs/features/qt_functions.prf:
/usr/local/Cellar/qt/4.8.5/mkspecs/features/qt_config.prf:
/usr/local/Cellar/qt/4.8.5/mkspecs/features/exclusive_builds.prf:
/usr/local/Cellar/qt/4.8.5/mkspecs/features/default_pre.prf:
/usr/local/Cellar/qt/4.8.5/mkspecs/features/mac/default_pre.prf:
/usr/local/Cellar/qt/4.8.5/mkspecs/features/release.prf:
/usr/local/Cellar/qt/4.8.5/mkspecs/features/default_post.prf:
/usr/local/Cellar/qt/4.8.5/mkspecs/features/mac/default_post.prf:
/usr/local/Cellar/qt/4.8.5/mkspecs/features/mac/x86_64.prf:
/usr/local/Cellar/qt/4.8.5/mkspecs/features/mac/objective_c.prf:
/usr/local/Cellar/qt/4.8.5/mkspecs/features/shared.prf:
/usr/local/Cellar/qt/4.8.5/mkspecs/features/warn_on.prf:
/usr/local/Cellar/qt/4.8.5/mkspecs/features/qt.prf:
/usr/local/Cellar/qt/4.8.5/mkspecs/features/unix/thread.prf:
/usr/local/Cellar/qt/4.8.5/mkspecs/features/moc.prf:
/usr/local/Cellar/qt/4.8.5/mkspecs/features/mac/rez.prf:
/usr/local/Cellar/qt/4.8.5/mkspecs/features/mac/sdk.prf:
/usr/local/Cellar/qt/4.8.5/mkspecs/features/resources.prf:
/usr/local/Cellar/qt/4.8.5/mkspecs/features/uic.prf:
/usr/local/Cellar/qt/4.8.5/mkspecs/features/yacc.prf:
/usr/local/Cellar/qt/4.8.5/mkspecs/features/lex.prf:
/usr/local/Cellar/qt/4.8.5/mkspecs/features/include_source_dir.prf:
/usr/local/Cellar/qt/4.8.5/lib/QtGui.framework/QtGui.prl:
/usr/local/Cellar/qt/4.8.5/lib/QtCore.framework/QtCore.prl:
qmake:  FORCE
	@$(QMAKE) -o Makefile simponopoly.pro

simponopoly.app/Contents/PkgInfo: 
	@$(CHK_DIR_EXISTS) simponopoly.app/Contents || $(MKDIR) simponopoly.app/Contents 
	@$(DEL_FILE) simponopoly.app/Contents/PkgInfo
	@echo "APPL????" >simponopoly.app/Contents/PkgInfo
simponopoly.app/Contents/Resources/empty.lproj: 
	@$(CHK_DIR_EXISTS) simponopoly.app/Contents/Resources || $(MKDIR) simponopoly.app/Contents/Resources 
	@touch simponopoly.app/Contents/Resources/empty.lproj
	
simponopoly.app/Contents/Info.plist: 
	@$(CHK_DIR_EXISTS) simponopoly.app/Contents || $(MKDIR) simponopoly.app/Contents 
	@$(DEL_FILE) simponopoly.app/Contents/Info.plist
	@sed -e "s,@SHORT_VERSION@,1.0,g" -e "s,@TYPEINFO@,????,g" -e "s,@ICON@,,g" -e "s,@EXECUTABLE@,simponopoly,g" -e "s,@TYPEINFO@,????,g" /usr/local/Cellar/qt/4.8.5/mkspecs/unsupported/macx-clang-libc++/Info.plist.app >simponopoly.app/Contents/Info.plist
dist: 
	@$(CHK_DIR_EXISTS) .tmp/simponopoly1.0.0 || $(MKDIR) .tmp/simponopoly1.0.0 
	$(COPY_FILE) --parents $(SOURCES) $(DIST) .tmp/simponopoly1.0.0/ && $(COPY_FILE) --parents Action.h Bank.h Card.h CardAction.h CentralWidget.h ConsoleWidget.h Deck.h Die.h Game_Board.h GoToAction.h GUIChestSpace.h GUIDockPlayer.h GUIPlayer.h GUIPropertySpace.h GUISpace.h IconDialog.h MainWindow.h MoneyAction.h MoveAction.h Player.h PlayerDock.h PropertyAction.h Space.h .tmp/simponopoly1.0.0/ && $(COPY_FILE) --parents application.qrc .tmp/simponopoly1.0.0/ && $(COPY_FILE) --parents Action.cpp Bank.cpp Card.cpp CardAction.cpp CentralWidget.cpp ConsoleWidget.cpp Deck.cpp Die.cpp Game_Board.cpp GoToAction.cpp GUIChestSpace.cpp GUIDockPlayer.cpp GUIPlayer.cpp GUIPropertySpace.cpp GUISpace.cpp IconDialog.cpp main.cpp MainWindow.cpp MoneyAction.cpp MoveAction.cpp Player.cpp PlayerDock.cpp PropertyAction.cpp Space.cpp .tmp/simponopoly1.0.0/ && (cd `dirname .tmp/simponopoly1.0.0` && $(TAR) simponopoly1.0.0.tar simponopoly1.0.0 && $(COMPRESS) simponopoly1.0.0.tar) && $(MOVE) `dirname .tmp/simponopoly1.0.0`/simponopoly1.0.0.tar.gz . && $(DEL_FILE) -r .tmp/simponopoly1.0.0


clean:compiler_clean 
	-$(DEL_FILE) $(OBJECTS)
	-$(DEL_FILE) *~ core *.core


####### Sub-libraries

distclean: clean
	-$(DEL_FILE) -r simponopoly.app
	-$(DEL_FILE) Makefile


check: first

mocclean: compiler_moc_header_clean compiler_moc_source_clean

mocables: compiler_moc_header_make_all compiler_moc_source_make_all

compiler_objective_c_make_all:
compiler_objective_c_clean:
compiler_moc_header_make_all: moc_CentralWidget.cpp moc_ConsoleWidget.cpp moc_GUIPlayer.cpp moc_GUIPropertySpace.cpp moc_GUISpace.cpp moc_IconDialog.cpp moc_MainWindow.cpp
compiler_moc_header_clean:
	-$(DEL_FILE) moc_CentralWidget.cpp moc_ConsoleWidget.cpp moc_GUIPlayer.cpp moc_GUIPropertySpace.cpp moc_GUISpace.cpp moc_IconDialog.cpp moc_MainWindow.cpp
moc_CentralWidget.cpp: GUISpace.h \
		Space.h \
		Action.h \
		Player.h \
		GUIPlayer.h \
		Deck.h \
		ConsoleWidget.h \
		Die.h \
		CentralWidget.h \
		Bank.h \
		CentralWidget.h
	/usr/local/Cellar/qt/4.8.5/bin/moc $(DEFINES) $(INCPATH) -D__APPLE__ -D__GNUC__ CentralWidget.h -o moc_CentralWidget.cpp

moc_ConsoleWidget.cpp: Die.h \
		GUIPlayer.h \
		Player.h \
		Space.h \
		Action.h \
		GUISpace.h \
		CentralWidget.h \
		Deck.h \
		ConsoleWidget.h \
		Bank.h \
		ConsoleWidget.h
	/usr/local/Cellar/qt/4.8.5/bin/moc $(DEFINES) $(INCPATH) -D__APPLE__ -D__GNUC__ ConsoleWidget.h -o moc_ConsoleWidget.cpp

moc_GUIPlayer.cpp: Player.h \
		Space.h \
		Action.h \
		GUISpace.h \
		GUIPlayer.h \
		GUIPlayer.h
	/usr/local/Cellar/qt/4.8.5/bin/moc $(DEFINES) $(INCPATH) -D__APPLE__ -D__GNUC__ GUIPlayer.h -o moc_GUIPlayer.cpp

moc_GUIPropertySpace.cpp: GUISpace.h \
		Space.h \
		Action.h \
		Player.h \
		GUIPlayer.h \
		GUIPropertySpace.h
	/usr/local/Cellar/qt/4.8.5/bin/moc $(DEFINES) $(INCPATH) -D__APPLE__ -D__GNUC__ GUIPropertySpace.h -o moc_GUIPropertySpace.cpp

moc_GUISpace.cpp: Space.h \
		Action.h \
		Player.h \
		GUIPlayer.h \
		GUISpace.h \
		GUISpace.h
	/usr/local/Cellar/qt/4.8.5/bin/moc $(DEFINES) $(INCPATH) -D__APPLE__ -D__GNUC__ GUISpace.h -o moc_GUISpace.cpp

moc_IconDialog.cpp: IconDialog.h
	/usr/local/Cellar/qt/4.8.5/bin/moc $(DEFINES) $(INCPATH) -D__APPLE__ -D__GNUC__ IconDialog.h -o moc_IconDialog.cpp

moc_MainWindow.cpp: CentralWidget.h \
		GUISpace.h \
		Space.h \
		Action.h \
		Player.h \
		GUIPlayer.h \
		Deck.h \
		ConsoleWidget.h \
		Die.h \
		Bank.h \
		PlayerDock.h \
		GUIDockPlayer.h \
		MainWindow.h
	/usr/local/Cellar/qt/4.8.5/bin/moc $(DEFINES) $(INCPATH) -D__APPLE__ -D__GNUC__ MainWindow.h -o moc_MainWindow.cpp

compiler_rcc_make_all: qrc_application.cpp
compiler_rcc_clean:
	-$(DEL_FILE) qrc_application.cpp
qrc_application.cpp: application.qrc \
		images/coliseum1.png \
		images/flag20.png \
		images/clip5.png \
		images/message3.png \
		images/airplane9.png \
		images/die1.png \
		images/closed18.png \
		images/shopping29.png \
		images/user56.png \
		images/die2.png \
		images/detailed.png \
		images/die3.png \
		images/die4.png \
		images/die5.png \
		images/die6.png \
		images/cup18.png
	/usr/local/Cellar/qt/4.8.5/bin/rcc -name application application.qrc -o qrc_application.cpp

compiler_image_collection_make_all: qmake_image_collection.cpp
compiler_image_collection_clean:
	-$(DEL_FILE) qmake_image_collection.cpp
compiler_moc_source_make_all:
compiler_moc_source_clean:
compiler_rez_source_make_all:
compiler_rez_source_clean:
compiler_uic_make_all:
compiler_uic_clean:
compiler_yacc_decl_make_all:
compiler_yacc_decl_clean:
compiler_yacc_impl_make_all:
compiler_yacc_impl_clean:
compiler_lex_make_all:
compiler_lex_clean:
compiler_clean: compiler_moc_header_clean compiler_rcc_clean 

####### Compile

Action.o: Action.cpp Action.h \
		Player.h \
		Space.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o Action.o Action.cpp

Bank.o: Bank.cpp Bank.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o Bank.o Bank.cpp

Card.o: Card.cpp Card.h \
		Action.h \
		Player.h \
		Space.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o Card.o Card.cpp

CardAction.o: CardAction.cpp CardAction.h \
		Action.h \
		Player.h \
		Space.h \
		Deck.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o CardAction.o CardAction.cpp

CentralWidget.o: CentralWidget.cpp CentralWidget.h \
		GUISpace.h \
		Space.h \
		Action.h \
		Player.h \
		GUIPlayer.h \
		Deck.h \
		ConsoleWidget.h \
		Die.h \
		Bank.h \
		GUIPropertySpace.h \
		GUIChestSpace.h \
		CardAction.h \
		MoneyAction.h \
		IconDialog.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o CentralWidget.o CentralWidget.cpp

ConsoleWidget.o: ConsoleWidget.cpp ConsoleWidget.h \
		Die.h \
		GUIPlayer.h \
		Player.h \
		Space.h \
		Action.h \
		GUISpace.h \
		CentralWidget.h \
		Deck.h \
		Bank.h \
		PropertyAction.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o ConsoleWidget.o ConsoleWidget.cpp

Deck.o: Deck.cpp Deck.h \
		Action.h \
		Player.h \
		Space.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o Deck.o Deck.cpp

Die.o: Die.cpp Die.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o Die.o Die.cpp

Game_Board.o: Game_Board.cpp Game_Board.h \
		Space.h \
		Action.h \
		Player.h \
		Deck.h \
		Bank.h \
		CardAction.h \
		MoneyAction.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o Game_Board.o Game_Board.cpp

GoToAction.o: GoToAction.cpp GoToAction.h \
		Action.h \
		Player.h \
		Space.h \
		Game_Board.h \
		Deck.h \
		Bank.h \
		MoneyAction.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o GoToAction.o GoToAction.cpp

GUIChestSpace.o: GUIChestSpace.cpp GUIChestSpace.h \
		Deck.h \
		Action.h \
		Player.h \
		Space.h \
		GUISpace.h \
		GUIPlayer.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o GUIChestSpace.o GUIChestSpace.cpp

GUIDockPlayer.o: GUIDockPlayer.cpp GUIDockPlayer.h \
		GUIPlayer.h \
		Player.h \
		Space.h \
		Action.h \
		GUISpace.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o GUIDockPlayer.o GUIDockPlayer.cpp

GUIPlayer.o: GUIPlayer.cpp GUIPlayer.h \
		Player.h \
		Space.h \
		Action.h \
		GUISpace.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o GUIPlayer.o GUIPlayer.cpp

GUIPropertySpace.o: GUIPropertySpace.cpp GUIPropertySpace.h \
		GUISpace.h \
		Space.h \
		Action.h \
		Player.h \
		GUIPlayer.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o GUIPropertySpace.o GUIPropertySpace.cpp

GUISpace.o: GUISpace.cpp GUISpace.h \
		Space.h \
		Action.h \
		Player.h \
		GUIPlayer.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o GUISpace.o GUISpace.cpp

IconDialog.o: IconDialog.cpp IconDialog.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o IconDialog.o IconDialog.cpp

main.o: main.cpp MainWindow.h \
		CentralWidget.h \
		GUISpace.h \
		Space.h \
		Action.h \
		Player.h \
		GUIPlayer.h \
		Deck.h \
		ConsoleWidget.h \
		Die.h \
		Bank.h \
		PlayerDock.h \
		GUIDockPlayer.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o main.o main.cpp

MainWindow.o: MainWindow.cpp MainWindow.h \
		CentralWidget.h \
		GUISpace.h \
		Space.h \
		Action.h \
		Player.h \
		GUIPlayer.h \
		Deck.h \
		ConsoleWidget.h \
		Die.h \
		Bank.h \
		PlayerDock.h \
		GUIDockPlayer.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o MainWindow.o MainWindow.cpp

MoneyAction.o: MoneyAction.cpp MoneyAction.h \
		Action.h \
		Player.h \
		Space.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o MoneyAction.o MoneyAction.cpp

MoveAction.o: MoveAction.cpp MoveAction.h \
		Action.h \
		Player.h \
		Space.h \
		Game_Board.h \
		Deck.h \
		Bank.h \
		MoneyAction.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o MoveAction.o MoveAction.cpp

Player.o: Player.cpp Player.h \
		Space.h \
		Action.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o Player.o Player.cpp

PlayerDock.o: PlayerDock.cpp PlayerDock.h \
		GUIPlayer.h \
		Player.h \
		Space.h \
		Action.h \
		GUISpace.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o PlayerDock.o PlayerDock.cpp

PropertyAction.o: PropertyAction.cpp PropertyAction.h \
		Player.h \
		Space.h \
		Action.h \
		Bank.h \
		MoneyAction.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o PropertyAction.o PropertyAction.cpp

Space.o: Space.cpp Space.h \
		Action.h \
		Player.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o Space.o Space.cpp

moc_CentralWidget.o: moc_CentralWidget.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_CentralWidget.o moc_CentralWidget.cpp

moc_ConsoleWidget.o: moc_ConsoleWidget.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_ConsoleWidget.o moc_ConsoleWidget.cpp

moc_GUIPlayer.o: moc_GUIPlayer.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_GUIPlayer.o moc_GUIPlayer.cpp

moc_GUIPropertySpace.o: moc_GUIPropertySpace.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_GUIPropertySpace.o moc_GUIPropertySpace.cpp

moc_GUISpace.o: moc_GUISpace.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_GUISpace.o moc_GUISpace.cpp

moc_IconDialog.o: moc_IconDialog.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_IconDialog.o moc_IconDialog.cpp

moc_MainWindow.o: moc_MainWindow.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_MainWindow.o moc_MainWindow.cpp

qrc_application.o: qrc_application.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o qrc_application.o qrc_application.cpp

####### Install

install:   FORCE

uninstall:   FORCE

FORCE:

