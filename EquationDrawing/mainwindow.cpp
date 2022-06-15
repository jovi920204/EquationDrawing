#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_addButton_clicked()
{
//    QLineEdit *label = new QLineEdit;
//    label->setText(QString::number(ui->listWidget->count()));
//    ui->listWidget->addItem(label->text());
    auto item = new QListWidgetItem();
    Widget *widget = new Widget(this);
    widget->setText(QString::number(ui->listWidget->count()));

    item->setSizeHint(widget->sizeHint());

    ui->listWidget->addItem(item);
    ui->listWidget->setItemWidget(item, widget);

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

