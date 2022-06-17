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
    void setVisibleStatus(bool status);
signals:
    void sendRemoveItem(const QString &text);

private slots:
    void on_visibleButton_clicked();

    void on_deleteButton_clicked();

    void setLineEditStatus(bool status); // 0 is readOnly 1 is editible

    bool isVisible(){ return visible; } // 0 is can't see, 1 is can see
private:
    Ui::Widget *ui;
    QVector<QColor> colorVec;
    bool visible; // 0 is can't see, 1 is can see

};

#endif // WIDGET_H
