//***********************************************************************
//  this Drawer class is the widget, which can draw equation ,x-y axis and grid
//***********************************************************************

#ifndef DRAWER_H
#define DRAWER_H

#include <QWidget>
#include <QMessageBox>
#include <QPainter>
#include <QPainterPath>
#include <QPen>
#include <fstream>
#include <complex>
#include <QFile>
#include <QList>

#include <map>
#include <vector>
#include "widget.h"


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

    void changeRange(int xmax,int xmin, int ymax, int ymin);

    void addEquation(Widget *w);


private slots:
    void receiveAddEquation(Widget *);
    void receiveDeleteEquation(Widget *);
private:
    Ui::Drawer *ui;
    int xMax,xMin,yMax,yMin;
    QList<Widget*> equationList;
    // 當CreateButton新增時, 用成員函式新增Widget物件到equationLst裡面
    // visible或是delete也是調用成員函式完成狀態更新或是刪除
    std::map<QString,QString> table; // variable table


};

#endif // DRAWER_H
