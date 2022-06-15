/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 6.3.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QHBoxLayout *horizontalLayout_3;
    QHBoxLayout *horizontalLayout_2;
    QLabel *colorLabel;
    QLineEdit *lineEdit;
    QHBoxLayout *horizontalLayout;
    QPushButton *visibleButton;
    QPushButton *deleteButton;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(474, 46);
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Widget->sizePolicy().hasHeightForWidth());
        Widget->setSizePolicy(sizePolicy);
        horizontalLayout_3 = new QHBoxLayout(Widget);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        colorLabel = new QLabel(Widget);
        colorLabel->setObjectName(QString::fromUtf8("colorLabel"));

        horizontalLayout_2->addWidget(colorLabel);

        lineEdit = new QLineEdit(Widget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        horizontalLayout_2->addWidget(lineEdit);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        visibleButton = new QPushButton(Widget);
        visibleButton->setObjectName(QString::fromUtf8("visibleButton"));
        sizePolicy.setHeightForWidth(visibleButton->sizePolicy().hasHeightForWidth());
        visibleButton->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(visibleButton);

        deleteButton = new QPushButton(Widget);
        deleteButton->setObjectName(QString::fromUtf8("deleteButton"));
        sizePolicy.setHeightForWidth(deleteButton->sizePolicy().hasHeightForWidth());
        deleteButton->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(deleteButton);


        horizontalLayout_2->addLayout(horizontalLayout);


        horizontalLayout_3->addLayout(horizontalLayout_2);


        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "Form", nullptr));
        colorLabel->setText(QString());
        visibleButton->setText(QCoreApplication::translate("Widget", "visible", nullptr));
        deleteButton->setText(QCoreApplication::translate("Widget", "delete", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
