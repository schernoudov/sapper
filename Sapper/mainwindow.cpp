#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "squarecontrol.h"
#include <QPair>

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
    engine->placeMines();
}

void MainWindow::onSquareButtonLeftClicked()
{
    SquareControl* sender = qobject_cast<SquareControl*>(QObject::sender());

    int index = ui->minefieldLayout->indexOf(sender);

    int rs,cs;
    QPair<int, int> position = qMakePair(-1,-1);

    ui->minefieldLayout->getItemPosition(index, &position.first, &position.second, &rs, &cs);

    if (this->engine->openSquare(&position)) {
        this->drawMinefield();
    } else {
        this->openMinefield();
    }
}

void MainWindow::onSquareButtonRightClicked()
{
    printf("right");
}

void MainWindow::onSquareButtonMutuallyClicked()
{
    printf("mutually");
}

void MainWindow::drawMinefield()
{

}

void MainWindow::openMinefield()
{

}

void MainWindow::setEngine(Engine *engine)
{
	this->engine = engine;
}

SquareControl * MainWindow::createSquareButton(QRect *defaultGeometry) {

    SquareControl *button = new SquareControl();
    button->setGeometry(*defaultGeometry);

    QObject::connect(button, SIGNAL(clicked()), this, SLOT(onSquareButtonLeftClicked()));
    QObject::connect(button, SIGNAL(rightClicked()), this, SLOT(onSquareButtonRightClicked()));
    QObject::connect(button, SIGNAL(mutuallyClicked()), this, SLOT(onSquareButtonMutuallyClicked()));

    return button;
}

void MainWindow::initialize()
{
	engine->initialize();

    Minefield *minefield = engine->getMinefield();

    unsigned short minefieldWidth = minefield->getWidth();
    unsigned short minefieldHeight = minefield->getHeight();

    QWidget *minefieldWidget = ui->minefieldWidget;
    QGridLayout *minefieldLayout = ui->minefieldLayout;

    QRect *defaultGeometry = new QRect();
    defaultGeometry->setWidth(18);
    defaultGeometry->setHeight(18);

    for (unsigned short i = 0 ; i < minefieldHeight ; i++) {
        for (unsigned short j = 0 ; j < minefieldWidth ; j++) {

            QPushButton *squareButton = createSquareButton(defaultGeometry);

            minefieldLayout->addWidget(squareButton, i, j, 1, 1, Qt::AlignCenter);
        }
    }

    int width = minefieldLayout->columnCount() * defaultGeometry->width() + (minefieldLayout->columnCount() + 1) * minefieldLayout->horizontalSpacing() + 30;
    int height = minefieldLayout->rowCount() * defaultGeometry->height() + (minefieldLayout->rowCount() + 1) * minefieldLayout->verticalSpacing() + 40;

    minefieldWidget->setGeometry(20, 20, width, height);

    QWidget *centralWidget = ui->centralWidget;
    centralWidget->resize(20 + width + 20, 20 + height + 20);

    this->setFixedSize(centralWidget->width(), centralWidget->height() + ui->menuBar->height());
}
