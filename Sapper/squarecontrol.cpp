#include "squarecontrol.h"

SquareControl::SquareControl(QWidget *parent) : QPushButton(parent)
{
}

void SquareControl::mousePressEvent(QMouseEvent *e)
{
    if(e->button() & Qt::LeftButton) {
        this->state += 1;
    } else if (e->button() & Qt::RightButton) {
        this->state += 2;
    }

    QPushButton::mousePressEvent(e);
}

void SquareControl::mouseReleaseEvent(QMouseEvent *e)
{
    if (this->state == 3) {
        this->state = 0;
        emit mutuallyClicked();
    } else if (this->state == 2) {
        this->state = 0;
        emit rightClicked();
    } else {
        this->state = 0;
        QPushButton::mouseReleaseEvent(e);
    }
}
