#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    connect(this, SIGNAL(sendRemoveItem(const QString &)), parent, SLOT(removeItem(const QString &)));
    srand(time(NULL));
}

Widget::~Widget()
{
    delete ui;
}

QString Widget::getText()
{
    return ui->lineEdit->text();
}
QColor Widget::getColor(){
    return ui->colorWidget->styleSheet();
}

void Widget::setText(const QString &text)
{
    ui->lineEdit->setText(text);
}

void Widget::setColor(){
    qDebug() << "set Color";
    ui->colorWidget->setSizeIncrement(100,100);
    QColor qc = QColor::fromHsl(rand()%360,50+rand()%180,150);
    QColor c(qc.red(),qc.green(),qc.blue());
    while(std::find(colorVec.begin(),colorVec.end(),c) != colorVec.end()){
        qc = QColor::fromHsl(rand()%360,50+rand()%180,150);
        c.setRed(qc.red());
        c.setGreen(qc.green());
        c.setBlue(qc.blue());
    }
    colorVec.push_back(c);
    QString r = QString::number(qc.red());
    QString g = QString::number(qc.green());
    QString b = QString::number(qc.blue());
    QString color = "background-color: rgb(" + r + ", " + g + ", " + b +");";
    ui->colorWidget->setStyleSheet(color);
}
void Widget::on_visibleButton_clicked()
{

}

void Widget::on_deleteButton_clicked()
{
    qDebug("deleteButton clicked func called");
    emit sendRemoveItem(ui->lineEdit->text());
}

void Widget::setLineEditStatus(bool status)
{
    // status = 1 => lineEdit is Editible
    if (status == 0) {
        ui->lineEdit->setReadOnly(true);
    } else {
        ui->lineEdit->setReadOnly(false);
    }
}
