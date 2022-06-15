#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

QString Widget::getText(){
    return ui->lineEdit->text();
}

void Widget::setText(const QString &text){
    ui->lineEdit->setText(text);
}

void Widget::on_visibleButton_clicked()
{

}


void Widget::on_deleteButton_clicked()
{

    delete this;
}

void Widget::setLineEditStatus(bool status){
    // status = 1 => lineEdit is Editible
    if (status == 0){
        ui->lineEdit->setReadOnly(true);
    }
    else {
        ui->lineEdit->setReadOnly(false);
    }
}

