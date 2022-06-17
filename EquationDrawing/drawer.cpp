#include "drawer.h"
#include "ui_drawer.h"
#include <QGraphicsRectItem>>

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

void Drawer::changeRange(int xmax,int xmin, int ymax, int ymin){
    xMax = xmax, xMin = xmin, yMax = ymax, yMin = ymin;
}

void Drawer::addEquation(Widget *w){
    qDebug() << "Add equation";
    equationList.append(w);
}

void Drawer::receiveAddEquation(Widget *w){
    addEquation(w);
}

void Drawer::receiveDeleteEquation(Widget *w){
    auto iter = std::find(equationList.begin(), equationList.end(), w);
    equationList.erase(iter);
    qDebug() << "deleted from equationList";
}

void Drawer::paintEvent(QPaintEvent *event){
    qDebug() << "paintEvent!!";
    QPainter painter(this);
    int W = width();
    int H = height();
    int side = qMin(xMax-xMin,yMax-yMin);
    int x_Pro = 600/(xMax-xMin);
    int y_Pro = 600/(yMax-yMin);

    QRect rect(0, 0, 600, 600);
    painter.drawRect(rect);

    painter.setViewport(rect);
    painter.setWindow(xMin,yMax,xMax*2,yMin*2);

    int interval = intervalNumber;

    // draw x and y axis
    painter.setPen(QPen(Qt::black, 1/x_Pro+(0.1)*xMax/10));
    painter.drawLine(xMin,0,xMax,0);
    painter.drawLine(0,yMin,0,yMax);
    // draw grid => default interval is 10 block;
    painter.setPen(QPen(Qt::black,1/x_Pro));
    for (double x=xMin;x<=xMax;x+=(side/interval)){
        painter.drawLine(x,yMin,x,yMax);
    }
    for (double y=yMin;y<=yMax;y+=(side/interval)){
        painter.drawLine(xMin,y,xMax,y);
    }

    //draw equation;
    painter.setPen(QPen(Qt::blue,1/x_Pro+(0.1)*xMax/10));
    double preX = xMin ,preY = qSin(xMin);
    double dot = (xMax-xMin)/500.f;

    for (double x = xMin + dot; x <= xMax ;x += dot){
        painter.drawLine(QPointF(preX,preY),QPointF(x,qSin(x)));
        preX = x;
        preY = qSin(x);
    }

    std::vector<double> xdot;
    std::vector<double> ydot;
    std::ifstream file("C:/Users/jovi9/Documents/code/EquationDrawing/EquationDrawing/EquationDrawing/output/output2.txt");
    double x, y;
    double prex, prey;
    while(file.good()){
        file >> x >> y;
        xdot.push_back(x);
        ydot.push_back(y);
    }
    prex = xdot[0], prey = ydot[0];
    for (int i= 1; i < xdot.size(); i++){
        if (prey == ydot[i]) continue;
        painter.drawLine(QPointF(prex, prey),QPointF(xdot[i],ydot[i]));
        prex = xdot[i], prey = ydot[i];
    }

    // 一個for迴圈跑過所有的equationList
    // if (widget的isVisible() == true)
    // 再畫出來
    // 畫的步驟是 -> 帶入範圍 -> 生成出檔案 -> vector存檔案的x,y -> 跑vector中所有的點{ painter.drawLine }
}


