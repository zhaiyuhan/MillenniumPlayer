/********************************************************************************
** Form generated from reading UI file 'SettingView.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETTINGVIEW_H
#define UI_SETTINGVIEW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QToolBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SettingView
{
public:
    QHBoxLayout *horizontalLayout_3;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QSpacerItem *verticalSpacer_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_5;
    QSpacerItem *verticalSpacer;
    QVBoxLayout *verticalLayout_2;
    QStackedWidget *stackedWidget;
    QWidget *page_5;
    QTabWidget *tabWidget;
    QWidget *tab;
    QGridLayout *gridLayout_2;
    QGridLayout *gridLayout;
    QLabel *label_2;
    QLabel *label_4;
    QPushButton *pushButton_6;
    QComboBox *comboBox;
    QComboBox *comboBox_2;
    QLabel *label_3;
    QPushButton *pushButton_8;
    QWidget *tab_2;
    QToolBox *toolBox;
    QWidget *page;
    QVBoxLayout *verticalLayout_4;
    QVBoxLayout *verticalLayout_3;
    QRadioButton *radioButton_2;
    QRadioButton *radioButton;
    QWidget *page_2;
    QGridLayout *gridLayout_3;
    QPushButton *pushButton_10;
    QPushButton *pushButton_9;
    QLabel *label_5;
    QWidget *page_6;
    QWidget *page_3;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_7;
    QPushButton *CancelButton;

    void setupUi(QWidget *SettingView)
    {
        if (SettingView->objectName().isEmpty())
            SettingView->setObjectName(QStringLiteral("SettingView"));
        SettingView->resize(769, 404);
        SettingView->setStyleSheet(QLatin1String("QWidget{\n"
"background-color: rgb(255, 255, 255);\n"
"}\n"
"QPushButton {\n"
"  background-color: transparent;\n"
"  border: 1px solid;\n"
"  border-color: #1E90FF;\n"
"  border-radius: 5px;\n"
"  padding: 4px;\n"
"  color: rgba(0, 0, 0, 80%);\n"
"}\n"
"QPushButton #CancelButton{\n"
"  background-color: transparent;\n"
"  padding: 4px;\n"
"  color: rgba(0, 0, 0, 80%);\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"  \n"
"  border-color: #396895;\n"
"}\n"
"\n"
"QPushButton:pressed { \n"
"  color: rgba(255, 255, 255, 90%);\n"
"  background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #4c98fe, stop: 1 #0564e3);\n"
"  border-top-color: #247fff;\n"
"  border-bottom-color: #003ddb;\n"
"  border-left-color: #125eed;\n"
"  border-right-color: #125eed;\n"
"}\n"
"\n"
"QPushButton:disabled {\n"
"  color: #333333;\n"
"}\n"
"\n"
"QTabWidget::pane {\n"
"  background-color: transparent;\n"
"  position: absolute;\n"
"  top: -0.5em;\n"
"}\n"
"\n"
"QTabWidget#Ribbon::pane {\n"
"  background-color: #ffffff;\n"
"}\n"
"\n"
""
                        "QTabWidget::tab-bar {\n"
"  alignment: center;\n"
"}\n"
"\n"
"QTabWidget#Ribbon::tab-bar {\n"
"\n"
"  left: 100px;\n"
"}\n"
"\n"
"QTabBar::tab {\n"
"  min-width: 60px;\n"
"  max-width: 60px;\n"
"  min-height: 22px;\n"
"  max-height: 22px;\n"
"  padding: 2px;\n"
"  border: 1px solid #1E90FF;\n"
"}\n"
"\n"
"QTabBar::tab:hover {\n"
"  border-color: #396895;\n"
"}\n"
"\n"
"QTabBar::tab:selected {\n"
"  background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #4c98fe, stop: 1 #0564e3);\n"
"  border-top-color: #247fff;\n"
"  border-bottom-color: #003ddb;\n"
"  border-left-color: #125eed;\n"
"  border-right-color: #125eed;\n"
"  color: white;\n"
"}\n"
"\n"
"QTabBar::tab:selected {}\n"
"\n"
"QTabBar::tab:first {\n"
"  border-top-left-radius: 5px;\n"
"  border-top-right-radius: 0px;\n"
"  border-bottom-left-radius: 5px;\n"
"  border-bottom-right-radius: 0px;\n"
"}\n"
"\n"
"QTabBar::tab:first:selected {}\n"
"\n"
"QTabBar::tab:first:!selected {}\n"
"\n"
"QTabBar::tab:first:selected,\n"
"QTabBar::tab:hover {}"
                        "\n"
"\n"
"QTabBar::tab:first:!selected,\n"
"QTabBar::tab:hover {}\n"
"\n"
"QTabBar::tab:last {\n"
"  border-top-left-radius: px;\n"
"  border-top-right-radius: 5px;\n"
"  border-bottom-left-radius: 0px;\n"
"  border-bottom-right-radius: 5px;\n"
"}\n"
"\n"
"QTabBar::tab:last:selected {}\n"
"\n"
"QTabBar::tab:last:!selected {}\n"
"\n"
"QTabBar::tab:last:selected,\n"
"QTabBar::tab:hover {}\n"
"\n"
"QTabBar::tab:last:!selected,\n"
"QTabBar::tab:hover {}\n"
"\n"
"QTabBar::tab:only-one {\n"
"  border-top-left-radius: 5px;\n"
"  border-top-right-radius: 5px;\n"
"  border-bottom-left-radius: 5px;\n"
"  border-bottom-right-radius: 5px;\n"
"}"));
        horizontalLayout_3 = new QHBoxLayout(SettingView);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(3);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(4);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        label = new QLabel(SettingView);
        label->setObjectName(QStringLiteral("label"));
        label->setMaximumSize(QSize(16777215, 50));
        QFont font;
        font.setFamily(QString::fromUtf8(".\350\220\215\346\226\271-\347\256\200"));
        font.setPointSize(30);
        label->setFont(font);
        label->setStyleSheet(QStringLiteral("color: rgba(0, 0, 0, 95);"));
        label->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);

        verticalLayout->addWidget(label);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout->addItem(verticalSpacer_2);

        pushButton_3 = new QPushButton(SettingView);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setMinimumSize(QSize(120, 40));
        pushButton_3->setMaximumSize(QSize(120, 40));

        verticalLayout->addWidget(pushButton_3);

        pushButton_4 = new QPushButton(SettingView);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setMinimumSize(QSize(0, 40));
        pushButton_4->setMaximumSize(QSize(120, 40));

        verticalLayout->addWidget(pushButton_4);

        pushButton = new QPushButton(SettingView);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setMinimumSize(QSize(0, 40));
        pushButton->setMaximumSize(QSize(120, 40));

        verticalLayout->addWidget(pushButton);

        pushButton_2 = new QPushButton(SettingView);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setMinimumSize(QSize(0, 40));
        pushButton_2->setMaximumSize(QSize(120, 40));

        verticalLayout->addWidget(pushButton_2);

        pushButton_5 = new QPushButton(SettingView);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));
        pushButton_5->setMinimumSize(QSize(0, 40));
        pushButton_5->setMaximumSize(QSize(120, 40));

        verticalLayout->addWidget(pushButton_5);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        horizontalLayout->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(5, 50, 5, 0);
        stackedWidget = new QStackedWidget(SettingView);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        page_5 = new QWidget();
        page_5->setObjectName(QStringLiteral("page_5"));
        tabWidget = new QTabWidget(page_5);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(140, 40, 341, 241));
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        gridLayout_2 = new QGridLayout(tab);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label_2 = new QLabel(tab);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 0, 0, 1, 1);

        label_4 = new QLabel(tab);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout->addWidget(label_4, 2, 0, 1, 1);

        pushButton_6 = new QPushButton(tab);
        pushButton_6->setObjectName(QStringLiteral("pushButton_6"));

        gridLayout->addWidget(pushButton_6, 0, 1, 1, 1);

        comboBox = new QComboBox(tab);
        comboBox->setObjectName(QStringLiteral("comboBox"));

        gridLayout->addWidget(comboBox, 1, 1, 1, 1);

        comboBox_2 = new QComboBox(tab);
        comboBox_2->setObjectName(QStringLiteral("comboBox_2"));

        gridLayout->addWidget(comboBox_2, 2, 1, 1, 1);

        label_3 = new QLabel(tab);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout->addWidget(label_3, 1, 0, 1, 1);

        pushButton_8 = new QPushButton(tab);
        pushButton_8->setObjectName(QStringLiteral("pushButton_8"));

        gridLayout->addWidget(pushButton_8, 3, 1, 1, 1);


        gridLayout_2->addLayout(gridLayout, 0, 0, 1, 1);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        toolBox = new QToolBox(tab_2);
        toolBox->setObjectName(QStringLiteral("toolBox"));
        toolBox->setGeometry(QRect(50, 40, 221, 121));
        page = new QWidget();
        page->setObjectName(QStringLiteral("page"));
        page->setGeometry(QRect(0, 0, 221, 69));
        verticalLayout_4 = new QVBoxLayout(page);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        radioButton_2 = new QRadioButton(page);
        radioButton_2->setObjectName(QStringLiteral("radioButton_2"));

        verticalLayout_3->addWidget(radioButton_2);

        radioButton = new QRadioButton(page);
        radioButton->setObjectName(QStringLiteral("radioButton"));

        verticalLayout_3->addWidget(radioButton);


        verticalLayout_4->addLayout(verticalLayout_3);

        toolBox->addItem(page, QString::fromUtf8("\345\205\263\351\227\255\344\270\273\351\235\242\346\235\277"));
        page_2 = new QWidget();
        page_2->setObjectName(QStringLiteral("page_2"));
        page_2->setGeometry(QRect(0, 0, 221, 69));
        gridLayout_3 = new QGridLayout(page_2);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        pushButton_10 = new QPushButton(page_2);
        pushButton_10->setObjectName(QStringLiteral("pushButton_10"));

        gridLayout_3->addWidget(pushButton_10, 2, 0, 1, 1);

        pushButton_9 = new QPushButton(page_2);
        pushButton_9->setObjectName(QStringLiteral("pushButton_9"));

        gridLayout_3->addWidget(pushButton_9, 2, 1, 1, 1);

        label_5 = new QLabel(page_2);
        label_5->setObjectName(QStringLiteral("label_5"));

        gridLayout_3->addWidget(label_5, 1, 0, 1, 2, Qt::AlignHCenter);

        toolBox->addItem(page_2, QString::fromUtf8("\350\207\252\345\256\232\344\271\211\344\270\273\351\242\230"));
        tabWidget->addTab(tab_2, QString());
        stackedWidget->addWidget(page_5);
        page_6 = new QWidget();
        page_6->setObjectName(QStringLiteral("page_6"));
        stackedWidget->addWidget(page_6);
        page_3 = new QWidget();
        page_3->setObjectName(QStringLiteral("page_3"));
        stackedWidget->addWidget(page_3);

        verticalLayout_2->addWidget(stackedWidget);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(-1, 10, -1, -1);
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        pushButton_7 = new QPushButton(SettingView);
        pushButton_7->setObjectName(QStringLiteral("pushButton_7"));
        pushButton_7->setMinimumSize(QSize(60, 30));
        pushButton_7->setMaximumSize(QSize(50, 16777215));
        pushButton_7->setStyleSheet(QLatin1String("QPushButton {\n"
"  padding: 4px;\n"
"  color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #4c98fe, stop: 1 #0564e3);\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"  color: rgba(255, 255, 255, 90%);\n"
"  border-color: #396895;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"  background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #4c98fe, stop: 1 #0564e3);\n"
"  border-top-color: #247fff;\n"
"  border-bottom-color: #003ddb;\n"
"  border-left-color: #125eed;\n"
"  border-right-color: #125eed;\n"
"}"));

        horizontalLayout_2->addWidget(pushButton_7);

        CancelButton = new QPushButton(SettingView);
        CancelButton->setObjectName(QStringLiteral("CancelButton"));
        CancelButton->setMinimumSize(QSize(60, 30));
        CancelButton->setMaximumSize(QSize(50, 16777215));
        CancelButton->setStyleSheet(QLatin1String("QPushButton#CancelButton {\n"
"  padding: 4px;\n"
"  color: #e51c32;\n"
"}\n"
"\n"
"QPushButton:hover#CancelButton {\n"
"  color: rgba(255, 255, 255, 90%);\n"
"  border-color: #396895;\n"
"}\n"
"\n"
"QPushButton:pressed#CancelButton {\n"
"  background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #4c98fe, stop: 1 #0564e3);\n"
"  border-top-color: #247fff;\n"
"  border-bottom-color: #003ddb;\n"
"  border-left-color: #125eed;\n"
"  border-right-color: #125eed;\n"
"}"));

        horizontalLayout_2->addWidget(CancelButton);


        verticalLayout_2->addLayout(horizontalLayout_2);


        horizontalLayout->addLayout(verticalLayout_2);


        horizontalLayout_3->addLayout(horizontalLayout);


        retranslateUi(SettingView);
        QObject::connect(CancelButton, SIGNAL(clicked()), SettingView, SLOT(close()));

        stackedWidget->setCurrentIndex(1);
        tabWidget->setCurrentIndex(0);
        toolBox->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(SettingView);
    } // setupUi

    void retranslateUi(QWidget *SettingView)
    {
        SettingView->setWindowTitle(QApplication::translate("SettingView", "SettingView", nullptr));
        label->setText(QApplication::translate("SettingView", "\350\256\276\347\275\256", nullptr));
        pushButton_3->setText(QApplication::translate("SettingView", "\347\225\214\351\235\242\350\256\276\347\275\256", nullptr));
        pushButton_4->setText(QApplication::translate("SettingView", "\346\255\214\350\257\215", nullptr));
        pushButton->setText(QApplication::translate("SettingView", "\345\277\253\346\215\267\351\224\256", nullptr));
        pushButton_2->setText(QApplication::translate("SettingView", "\351\237\263\351\242\221\350\256\276\345\244\207", nullptr));
        pushButton_5->setText(QApplication::translate("SettingView", "\345\201\217\345\245\275\350\256\276\347\275\256", nullptr));
        label_2->setText(QApplication::translate("SettingView", "\351\242\234\350\211\262", nullptr));
        label_4->setText(QApplication::translate("SettingView", "\345\255\227\344\275\223", nullptr));
        pushButton_6->setText(QApplication::translate("SettingView", "\351\200\217\346\230\216", nullptr));
        label_3->setText(QApplication::translate("SettingView", "\350\257\255\350\250\200", nullptr));
        pushButton_8->setText(QApplication::translate("SettingView", "\351\207\215\347\275\256", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("SettingView", "\345\270\270\350\247\204\347\225\214\351\235\242", nullptr));
        radioButton_2->setText(QApplication::translate("SettingView", "\346\234\200\345\260\217\345\214\226\345\210\260\346\211\230\347\233\230", nullptr));
        radioButton->setText(QApplication::translate("SettingView", "\351\200\200\345\207\272\347\250\213\345\272\217", nullptr));
        toolBox->setItemText(toolBox->indexOf(page), QApplication::translate("SettingView", "\345\205\263\351\227\255\344\270\273\351\235\242\346\235\277", nullptr));
        pushButton_10->setText(QApplication::translate("SettingView", "\345\257\274\345\205\245", nullptr));
        pushButton_9->setText(QApplication::translate("SettingView", "\351\207\215\347\275\256", nullptr));
        label_5->setText(QApplication::translate("SettingView", "Default", nullptr));
        toolBox->setItemText(toolBox->indexOf(page_2), QApplication::translate("SettingView", "\350\207\252\345\256\232\344\271\211\344\270\273\351\242\230", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("SettingView", "\351\253\230\347\272\247\350\256\276\347\275\256", nullptr));
        pushButton_7->setText(QApplication::translate("SettingView", "\345\272\224\347\224\250", nullptr));
        CancelButton->setText(QApplication::translate("SettingView", "\345\217\226\346\266\210", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SettingView: public Ui_SettingView {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETTINGVIEW_H
