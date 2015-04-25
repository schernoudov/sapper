#include "mainwindow.h"
#include <QApplication>
#include <engine.h>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	MainWindow w;

	Engine *engine = new Engine();
	w.set_engine(engine);
	w.initialize();
	w.show();

	return a.exec();
}
