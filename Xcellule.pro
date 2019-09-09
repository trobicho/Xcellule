SOURCES+=main.cpp
SOURCES+=Xcellule.cpp
SOURCES+=GLtree.cpp
SOURCES+=WinGL.cpp

HEADERS+=Xcellule.h
HEADERS+=GLtree.h
HEADERS+=WinGL.h

LIBS+= -lglut -lGLU
LIBS+=-L ~/lib -lXcel
QT+=opengl
CONFIG+=qt
CONFIG+=no_lflags_merge
CONFIG+=debug
