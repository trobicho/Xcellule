#include "GLtree.h"
#include <iostream>

GLtree::GLtree(): WinGL(60, nullptr, "Xcellule")
{
	setFocusPolicy(Qt::ClickFocus);
	m_view.min = (t_pos2D_d){-20, -20};
	m_view.max = (t_pos2D_d){20, 20};

	m_ctree = new Celtree(nullptr, (t_pos2D){0, 0},
			(t_pos2D){(int)0x80000000, (int)0x80000000}, 
			(t_pos2D){(int)0x7FFFFFFF, (int)0x7FFFFFFF});
	m_ctree->set_maxObject(9);
	m_ctree->set_rules(&m_rules_gol);
	/*
	m_ctree->obj_add((t_cel){0, 0, 1});
	m_ctree->obj_add((t_cel){0, 1, 1});
	m_ctree->obj_add((t_cel){0, 2, 1});
	m_ctree->obj_add((t_cel){1, 2, 1});
	m_ctree->obj_add((t_cel){2, 1, 1});
	
	m_ctree->obj_add((t_cel){-5, 0, 1});
	m_ctree->obj_add((t_cel){-5, 1, 1});
	m_ctree->obj_add((t_cel){-5, 2, 1});
	m_ctree->obj_add((t_cel){-6, 2, 1});
	m_ctree->obj_add((t_cel){-7, 1, 1});
	*/
}

void GLtree::loadRLE_file(const std::string &file_path)
{
	LoaderRLE loader;
	loader.load(m_ctree, file_path);
}

void GLtree::reset()
{
	delete m_ctree;
	m_ctree = new Celtree(nullptr, (t_pos2D){0, 0},
			(t_pos2D){(int)0x80000000, (int)0x80000000}, 
			(t_pos2D){(int)0x7FFFFFFF, (int)0x7FFFFFFF});
	m_ctree->set_maxObject(9);
	m_ctree->set_rules(&m_rules_gol);
}

void GLtree::nextGen()
{
	Celtree *ctreeNG = m_ctree->calc_nextGen();
	delete m_ctree;
	m_ctree = ctreeNG;
}

void GLtree::timeOutSlot()
{
	if(m_bGen)
		nextGen();
	updateGL();
}

void GLtree::paintGL()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	glOrtho(m_view.min.x, m_view.max.x, m_view.min.y, m_view.max.y, -1, 100);
	if(celSize() > 5)
		paintGrid();
	paintTree(m_ctree);
}

void GLtree::paintGrid()
{
	glColor3ub(0x8A, 0x8A, 0x8A);
	glBegin(GL_LINES);
	for(int i = m_view.min.x; i < m_view.max.x; i++)
	{
		glVertex2d(i, m_view.min.y);
		glVertex2d(i, m_view.max.y);
	}
	for(int i = m_view.min.y; i < m_view.max.y; i++)
	{
		glVertex2d(m_view.min.x, i);
		glVertex2d(m_view.max.x, i);
	}
	glEnd();
}

void GLtree::paintTree(Celtree *tree)
{
	Celtree *sons = tree->get_sons();
	t_cel *cel;
	int nbCel;
	t_pos2D min, max;

	if(m_dispTree)
	{
		tree->get_minMax(&min, &max);
		glBegin(GL_LINE_LOOP);
		glColor3ub(0x0, 0xF0, 0x44);
		glVertex2i(min.x, min.y);
		glVertex2i(max.x, min.y);
		glVertex2i(max.x, max.y);
		glVertex2i(min.x, max.y);
		glEnd();
	}
	if(sons)
	{
		for(int i = 0; i < 4; i++)
		{
			paintTree(&sons[i]);
		}
	}
	else
	{
		cel = tree->get_cel(&nbCel);
		if(cel && nbCel)
		{
			for(int i = 0; i < nbCel; i++)
			{
				paintCel(cel[i]);
			}
		}
	}
}

void GLtree::paintCel(t_cel &cel)
{
	glColor3ub(0xE0, 0xD0, 0x00);
	glBegin(GL_QUADS);
	glVertex2i(cel.x, cel.y);
	glVertex2i(cel.x + 1, cel.y);
	glVertex2i(cel.x + 1, cel.y + 1);
	glVertex2i(cel.x, cel.y + 1);
	glEnd();
}

void GLtree::view_zoom(t_pos2D_d center, double zoom)
{
	zoom=1/zoom;
	double	VMinX=(m_view.min.x-center.x)*zoom+center.x, VMaxX=(m_view.max.x-center.x)*zoom+center.x;
	double	VMinY=(m_view.min.y-center.y)*zoom+center.y, VMaxY=(m_view.max.y-center.y)*zoom+center.y;
	double	d;

	if (zoom > 1.0 || (VMaxX-VMinX >= VIEW_MIN_W && VMaxY-VMinY >= VIEW_MIN_H))
	{
		m_view.min.x=VMinX;
		m_view.max.x=VMaxX;
		m_view.min.y=VMinY;
		m_view.max.y=VMaxY;
	}
	/*
	else
	{
		if (VMaxX-VMinX < VIEW_MIN_W)
		{
			d = (1.0 - ((VMaxX - VMinX) / VIEW_MIN_W)) / 2.0;
			m_view.max.x += d;
			m_view.min.x -= d;
		}
		if (VMaxY-VMinY < VIEW_MIN_H)
		{
			d = (1.0 - ((VMaxY - VMinY) / VIEW_MIN_H)) / 2.0;
			m_view.max.y += d;
			m_view.min.y -= d;
		}
	}
	*/
}


void GLtree::keyPressEvent(QKeyEvent *keyEvent)
{
	switch(keyEvent->key())
	{
		case Qt::Key_Escape:
			close();
			break;

		case Qt::Key_Right:
			view_moveRel(0.05, 0);
			break;
		case Qt::Key_Left:
			view_moveRel(-0.05, 0);
			break;
		case Qt::Key_Up:
			view_moveRel(0, 0.05);
			break;
		case Qt::Key_Down:
			view_moveRel(0, -0.05);
			break;
		case Qt::Key_P:
			nextGen();
			break;
		case Qt::Key_T:
			m_dispTree = !m_dispTree;
			break;
		case Qt::Key_Space:
			m_bGen = !m_bGen;
			break;
		case Qt::Key_Z:
			if(keyEvent->modifiers() & Qt::ShiftModifier)
				view_zoom(m_view.center(), 0.933);
			else
				view_zoom(m_view.center(), 1.1);
			break;
	}
}

void GLtree::mousePressEvent(QMouseEvent *event)
{
	if (event->button() == Qt::left_button)
		get_cel_pos(pos);
}

void GLtree::resizeGL(int width, int height)
{
	if(height == 0)
		height = 1;
	glViewport(0, 0, width, height);
	QSize size = this->size();
	double x = size.width()/(m_view.max.x - m_view.min.x);
	double y = size.height()/(m_view.max.y - m_view.min.y);
	double center, f;
	if(x > y)
	{
		center = m_view.min.y + (m_view.max.y - m_view.min.y)/2.0;
		f = y/x;
		m_view.min.y = (m_view.min.y - center) * f + center;
		m_view.max.y = (m_view.max.y - center) * f + center;
	}
	else
	{
		center = m_view.min.x + (m_view.max.x - m_view.min.x)/2.0;
		f = x/y;
		m_view.min.x = (m_view.min.x - center) * f + center;
		m_view.max.x = (m_view.max.x - center) * f + center;
	}
}
