#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <engine.h>

namespace Ui {
	class MainWindow;
}

class MainWindow : public QMainWindow
{
		Q_OBJECT

	public:

		explicit MainWindow(QWidget *parent = 0);

		~MainWindow();

        void setEngine(Engine *engine);

		void initialize();

	private slots:

        void onActionNewGameTriggered();

	private:

		Ui::MainWindow *ui;

		Engine *engine;
};

#endif // MAINWINDOW_H
