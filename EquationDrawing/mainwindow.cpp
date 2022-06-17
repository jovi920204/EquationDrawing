#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    rec = 0;

    ui->DrawerWidget = new Drawer(this);

    connect(this, SIGNAL(sendAddEquation(Widget *)), ui->DrawerWidget, SLOT(receiveAddEquation(Widget *)));

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_addButton_clicked()
{
    auto item = new QListWidgetItem();
    Widget *widget = new Widget(this);
//    widget->setText(QString::number(ui->listWidget->count()));

    item->setSizeHint(widget->sizeHint());
    widget->setColor();
    widget->setText("");
    ui->listWidget->addItem(item);
    ui->listWidget->setItemWidget(item, widget);
    emit sendAddEquation(widget);
}


void MainWindow::on_listWidget_doubleClicked(const QModelIndex &index)
{
}

void MainWindow::removeItem(const QString &text)
{
    qDebug("removeItem func called");
    for(int i = 0; i < ui->listWidget->count(); i++) {
        auto item = ui->listWidget->item(i);
        auto itemWidget = dynamic_cast<Widget*>(ui->listWidget->itemWidget(item));
        if(itemWidget->getText() == text) {
            delete item;
            return;
        }
    }
}
