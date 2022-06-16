#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    connect(this, SIGNAL(sendRemoveItem(const QString &)), parent, SLOT(removeItem(const QString &)));
}

Widget::~Widget()
{
    delete ui;
}

QString Widget::getText()
{
    return ui->lineEdit->text();
}

void Widget::setText(const QString &text)
{
    ui->lineEdit->setText(text);
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
