#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <presenter.h>

namespace Ui {
	class MainWindow;
}

class MainWindow : public QMainWindow
{
		Q_OBJECT

	public:

		explicit MainWindow(QWidget *parent = 0);

		~MainWindow();

		void set_presenter(Presenter *presenter);

	private slots:
		void on_actionNew_Game_triggered();

	private:

		Ui::MainWindow *ui;

		Presenter *presenter;
};

#endif // MAINWINDOW_H
