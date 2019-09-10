SOURCES+=main.cpp
SOURCES+=MainWin.cpp
SOURCES+=Xcellule.cpp
SOURCES+=GLtree.cpp
SOURCES+=File_panel.cpp
SOURCES+=WinGL.cpp

HEADERS+=Xcellule.h
HEADERS+=MainWin.h
HEADERS+=File_panel.h
HEADERS+=GLtree.h
HEADERS+=WinGL.h

LIBS+=-framework GLUT
LIBS+=-L$(HOME)/lib -lXcel
QT+=core gui opengl widgets
CONFIG+=qt
CONFIG+=no_lflags_merge
CONFIG+=debug
QMAKE_LFLAGS += -stdlib=libc++
QMAKE_CXXFLAGS += -stdlib=libc++ -std=c++11
CXXFLAGS+=-std=c++11
