#ifndef SQUARECONTROL_H
#define SQUARECONTROL_H

#include <QPushButton>
#include <QMouseEvent>

class SquareControl : public QPushButton
{
    Q_OBJECT

public:

    explicit SquareControl(QWidget *parent = 0);

protected:

    void mousePressEvent(QMouseEvent *e) Q_DECL_OVERRIDE;

    void mouseReleaseEvent(QMouseEvent *e) Q_DECL_OVERRIDE;

private:

    short state = 0;

signals:

    void rightClicked();

    void mutuallyClicked();

};

#endif // QRIGHTCLICKBUTTON_H
