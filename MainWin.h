#pragma once
#include <QApplication>
#include <QWidget>
#include <QMainWindow>
#include <QCoreApplication>
#include "File_panel.h"
#include "GLtree.h"
//#include <QPushButton>

class MainWin: public QMainWindow
{
	Q_OBJECT
    public:
        MainWin();
        ~MainWin(){};
		void create_dock_windows();

	public slots:
		void slot_activated(const QModelIndex &index);

    private:
		GLtree		m_tree_win;
		File_panel	m_file_panel;
};
