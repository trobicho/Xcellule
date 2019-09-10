#include "MainWin.h"
#include "GLtree.h"

MainWin::MainWin(): QMainWindow()
{
	setCentralWidget(&m_tree_win);
	create_dock_windows();
}

void MainWin::create_dock_windows()
{
	QDockWidget *dock = new QDockWidget(tr("Customers"), this);
	dock->setAllowedAreas(Qt::LeftDockWidgetArea | Qt::RightDockWidgetArea);
	dock->setWidget(&m_file_panel);
	addDockWidget(Qt::LeftDockWidgetArea, dock);
	//viewMenu->addAction(dock->toggleViewAction());
}
