#include "MainWin.h"
#include "GLtree.h"

MainWin::MainWin(): QMainWindow()
{
	setCentralWidget(&m_tree_win);
}
