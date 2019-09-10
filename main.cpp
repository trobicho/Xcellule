#include "Xcellule.h"

int main(int ac, char **av)
{
	QApplication app(ac, av);

	MainWin		main_win;
    main_win.show();
	return app.exec();
}
