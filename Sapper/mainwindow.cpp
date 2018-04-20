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

void MainWindow::onActionNewGameTriggered()
{

}

void MainWindow::setEngine(Engine *engine)
{
	this->engine = engine;
}

void MainWindow::initialize()
{
	engine->initialize();
}
