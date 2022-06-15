#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QMessageBox>


namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();

    QString getText();
    void setText(const QString &text);

private slots:
    void on_visibleButton_clicked();

    void on_deleteButton_clicked();

    void setLineEditStatus(bool status); // 0 is readOnly 1 is editible

private:
    Ui::Widget *ui;
};

#endif // WIDGET_H
