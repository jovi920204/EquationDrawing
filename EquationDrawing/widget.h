#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QMessageBox>
#include <stdlib.h>
#include <time.h>


namespace Ui
{
    class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();

    QString getText();
    QColor getColor();
    void setText(const QString &text);
    void setColor();

signals:
    void sendRemoveItem(const QString &text);

private slots:
    void on_visibleButton_clicked();

    void on_deleteButton_clicked();

    void setLineEditStatus(bool status); // 0 is readOnly 1 is editible

private:
    Ui::Widget *ui;
    QVector<QColor> colorVec;
};

#endif // WIDGET_H
