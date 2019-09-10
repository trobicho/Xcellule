#pragma once
#include <QApplication>
#include <QWidget>
#include <QCoreApplication>
#include "GLtree.h"
//#include <QPushButton>

class File_panel: public QWidget
{
	Q_OBJECT
    public:
        File_panel();
        ~File_panel(){};

    private:
		 QFileSystemModel	m_fs_model;
		 QTreeView			m_tree_view;
};
