/********************************************************************************
** Form generated from reading UI file 'AboutView.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ABOUTVIEW_H
#define UI_ABOUTVIEW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AboutView
{
public:
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLabel *label_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_5;
    QSpacerItem *horizontalSpacer;
    QLabel *label_3;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_6;
    QSpacerItem *horizontalSpacer_2;
    QLabel *label_4;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_7;
    QSpacerItem *horizontalSpacer_3;
    QLabel *label_8;

    void setupUi(QWidget *AboutView)
    {
        if (AboutView->objectName().isEmpty())
            AboutView->setObjectName(QStringLiteral("AboutView"));
        AboutView->resize(551, 274);
        QFont font;
        font.setFamily(QString::fromUtf8(".\350\220\215\346\226\271-\347\256\200"));
        AboutView->setFont(font);
        AboutView->setStyleSheet(QLatin1String("QDialog\n"
"{\n"
"	background-color: rgb(255, 255, 255);\n"
"}"));
        verticalLayout_2 = new QVBoxLayout(AboutView);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(AboutView);
        label->setObjectName(QStringLiteral("label"));
        QFont font1;
        font1.setFamily(QStringLiteral("Yu Gothic UI Light"));
        font1.setPointSize(36);
        label->setFont(font1);
        label->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(label);


        verticalLayout->addLayout(horizontalLayout);

        label_2 = new QLabel(AboutView);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setFont(font);
        label_2->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label_2);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_5 = new QLabel(AboutView);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_2->addWidget(label_5);

        horizontalSpacer = new QSpacerItem(20, 20, QSizePolicy::Preferred, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        label_3 = new QLabel(AboutView);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout_2->addWidget(label_3);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_6 = new QLabel(AboutView);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_3->addWidget(label_6);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Preferred, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);

        label_4 = new QLabel(AboutView);
        label_4->setObjectName(QStringLiteral("label_4"));

        horizontalLayout_3->addWidget(label_4);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_7 = new QLabel(AboutView);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_4->addWidget(label_7);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Preferred, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_3);

        label_8 = new QLabel(AboutView);
        label_8->setObjectName(QStringLiteral("label_8"));

        horizontalLayout_4->addWidget(label_8);


        verticalLayout->addLayout(horizontalLayout_4);


        verticalLayout_2->addLayout(verticalLayout);


        retranslateUi(AboutView);

        QMetaObject::connectSlotsByName(AboutView);
    } // setupUi

    void retranslateUi(QWidget *AboutView)
    {
        AboutView->setWindowTitle(QApplication::translate("AboutView", "AboutView", nullptr));
        label->setText(QApplication::translate("AboutView", "About", nullptr));
        label_2->setText(QApplication::translate("AboutView", "Millennium Player", nullptr));
        label_5->setText(QApplication::translate("AboutView", "\347\211\210\346\234\254", nullptr));
        label_3->setText(QApplication::translate("AboutView", "0.0.1", nullptr));
        label_6->setText(QApplication::translate("AboutView", "\344\275\234\350\200\205", nullptr));
        label_4->setText(QApplication::translate("AboutView", "\347\277\237\351\225\277\350\205\277", nullptr));
        label_7->setText(QApplication::translate("AboutView", "\344\277\256\350\256\242\346\227\266\351\227\264", nullptr));
        label_8->setText(QApplication::translate("AboutView", "2018.3.16", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AboutView: public Ui_AboutView {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ABOUTVIEW_H
