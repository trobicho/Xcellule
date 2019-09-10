#pragma once
#include <QApplication>
#include <QWidget>
#include <QCoreApplication>
#include "GLtree.h"
//#include <QPushButton>

class File_panel: public QTreeView
{
	Q_OBJECT
    public:
        File_panel();
        ~File_panel(){};

	private slots:
		void activated(const QModelIndex & index);
    private:
		 QFileSystemModel	m_fs_model;
};
