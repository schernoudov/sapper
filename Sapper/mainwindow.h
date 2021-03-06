#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <engine.h>
#include <squarecontrol.h>

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

        void onSquareButtonLeftClicked();

        void onSquareButtonRightClicked();

        void onSquareButtonMutuallyClicked();

	private:

		Ui::MainWindow *ui;

        Engine *engine;

        SquareControl *createSquareButton(QRect *defaultGeometry);

        void drawMinefield();

        void openMinefield();
};

#endif // MAINWINDOW_H
