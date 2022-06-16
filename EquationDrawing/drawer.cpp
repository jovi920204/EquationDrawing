#include "drawer.h"
#include "ui_drawer.h"

Drawer::Drawer(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Drawer)
{
    ui->setupUi(this);
    this->setGeometry(0,0,601,601);
    intervalNumber = 10;
    xMax = 10;
    xMin = -10;
    yMax = 10;
    yMin = -10;
}

Drawer::~Drawer()
{
    delete ui;
}

void Drawer::paintEvent(QPaintEvent *event){

    QPainter painter(this);
    int W = width();
    int H = height();
    int side = qMin(W,H);
    int x_Pro = 600/(xMax-xMin);
    int y_Pro = 600/(yMax-yMin);
    int x_max = xMax*x_Pro;
    int x_min = xMin*x_Pro;
    int y_max = yMax*y_Pro;
    int y_min = yMin*y_Pro;


    QRect rect(0, 0, 600, 600);
    painter.drawRect(rect);

    painter.setViewport(rect);
    painter.setWindow(x_min,y_max,x_max*2,y_min*2);


    int interval = intervalNumber;

    // draw x and y axis
    painter.setPen(QPen(Qt::black, 5));
    painter.drawLine(x_min,0,x_max,0);
    painter.drawLine(0,y_min,0,y_max);
    // draw grid => default interval is 10 block;
    painter.setPen(QPen(Qt::black, 1));
    for (int x=x_min;x<=x_max;x+=(side/interval)){
        painter.drawLine(x,y_min,x,y_max);
    }
    for (int y=y_min;y<=y_max;y+=(side/interval)){
        painter.drawLine(x_min,y,x_max,y);
    }

    //draw equation;

}


