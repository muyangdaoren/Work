/********************************************************************************
** Form generated from reading UI file 'DicomBrowser.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DICOMBROWSER_H
#define UI_DICOMBROWSER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <qcustomplot.h>
#include "QVTKWidget.h"

QT_BEGIN_NAMESPACE

class Ui_DicomBrowserClass
{
public:
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_9;
    QHBoxLayout *horizontalLayout_6;
    QVTKWidget *qvtkWidget;
    QCustomPlot *qcustomplot;
    QFrame *frame;
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox_3;
    QHBoxLayout *horizontalLayout;
    QTableWidget *patientTable;
    QGroupBox *groupBox;
    QHBoxLayout *horizontalLayout_2;
    QTableWidget *studyTable;
    QGroupBox *groupBox_2;
    QHBoxLayout *horizontalLayout_3;
    QTableWidget *seriesTable;
    QGroupBox *groupBox_4;
    QHBoxLayout *horizontalLayout_4;
    QTableWidget *imageTable;
    QHBoxLayout *horizontalLayout_8;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label;
    QLineEdit *windowCenterEdit;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_2;
    QLineEdit *windowWidthEdit;
    QVBoxLayout *verticalLayout_2;
    QFrame *frame_2;
    QVBoxLayout *verticalLayout_4;
    QPushButton *switchTo3DBtn;
    QPushButton *preBtn;
    QPushButton *nextBtn;
    QPushButton *loadBtn;
    QSpacerItem *verticalSpacer;

    void setupUi(QWidget *DicomBrowserClass)
    {
        if (DicomBrowserClass->objectName().isEmpty())
            DicomBrowserClass->setObjectName(QStringLiteral("DicomBrowserClass"));
        DicomBrowserClass->resize(1310, 517);
        gridLayout = new QGridLayout(DicomBrowserClass);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setSpacing(6);
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        qvtkWidget = new QVTKWidget(DicomBrowserClass);
        qvtkWidget->setObjectName(QStringLiteral("qvtkWidget"));

        horizontalLayout_6->addWidget(qvtkWidget);

        qcustomplot = new QCustomPlot(DicomBrowserClass);
        qcustomplot->setObjectName(QStringLiteral("qcustomplot"));
        qcustomplot->setStyleSheet(QStringLiteral("bachground-color:rgb(227, 221, 220)"));

        horizontalLayout_6->addWidget(qcustomplot);

        horizontalLayout_6->setStretch(0, 1);
        horizontalLayout_6->setStretch(1, 1);

        horizontalLayout_9->addLayout(horizontalLayout_6);

        frame = new QFrame(DicomBrowserClass);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setFrameShape(QFrame::WinPanel);
        frame->setFrameShadow(QFrame::Plain);
        verticalLayout = new QVBoxLayout(frame);
        verticalLayout->setSpacing(0);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        groupBox_3 = new QGroupBox(frame);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        QFont font;
        font.setFamily(QStringLiteral("Arial"));
        font.setPointSize(12);
        font.setBold(true);
        font.setWeight(75);
        groupBox_3->setFont(font);
        horizontalLayout = new QHBoxLayout(groupBox_3);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(2, 2, 2, 2);
        patientTable = new QTableWidget(groupBox_3);
        patientTable->setObjectName(QStringLiteral("patientTable"));

        horizontalLayout->addWidget(patientTable);


        verticalLayout->addWidget(groupBox_3);

        groupBox = new QGroupBox(frame);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setFont(font);
        horizontalLayout_2 = new QHBoxLayout(groupBox);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        studyTable = new QTableWidget(groupBox);
        studyTable->setObjectName(QStringLiteral("studyTable"));

        horizontalLayout_2->addWidget(studyTable);


        verticalLayout->addWidget(groupBox);

        groupBox_2 = new QGroupBox(frame);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setFont(font);
        horizontalLayout_3 = new QHBoxLayout(groupBox_2);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        seriesTable = new QTableWidget(groupBox_2);
        seriesTable->setObjectName(QStringLiteral("seriesTable"));

        horizontalLayout_3->addWidget(seriesTable);


        verticalLayout->addWidget(groupBox_2);

        groupBox_4 = new QGroupBox(frame);
        groupBox_4->setObjectName(QStringLiteral("groupBox_4"));
        groupBox_4->setFont(font);
        horizontalLayout_4 = new QHBoxLayout(groupBox_4);
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        imageTable = new QTableWidget(groupBox_4);
        imageTable->setObjectName(QStringLiteral("imageTable"));

        horizontalLayout_4->addWidget(imageTable);


        verticalLayout->addWidget(groupBox_4);


        horizontalLayout_9->addWidget(frame);

        horizontalLayout_9->setStretch(0, 6);
        horizontalLayout_9->setStretch(1, 2);

        verticalLayout_3->addLayout(horizontalLayout_9);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        label = new QLabel(DicomBrowserClass);
        label->setObjectName(QStringLiteral("label"));
        label->setMaximumSize(QSize(50, 16777215));
        label->setAlignment(Qt::AlignCenter);

        horizontalLayout_5->addWidget(label);

        windowCenterEdit = new QLineEdit(DicomBrowserClass);
        windowCenterEdit->setObjectName(QStringLiteral("windowCenterEdit"));
        windowCenterEdit->setMaximumSize(QSize(150, 16777215));

        horizontalLayout_5->addWidget(windowCenterEdit);


        horizontalLayout_8->addLayout(horizontalLayout_5);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_2);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(0);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        label_2 = new QLabel(DicomBrowserClass);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setMaximumSize(QSize(50, 16777215));
        label_2->setAlignment(Qt::AlignCenter);

        horizontalLayout_7->addWidget(label_2);

        windowWidthEdit = new QLineEdit(DicomBrowserClass);
        windowWidthEdit->setObjectName(QStringLiteral("windowWidthEdit"));
        windowWidthEdit->setMaximumSize(QSize(150, 16777215));

        horizontalLayout_7->addWidget(windowWidthEdit);


        horizontalLayout_8->addLayout(horizontalLayout_7);


        verticalLayout_3->addLayout(horizontalLayout_8);


        gridLayout->addLayout(verticalLayout_3, 0, 0, 1, 1);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        frame_2 = new QFrame(DicomBrowserClass);
        frame_2->setObjectName(QStringLiteral("frame_2"));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        verticalLayout_4 = new QVBoxLayout(frame_2);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        switchTo3DBtn = new QPushButton(frame_2);
        switchTo3DBtn->setObjectName(QStringLiteral("switchTo3DBtn"));
        switchTo3DBtn->setMinimumSize(QSize(0, 50));
        switchTo3DBtn->setFont(font);
        QIcon icon;
        icon.addFile(QStringLiteral(":/DicomBrowser/Resources/arr2.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        switchTo3DBtn->setIcon(icon);

        verticalLayout_4->addWidget(switchTo3DBtn);

        preBtn = new QPushButton(frame_2);
        preBtn->setObjectName(QStringLiteral("preBtn"));
        preBtn->setMinimumSize(QSize(0, 50));
        preBtn->setFont(font);

        verticalLayout_4->addWidget(preBtn);

        nextBtn = new QPushButton(frame_2);
        nextBtn->setObjectName(QStringLiteral("nextBtn"));
        nextBtn->setMinimumSize(QSize(0, 50));
        nextBtn->setFont(font);

        verticalLayout_4->addWidget(nextBtn);

        loadBtn = new QPushButton(frame_2);
        loadBtn->setObjectName(QStringLiteral("loadBtn"));
        loadBtn->setMinimumSize(QSize(0, 50));
        loadBtn->setFont(font);

        verticalLayout_4->addWidget(loadBtn);

        verticalSpacer = new QSpacerItem(17, 250, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_4->addItem(verticalSpacer);


        verticalLayout_2->addWidget(frame_2);

        verticalLayout_2->setStretch(0, 2);

        gridLayout->addLayout(verticalLayout_2, 0, 1, 1, 1);


        retranslateUi(DicomBrowserClass);

        QMetaObject::connectSlotsByName(DicomBrowserClass);
    } // setupUi

    void retranslateUi(QWidget *DicomBrowserClass)
    {
        DicomBrowserClass->setWindowTitle(QApplication::translate("DicomBrowserClass", "DicomBrowser", 0));
        groupBox_3->setTitle(QApplication::translate("DicomBrowserClass", "Patient", 0));
        groupBox->setTitle(QApplication::translate("DicomBrowserClass", "Study", 0));
        groupBox_2->setTitle(QApplication::translate("DicomBrowserClass", "Series", 0));
        groupBox_4->setTitle(QApplication::translate("DicomBrowserClass", "Image", 0));
        label->setText(QApplication::translate("DicomBrowserClass", "\347\252\227\344\275\215\357\274\232", 0));
        label_2->setText(QApplication::translate("DicomBrowserClass", "\347\252\227\345\256\275\357\274\232", 0));
        switchTo3DBtn->setText(QApplication::translate("DicomBrowserClass", "\351\232\220\350\227\217", 0));
        preBtn->setText(QApplication::translate("DicomBrowserClass", "\344\270\212\344\270\200\345\274\240", 0));
        nextBtn->setText(QApplication::translate("DicomBrowserClass", "\344\270\213\344\270\200\345\274\240", 0));
        loadBtn->setText(QApplication::translate("DicomBrowserClass", "\345\212\240\350\275\275\346\226\207\344\273\266", 0));
    } // retranslateUi

};

namespace Ui {
    class DicomBrowserClass: public Ui_DicomBrowserClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DICOMBROWSER_H
