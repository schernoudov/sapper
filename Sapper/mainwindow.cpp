#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "iostream"

MainWindow::MainWindow(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::MainWindow)
{
	ui->setupUi(this);
}

MainWindow::~MainWindow()
{
	delete ui;
}

void MainWindow::on_actionNew_Game_triggered()
{
	presenter->create_new_game();
}

void MainWindow::set_presenter(Presenter *presenter)
{
	this->presenter = presenter;
}
