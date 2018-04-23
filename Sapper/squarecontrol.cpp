#include "squarecontrol.h"
#include <QDateTime>
#include <QDebug>

SquareControl::SquareControl(QWidget *parent) : QPushButton(parent)
{
}

void SquareControl::mousePressEvent(QMouseEvent *e)
{

    if((e->buttons() & Qt::RightButton) && (e->buttons() & Qt::LeftButton))
    {
        emit doubleClicked();
    }

    if (e->button() == Qt::RightButton)
    {
        emit rightClicked();
    }

    if (e->button() == Qt::LeftButton)
    {
        QPushButton::mousePressEvent(e);
    }
}
