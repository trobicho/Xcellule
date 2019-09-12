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

LIBS+= -lglut -lGLU
LIBS+=-L ~/lib -lXcel
QT+=opengl
CONFIG+=qt
CONFIG+=no_lflags_merge
CONFIG+=debug
