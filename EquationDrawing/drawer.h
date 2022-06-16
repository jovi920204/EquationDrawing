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

#include <map>
#include <vector>
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


private slots:

private:
    Ui::Drawer *ui;
    int xMax,xMin,yMax,yMin;
    std::vector<QString> equationList;
    std::map<QString,QString> table; // variable table

};

#endif // DRAWER_H
