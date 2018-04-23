#ifndef SQUARECONTROL_H
#define SQUARECONTROL_H

#include <QPushButton>
#include <QMouseEvent>

class SquareControl : public QPushButton
{
    Q_OBJECT
public:
    explicit SquareControl(QWidget *parent = 0);

protected slots:
    void mousePressEvent(QMouseEvent *e) Q_DECL_OVERRIDE;

signals:
    void rightClicked();
    void doubleClicked();
public slots:
};

#endif // QRIGHTCLICKBUTTON_H
