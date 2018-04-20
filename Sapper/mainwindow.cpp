#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::MainWindow)
{
	ui->setupUi(this);
}

MainWindow::~MainWindow()
{
	delete engine;
	delete ui;
}

void MainWindow::on_actionNew_Game_triggered()
{

}

void MainWindow::set_engine(Engine *engine)
{
	this->engine = engine;
}

void MainWindow::initialize()
{
	engine->initialize();
}
