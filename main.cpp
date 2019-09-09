#include "Xcellule.h"

int main(int ac, char **av)
{
	QApplication app(ac, av);
	GLtree treeWin;
	//Celtree tree;

	treeWin.show();
    
	return app.exec();
}
