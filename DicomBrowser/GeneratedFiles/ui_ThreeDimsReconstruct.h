/********************************************************************************
** Form generated from reading UI file 'ThreeDimsReconstruct.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_THREEDIMSRECONSTRUCT_H
#define UI_THREEDIMSRECONSTRUCT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <qcustomplot.h>
#include "QVTKWidget.h"

QT_BEGIN_NAMESPACE

class Ui_ThreeDimsReconstruct
{
public:
    QHBoxLayout *horizontalLayout_5;
    QWidget *widget;
    QVBoxLayout *verticalLayout_2;
    QCustomPlot *showPlot;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer_4;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QLineEdit *lineEdit;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QLineEdit *lineEdit_2;
    QWidget *widget_2;
    QVBoxLayout *verticalLayout_3;
    QVTKWidget *vtkWidget;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *pushButton_3;
    QSpacerItem *horizontalSpacer_3;

    void setupUi(QWidget *ThreeDimsReconstruct)
    {
        if (ThreeDimsReconstruct->objectName().isEmpty())
            ThreeDimsReconstruct->setObjectName(QStringLiteral("ThreeDimsReconstruct"));
        ThreeDimsReconstruct->resize(992, 484);
        horizontalLayout_5 = new QHBoxLayout(ThreeDimsReconstruct);
        horizontalLayout_5->setSpacing(2);
        horizontalLayout_5->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(2, 2, 2, 2);
        widget = new QWidget(ThreeDimsReconstruct);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setStyleSheet(QStringLiteral("background-color: rgba(232, 232, 232,150);r"));
        verticalLayout_2 = new QVBoxLayout(widget);
        verticalLayout_2->setSpacing(2);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(2, 2, 2, 2);
        showPlot = new QCustomPlot(widget);
        showPlot->setObjectName(QStringLiteral("showPlot"));
        showPlot->setMinimumSize(QSize(0, 0));
        showPlot->setStyleSheet(QStringLiteral(""));

        verticalLayout_2->addWidget(showPlot);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_4);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label = new QLabel(widget);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout_2->addWidget(label);

        lineEdit = new QLineEdit(widget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));

        horizontalLayout_2->addWidget(lineEdit);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label_2 = new QLabel(widget);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout->addWidget(label_2);

        lineEdit_2 = new QLineEdit(widget);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));

        horizontalLayout->addWidget(lineEdit_2);


        verticalLayout->addLayout(horizontalLayout);


        horizontalLayout_4->addLayout(verticalLayout);


        verticalLayout_2->addLayout(horizontalLayout_4);

        verticalLayout_2->setStretch(0, 5);
        verticalLayout_2->setStretch(1, 1);

        horizontalLayout_5->addWidget(widget);

        widget_2 = new QWidget(ThreeDimsReconstruct);
        widget_2->setObjectName(QStringLiteral("widget_2"));
        verticalLayout_3 = new QVBoxLayout(widget_2);
        verticalLayout_3->setSpacing(2);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(2, 2, 2, 2);
        vtkWidget = new QVTKWidget(widget_2);
        vtkWidget->setObjectName(QStringLiteral("vtkWidget"));

        verticalLayout_3->addWidget(vtkWidget);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        pushButton = new QPushButton(widget_2);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        horizontalLayout_3->addWidget(pushButton);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);

        pushButton_3 = new QPushButton(widget_2);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));

        horizontalLayout_3->addWidget(pushButton_3);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_3);


        verticalLayout_3->addLayout(horizontalLayout_3);

        verticalLayout_3->setStretch(0, 10);
        verticalLayout_3->setStretch(1, 1);

        horizontalLayout_5->addWidget(widget_2);


        retranslateUi(ThreeDimsReconstruct);

        QMetaObject::connectSlotsByName(ThreeDimsReconstruct);
    } // setupUi

    void retranslateUi(QWidget *ThreeDimsReconstruct)
    {
        ThreeDimsReconstruct->setWindowTitle(QApplication::translate("ThreeDimsReconstruct", "ThreeDimsReconstruct", 0));
        label->setText(QApplication::translate("ThreeDimsReconstruct", "\347\252\227\344\275\215", 0));
        label_2->setText(QApplication::translate("ThreeDimsReconstruct", "\347\252\227\345\256\275", 0));
        pushButton->setText(QApplication::translate("ThreeDimsReconstruct", "\345\210\207\346\215\242\344\270\211\350\247\222\351\235\242\347\211\207", 0));
        pushButton_3->setText(QApplication::translate("ThreeDimsReconstruct", "\345\210\207\346\215\242STL", 0));
    } // retranslateUi

};

namespace Ui {
    class ThreeDimsReconstruct: public Ui_ThreeDimsReconstruct {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_THREEDIMSRECONSTRUCT_H
