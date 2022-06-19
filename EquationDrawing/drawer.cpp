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


    setMouseTracking(true);
}

Drawer::~Drawer()
{
    delete ui;
}

void Drawer::changeRange(double xmax,double xmin, double ymax, double ymin){
//    qDebug() << xmax << " " << xmin << " " << ymax << " " << ymin;
    if ((xmax - xmin) <= 8 || (ymax - ymin) <= 8){
        return;
    }
    if ((xmax-xmin) >= 600 || (ymax - ymin) >= 600){
        return;
    }
    xMax = xmax, xMin = xmin, yMax = ymax, yMin = ymin;
    Drawer::update();
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
//    qDebug() << "paintEvent!!";
    QPainter painter(this);
    int W = width();
    int H = height();
    int side = qMin(xMax-xMin,yMax-yMin);
    int x_Pro = 600/(xMax-xMin);
    int y_Pro = 600/(yMax-yMin);
    int xRange = xMax - xMin;
    int yRange = yMax - yMin;
    QRect rect(0, 0, 600, 600);
    painter.drawRect(rect);

    painter.setViewport(rect);
//    painter.setWindow(-xRange/2,yRange/2,xRange,-yRange);
    painter.setWindow(xMin,yMax,xRange,-yRange);

    int interval = intervalNumber;

    // draw x and y axis
    painter.setPen(QPen(Qt::black, 1/x_Pro+(0.1)*xRange/10));
    painter.drawLine(xMin,0,xMax,0);
    painter.drawLine(0,yMin,0,yMax);
    // draw grid => default interval is 10 block;
    painter.setPen(QPen(Qt::black,1/x_Pro));
    for (double x=0;x<=xMax;x+=(side/interval)){
        painter.drawLine(QPointF(x,yMin),QPointF(x,yMax));
    }
    for (double x=0;x>=xMin;x-=(side/interval)){
        painter.drawLine(QPointF(x,yMin),QPointF(x,yMax));
    }
    for (double y=0;y<=yMax;y+=(side/interval)){
        painter.drawLine(QPointF(xMin,y),QPointF(xMax,y));
    }
    for (double y=0;y>=yMin;y-=(side/interval)){
        painter.drawLine(QPointF(xMin,y),QPointF(xMax,y));
    }

    //draw equation;
    painter.setPen(QPen(Qt::blue,1/x_Pro+(0.1)*xRange/2/10));
    double preX = xMin ,preY = qSin(xMin);
    double dot = (xMax-xMin)/500.f;

    for (double x = xMin + dot; x <= xMax ;x += dot){
        painter.drawLine(QPointF(preX,preY),QPointF(x,qSin(x)));
        preX = x;
        preY = qSin(x);
    }
    for (int x = xMin; x <= xMax ; x++){
        for (int y = yMin ; y <= yMax ; y++){
            if (x == y) {
                painter.drawPoint(x,y);
            }
        }
    }

    // 一個for迴圈跑過所有的equationList
    // if (widget的isVisible() == true)
    // 再畫出來
    // 畫的步驟是 -> 帶入範圍 -> 生成出檔案 -> vector存檔案的x,y -> 跑vector中所有的點{ painter.drawLine }
}

void Drawer::mousePressEvent(QMouseEvent *event){
    pressflag = true;
}

void Drawer::mouseMoveEvent(QMouseEvent *event){
    int sensity = 600/(xMax-xMin);

    if(pressflag){
        QPointF temp;
        QPointF nowMousePos = event->pos();
        if (lastMousePos.isNull()){
            lastMousePos = nowMousePos;
        }
        else{
            temp = nowMousePos - lastMousePos;
            qDebug() << temp;
            changeRange(xMax-temp.x()/sensity,xMin-temp.x()/sensity,yMax+temp.y()/sensity,yMin+temp.y()/sensity);
            lastMousePos = nowMousePos;
        }

    }
}

void Drawer::mouseReleaseEvent(QMouseEvent *event){
    pressflag = false;
    lastMousePos = QPoint();
}

void Drawer::wheelEvent(QWheelEvent *event){
    QPoint numDegrees = event->angleDelta();
    if (numDegrees.y() > 0){ // 向前滾動
//        qDebug() << "front" << numDegrees.y();
        this->zoomIn();
    }
    else {
//        qDebug() << "back" << numDegrees.y();
        this->zoomOut();
    }
}

void Drawer::zoomIn(){
    this->changeRange(xMax-1,xMin+1,yMax-1,yMin+1);
}

void Drawer::zoomOut(){
    this->changeRange(xMax+1,xMin-1,yMax+1,yMin-1);
}

