#ifndef DRAWER_H
#define DRAWER_H

#include <QWidget>
#include <QMessageBox>
#include <QPainter>
#include <QPainterPath>
#include <QPen>

#include <complex>
namespace Ui {
class Drawer;
}

class Drawer : public QWidget
{
    Q_OBJECT

public:
    explicit Drawer(QWidget *parent = nullptr);
    ~Drawer();

    void paintEvent(QPaintEvent *);

    int intervalNumber;
private slots:



private:
    Ui::Drawer *ui;
    int xMax,xMin,yMax,yMin;

};

#endif // DRAWER_H
