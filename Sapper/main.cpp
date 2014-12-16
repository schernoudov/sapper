#include "mainwindow.h"
#include <QApplication>
#include <presenter.h>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	MainWindow w;

	Presenter *presenter = new Presenter();
	w.set_presenter(presenter);
	w.show();

	return a.exec();
}
