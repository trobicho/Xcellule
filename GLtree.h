#pragma once
#include "WinGL.h"
#include "../Xcel/Xcel.h"

#define VIEW_MIN_W 10
#define VIEW_MIN_H 10

typedef struct s_view
{
	t_pos2D_d center(){return (t_pos2D_d)
	{min.x + (max.x - min.x)/2, min.y + (max.y - min.y)/2};}
	t_pos2D_d min, max;
}t_view;

/*-----------------------------------------
(3/9/18)pourquoi un Celtree ? il doit gerer la root differament du reste ?
(5/12/18)Moi pas comprendre la question mais bon moi pas reveiller non plus
(ou alors c'etait un heritier de Celtree).
-----------------------------------------*/
class GLtree: public WinGL
{
	Q_OBJECT
	public:
		GLtree();
		//GLtree(Celtree *parent, t_pos2D min, t_pos2D max): Celtree(parent, min, max), WinGL(30){};
		//GLtree(Celtree *parent, t_pos center, t_pos2D min, t_pos2D max):
			//Celtree(parent, center, min, max)
			//WinGL(30){};
		void paintGL();
		void paintGrid();
		void paintTree(Celtree *tree);
		void paintCel(t_cel &cel);
		void set_debugLevel(int l){m_debug = l;}
		void keyPressEvent(QKeyEvent *keyEvent);
		void mousePressEvent(QMouseEvent *event);
		void resizeGL(int width, int height);
		void loadRLE_file(const std::string &file_path);
		void reset();
		void nextGen();

		double celSize(){
			QSize size = this->size();
			double x = size.width()/(m_view.max.x - m_view.min.x);
			double y = size.height()/(m_view.max.y - m_view.min.y);
			if(y < x)
				return y;
			return x;
		}
		void view_zoom(t_pos2D_d center, double zoom);
		void view_move(double x, double y){
			m_view.min.x += x; m_view.max.x += x;
			m_view.min.y += y; m_view.max.y += y;}
		void view_moveRel(double x, double y){
			x = x * (m_view.max.x - m_view.min.x);
			y = y * (m_view.max.y - m_view.min.y);
			m_view.min.x += x; m_view.max.x += x;
			m_view.min.y += y; m_view.max.y += y;}

	public slots:
		void timeOutSlot();

	private:
		Celtree		*m_ctree;
		t_view		m_view;
		int			m_debug = 0;
		bool		m_dispTree = true, m_bGen = false;
		// a delete
		Rules_gol m_rules_gol;
		//---------
};
