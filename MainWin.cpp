#include "MainWin.h"
#include "GLtree.h"

MainWin::MainWin(): QMainWindow()
{
	setCentralWidget(&m_tree_win);
	create_dock_windows();
	QObject::connect(&m_file_panel, &QAbstractItemView::activated
		, this, &MainWin::slot_activated);
}

void MainWin::create_dock_windows()
{
	QDockWidget *dock = new QDockWidget(tr("Customers"), this);
	dock->setAllowedAreas(Qt::LeftDockWidgetArea | Qt::RightDockWidgetArea);
	dock->setWidget(&m_file_panel);
	addDockWidget(Qt::LeftDockWidgetArea, dock);
	//viewMenu->addAction(dock->toggleViewAction());
}

void MainWin::slot_activated(const QModelIndex &index)
{
	m_tree_win.reset();
	m_tree_win.loadRLE_file(m_file_panel.index_to_char(index));
	std::cout << "test" << std::endl;
}
