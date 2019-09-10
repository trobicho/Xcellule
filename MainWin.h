#pragma once
#include <QApplication>
#include <QWidget>
#include <QMainWindow>
#include <QCoreApplication>
#include "GLtree.h"
//#include <QPushButton>

class MainWin: public QMainWindow
{
	Q_OBJECT
    public:
        MainWin();
        ~MainWin(){};

    private:
		GLtree		m_tree_win;
		File_panel	m_file_panel;
};
