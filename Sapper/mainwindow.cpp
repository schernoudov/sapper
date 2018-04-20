#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QPushButton"

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

void MainWindow::onSquareButtonClicked()
{
    QPushButton* sender = qobject_cast<QPushButton*>(QObject::sender());

    int index = ui->minefieldLayout->indexOf(sender);

    Q_ASSERT(index >= 0);

    int rs,cs;
    QPair<int, int> position = qMakePair(-1,-1);

    ui->minefieldLayout->getItemPosition(index, &position.first, &position.second, &rs, &cs);
}

void MainWindow::setEngine(Engine *engine)
{
	this->engine = engine;
}

QPushButton * MainWindow::createSquareButton(QRect *defaultGeometry) {

    QPushButton *button = new QPushButton();
    button->setGeometry(*defaultGeometry);

    QObject::connect(button, SIGNAL(clicked()), this, SLOT(onSquareButtonClicked()));

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
