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
		const char	*index_to_char(const QModelIndex &index);

    private:
		 QFileSystemModel	m_fs_model;
};
