#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QLineEdit>
#include <QMessageBox>
#include "widget.h"
#include "drawer.h"

QT_BEGIN_NAMESPACE
namespace Ui
{
    class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    int rec;

signals:
    void sendAddEquation(Widget *);
private slots:
    void on_addButton_clicked();

    void on_listWidget_doubleClicked(const QModelIndex &index);

    void removeItem(const QString &text);

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
