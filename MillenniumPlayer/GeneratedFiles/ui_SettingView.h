/********************************************************************************
** Form generated from reading UI file 'SettingView.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETTINGVIEW_H
#define UI_SETTINGVIEW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFontComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
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
    QPushButton *btn_interface_setting;
    QPushButton *btn_lyric_setting;
    QPushButton *btn_shortcut_key_setting;
    QPushButton *btn_device_setting;
    QPushButton *pushButton_5;
    QSpacerItem *verticalSpacer;
    QVBoxLayout *verticalLayout_2;
    QStackedWidget *stackedWidget;
    QWidget *widget_interface_setting;
    QTabWidget *tabWidget;
    QWidget *tab;
    QGridLayout *gridLayout_2;
    QGridLayout *gridLayout;
    QLabel *label_2;
    QLabel *label_4;
    QPushButton *pushButton_6;
    QComboBox *comboBox;
    QLabel *label_3;
    QPushButton *pushButton_8;
    QFontComboBox *fontComboBox;
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
    QWidget *widget_lyric_setting;
    QWidget *verticalLayoutWidget_3;
    QVBoxLayout *layout_for_widget_lyric_setting;
    QCheckBox *checkBox;
    QSpacerItem *verticalSpacer_3;
    QVBoxLayout *verticalLayout_5;
    QLabel *label_6;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *pushButton_4;
    QPushButton *pushButton_3;
    QSpacerItem *horizontalSpacer_2;
    QVBoxLayout *verticalLayout_6;
    QSpacerItem *horizontalSpacer_4;
    QLabel *label_7;
    QHBoxLayout *horizontalLayout_5;
    QFontComboBox *fontComboBox_2;
    QComboBox *comboBox_3;
    QSpacerItem *horizontalSpacer_3;
    QSpacerItem *verticalSpacer_4;
    QWidget *widget_shortcut_key_setting;
    QWidget *gridLayoutWidget;
    QGridLayout *layout_for_widget_shortcut_key_setting;
    QPushButton *pushButton_14;
    QLabel *label_8;
    QPushButton *pushButton_11;
    QLabel *label_12;
    QLabel *label_11;
    QPushButton *pushButton_13;
    QPushButton *pushButton_15;
    QLabel *label_10;
    QLabel *label_9;
    QPushButton *pushButton_12;
    QSpacerItem *horizontalSpacer_5;
    QSpacerItem *horizontalSpacer_6;
    QWidget *widget_device_setting;
    QWidget *horizontalLayoutWidget_3;
    QHBoxLayout *layout_for_widget_device_setting;
    QLabel *label_13;
    QSpacerItem *horizontalSpacer_8;
    QComboBox *comboBox_2;
    QSpacerItem *horizontalSpacer_7;
    QWidget *page_5;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_7;
    QPushButton *CancelButton;

    void setupUi(QWidget *SettingView)
    {
        if (SettingView->objectName().isEmpty())
            SettingView->setObjectName(QString::fromUtf8("SettingView"));
        SettingView->resize(769, 404);
        SettingView->setStyleSheet(QString::fromUtf8("QWidget{\n"
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
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(3);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(4);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        label = new QLabel(SettingView);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMaximumSize(QSize(16777215, 50));
        QFont font;
        font.setFamily(QString::fromUtf8(".\350\220\215\346\226\271-\347\256\200"));
        font.setPointSize(30);
        label->setFont(font);
        label->setStyleSheet(QString::fromUtf8("color: rgba(0, 0, 0, 95);"));
        label->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);

        verticalLayout->addWidget(label);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout->addItem(verticalSpacer_2);

        btn_interface_setting = new QPushButton(SettingView);
        btn_interface_setting->setObjectName(QString::fromUtf8("btn_interface_setting"));
        btn_interface_setting->setMinimumSize(QSize(120, 40));
        btn_interface_setting->setMaximumSize(QSize(120, 40));

        verticalLayout->addWidget(btn_interface_setting);

        btn_lyric_setting = new QPushButton(SettingView);
        btn_lyric_setting->setObjectName(QString::fromUtf8("btn_lyric_setting"));
        btn_lyric_setting->setMinimumSize(QSize(0, 40));
        btn_lyric_setting->setMaximumSize(QSize(120, 40));

        verticalLayout->addWidget(btn_lyric_setting);

        btn_shortcut_key_setting = new QPushButton(SettingView);
        btn_shortcut_key_setting->setObjectName(QString::fromUtf8("btn_shortcut_key_setting"));
        btn_shortcut_key_setting->setMinimumSize(QSize(0, 40));
        btn_shortcut_key_setting->setMaximumSize(QSize(120, 40));

        verticalLayout->addWidget(btn_shortcut_key_setting);

        btn_device_setting = new QPushButton(SettingView);
        btn_device_setting->setObjectName(QString::fromUtf8("btn_device_setting"));
        btn_device_setting->setMinimumSize(QSize(0, 40));
        btn_device_setting->setMaximumSize(QSize(120, 40));

        verticalLayout->addWidget(btn_device_setting);

        pushButton_5 = new QPushButton(SettingView);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));
        pushButton_5->setMinimumSize(QSize(0, 40));
        pushButton_5->setMaximumSize(QSize(120, 40));

        verticalLayout->addWidget(pushButton_5);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        horizontalLayout->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(5, 50, 5, 0);
        stackedWidget = new QStackedWidget(SettingView);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        widget_interface_setting = new QWidget();
        widget_interface_setting->setObjectName(QString::fromUtf8("widget_interface_setting"));
        tabWidget = new QTabWidget(widget_interface_setting);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setGeometry(QRect(140, 40, 341, 241));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        gridLayout_2 = new QGridLayout(tab);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label_2 = new QLabel(tab);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 0, 0, 1, 1);

        label_4 = new QLabel(tab);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 2, 0, 1, 1);

        pushButton_6 = new QPushButton(tab);
        pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));

        gridLayout->addWidget(pushButton_6, 0, 1, 1, 1);

        comboBox = new QComboBox(tab);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));

        gridLayout->addWidget(comboBox, 1, 1, 1, 1);

        label_3 = new QLabel(tab);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 1, 0, 1, 1);

        pushButton_8 = new QPushButton(tab);
        pushButton_8->setObjectName(QString::fromUtf8("pushButton_8"));

        gridLayout->addWidget(pushButton_8, 3, 1, 1, 1);

        fontComboBox = new QFontComboBox(tab);
        fontComboBox->setObjectName(QString::fromUtf8("fontComboBox"));

        gridLayout->addWidget(fontComboBox, 2, 1, 1, 1);


        gridLayout_2->addLayout(gridLayout, 0, 0, 1, 1);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        toolBox = new QToolBox(tab_2);
        toolBox->setObjectName(QString::fromUtf8("toolBox"));
        toolBox->setGeometry(QRect(50, 40, 221, 121));
        page = new QWidget();
        page->setObjectName(QString::fromUtf8("page"));
        page->setGeometry(QRect(0, 0, 221, 69));
        verticalLayout_4 = new QVBoxLayout(page);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        radioButton_2 = new QRadioButton(page);
        radioButton_2->setObjectName(QString::fromUtf8("radioButton_2"));

        verticalLayout_3->addWidget(radioButton_2);

        radioButton = new QRadioButton(page);
        radioButton->setObjectName(QString::fromUtf8("radioButton"));
        radioButton->setChecked(true);

        verticalLayout_3->addWidget(radioButton);


        verticalLayout_4->addLayout(verticalLayout_3);

        toolBox->addItem(page, QString::fromUtf8("\345\205\263\351\227\255\344\270\273\351\235\242\346\235\277"));
        page_2 = new QWidget();
        page_2->setObjectName(QString::fromUtf8("page_2"));
        page_2->setGeometry(QRect(0, 0, 221, 69));
        gridLayout_3 = new QGridLayout(page_2);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        pushButton_10 = new QPushButton(page_2);
        pushButton_10->setObjectName(QString::fromUtf8("pushButton_10"));

        gridLayout_3->addWidget(pushButton_10, 2, 0, 1, 1);

        pushButton_9 = new QPushButton(page_2);
        pushButton_9->setObjectName(QString::fromUtf8("pushButton_9"));

        gridLayout_3->addWidget(pushButton_9, 2, 1, 1, 1);

        label_5 = new QLabel(page_2);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout_3->addWidget(label_5, 1, 0, 1, 2, Qt::AlignHCenter);

        toolBox->addItem(page_2, QString::fromUtf8("\350\207\252\345\256\232\344\271\211\344\270\273\351\242\230"));
        tabWidget->addTab(tab_2, QString());
        stackedWidget->addWidget(widget_interface_setting);
        widget_lyric_setting = new QWidget();
        widget_lyric_setting->setObjectName(QString::fromUtf8("widget_lyric_setting"));
        verticalLayoutWidget_3 = new QWidget(widget_lyric_setting);
        verticalLayoutWidget_3->setObjectName(QString::fromUtf8("verticalLayoutWidget_3"));
        verticalLayoutWidget_3->setGeometry(QRect(50, 40, 388, 211));
        layout_for_widget_lyric_setting = new QVBoxLayout(verticalLayoutWidget_3);
        layout_for_widget_lyric_setting->setSpacing(6);
        layout_for_widget_lyric_setting->setContentsMargins(11, 11, 11, 11);
        layout_for_widget_lyric_setting->setObjectName(QString::fromUtf8("layout_for_widget_lyric_setting"));
        layout_for_widget_lyric_setting->setContentsMargins(20, 20, 20, 20);
        checkBox = new QCheckBox(verticalLayoutWidget_3);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));

        layout_for_widget_lyric_setting->addWidget(checkBox);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        layout_for_widget_lyric_setting->addItem(verticalSpacer_3);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        label_6 = new QLabel(verticalLayoutWidget_3);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        verticalLayout_5->addWidget(label_6);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        pushButton_4 = new QPushButton(verticalLayoutWidget_3);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));

        horizontalLayout_4->addWidget(pushButton_4);

        pushButton_3 = new QPushButton(verticalLayoutWidget_3);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));

        horizontalLayout_4->addWidget(pushButton_3);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_2);


        verticalLayout_5->addLayout(horizontalLayout_4);

        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout_6->addItem(horizontalSpacer_4);

        label_7 = new QLabel(verticalLayoutWidget_3);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        verticalLayout_6->addWidget(label_7);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        fontComboBox_2 = new QFontComboBox(verticalLayoutWidget_3);
        fontComboBox_2->setObjectName(QString::fromUtf8("fontComboBox_2"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(fontComboBox_2->sizePolicy().hasHeightForWidth());
        fontComboBox_2->setSizePolicy(sizePolicy);
        fontComboBox_2->setMaximumSize(QSize(80, 16777215));

        horizontalLayout_5->addWidget(fontComboBox_2);

        comboBox_3 = new QComboBox(verticalLayoutWidget_3);
        comboBox_3->setObjectName(QString::fromUtf8("comboBox_3"));

        horizontalLayout_5->addWidget(comboBox_3);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_3);


        verticalLayout_6->addLayout(horizontalLayout_5);


        verticalLayout_5->addLayout(verticalLayout_6);


        layout_for_widget_lyric_setting->addLayout(verticalLayout_5);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        layout_for_widget_lyric_setting->addItem(verticalSpacer_4);

        stackedWidget->addWidget(widget_lyric_setting);
        widget_shortcut_key_setting = new QWidget();
        widget_shortcut_key_setting->setObjectName(QString::fromUtf8("widget_shortcut_key_setting"));
        gridLayoutWidget = new QWidget(widget_shortcut_key_setting);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(60, 40, 501, 241));
        layout_for_widget_shortcut_key_setting = new QGridLayout(gridLayoutWidget);
        layout_for_widget_shortcut_key_setting->setSpacing(6);
        layout_for_widget_shortcut_key_setting->setContentsMargins(11, 11, 11, 11);
        layout_for_widget_shortcut_key_setting->setObjectName(QString::fromUtf8("layout_for_widget_shortcut_key_setting"));
        layout_for_widget_shortcut_key_setting->setContentsMargins(0, 0, 0, 0);
        pushButton_14 = new QPushButton(gridLayoutWidget);
        pushButton_14->setObjectName(QString::fromUtf8("pushButton_14"));

        layout_for_widget_shortcut_key_setting->addWidget(pushButton_14, 3, 2, 1, 1);

        label_8 = new QLabel(gridLayoutWidget);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        layout_for_widget_shortcut_key_setting->addWidget(label_8, 4, 1, 1, 1);

        pushButton_11 = new QPushButton(gridLayoutWidget);
        pushButton_11->setObjectName(QString::fromUtf8("pushButton_11"));

        layout_for_widget_shortcut_key_setting->addWidget(pushButton_11, 0, 2, 1, 1);

        label_12 = new QLabel(gridLayoutWidget);
        label_12->setObjectName(QString::fromUtf8("label_12"));

        layout_for_widget_shortcut_key_setting->addWidget(label_12, 3, 1, 1, 1);

        label_11 = new QLabel(gridLayoutWidget);
        label_11->setObjectName(QString::fromUtf8("label_11"));

        layout_for_widget_shortcut_key_setting->addWidget(label_11, 2, 1, 1, 1);

        pushButton_13 = new QPushButton(gridLayoutWidget);
        pushButton_13->setObjectName(QString::fromUtf8("pushButton_13"));

        layout_for_widget_shortcut_key_setting->addWidget(pushButton_13, 2, 2, 1, 1);

        pushButton_15 = new QPushButton(gridLayoutWidget);
        pushButton_15->setObjectName(QString::fromUtf8("pushButton_15"));

        layout_for_widget_shortcut_key_setting->addWidget(pushButton_15, 4, 2, 1, 1);

        label_10 = new QLabel(gridLayoutWidget);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        layout_for_widget_shortcut_key_setting->addWidget(label_10, 1, 1, 1, 1);

        label_9 = new QLabel(gridLayoutWidget);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        layout_for_widget_shortcut_key_setting->addWidget(label_9, 0, 1, 1, 1);

        pushButton_12 = new QPushButton(gridLayoutWidget);
        pushButton_12->setObjectName(QString::fromUtf8("pushButton_12"));

        layout_for_widget_shortcut_key_setting->addWidget(pushButton_12, 1, 2, 1, 1);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        layout_for_widget_shortcut_key_setting->addItem(horizontalSpacer_5, 0, 0, 1, 1);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        layout_for_widget_shortcut_key_setting->addItem(horizontalSpacer_6, 0, 3, 1, 1);

        stackedWidget->addWidget(widget_shortcut_key_setting);
        widget_device_setting = new QWidget();
        widget_device_setting->setObjectName(QString::fromUtf8("widget_device_setting"));
        horizontalLayoutWidget_3 = new QWidget(widget_device_setting);
        horizontalLayoutWidget_3->setObjectName(QString::fromUtf8("horizontalLayoutWidget_3"));
        horizontalLayoutWidget_3->setGeometry(QRect(100, 120, 379, 220));
        layout_for_widget_device_setting = new QHBoxLayout(horizontalLayoutWidget_3);
        layout_for_widget_device_setting->setSpacing(6);
        layout_for_widget_device_setting->setContentsMargins(11, 11, 11, 11);
        layout_for_widget_device_setting->setObjectName(QString::fromUtf8("layout_for_widget_device_setting"));
        layout_for_widget_device_setting->setContentsMargins(100, 100, 100, 100);
        label_13 = new QLabel(horizontalLayoutWidget_3);
        label_13->setObjectName(QString::fromUtf8("label_13"));

        layout_for_widget_device_setting->addWidget(label_13);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        layout_for_widget_device_setting->addItem(horizontalSpacer_8);

        comboBox_2 = new QComboBox(horizontalLayoutWidget_3);
        comboBox_2->setObjectName(QString::fromUtf8("comboBox_2"));

        layout_for_widget_device_setting->addWidget(comboBox_2);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        layout_for_widget_device_setting->addItem(horizontalSpacer_7);

        stackedWidget->addWidget(widget_device_setting);
        page_5 = new QWidget();
        page_5->setObjectName(QString::fromUtf8("page_5"));
        stackedWidget->addWidget(page_5);

        verticalLayout_2->addWidget(stackedWidget);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(-1, 10, -1, -1);
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        pushButton_7 = new QPushButton(SettingView);
        pushButton_7->setObjectName(QString::fromUtf8("pushButton_7"));
        pushButton_7->setMinimumSize(QSize(60, 30));
        pushButton_7->setMaximumSize(QSize(50, 16777215));
        pushButton_7->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        CancelButton->setObjectName(QString::fromUtf8("CancelButton"));
        CancelButton->setMinimumSize(QSize(60, 30));
        CancelButton->setMaximumSize(QSize(50, 16777215));
        CancelButton->setStyleSheet(QString::fromUtf8("QPushButton#CancelButton {\n"
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

        stackedWidget->setCurrentIndex(2);
        tabWidget->setCurrentIndex(0);
        toolBox->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(SettingView);
    } // setupUi

    void retranslateUi(QWidget *SettingView)
    {
        SettingView->setWindowTitle(QCoreApplication::translate("SettingView", "SettingView", nullptr));
        label->setText(QCoreApplication::translate("SettingView", "\350\256\276\347\275\256", nullptr));
        btn_interface_setting->setText(QCoreApplication::translate("SettingView", "\347\225\214\351\235\242\350\256\276\347\275\256", nullptr));
        btn_lyric_setting->setText(QCoreApplication::translate("SettingView", "\346\255\214\350\257\215", nullptr));
        btn_shortcut_key_setting->setText(QCoreApplication::translate("SettingView", "\345\277\253\346\215\267\351\224\256", nullptr));
        btn_device_setting->setText(QCoreApplication::translate("SettingView", "\351\237\263\351\242\221\350\256\276\345\244\207", nullptr));
        pushButton_5->setText(QCoreApplication::translate("SettingView", "\345\201\217\345\245\275\350\256\276\347\275\256", nullptr));
        label_2->setText(QCoreApplication::translate("SettingView", "\351\242\234\350\211\262", nullptr));
        label_4->setText(QCoreApplication::translate("SettingView", "\345\255\227\344\275\223", nullptr));
        pushButton_6->setText(QCoreApplication::translate("SettingView", "\351\200\217\346\230\216", nullptr));
        label_3->setText(QCoreApplication::translate("SettingView", "\350\257\255\350\250\200", nullptr));
        pushButton_8->setText(QCoreApplication::translate("SettingView", "\351\207\215\347\275\256", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("SettingView", "\345\270\270\350\247\204\347\225\214\351\235\242", nullptr));
        radioButton_2->setText(QCoreApplication::translate("SettingView", "\346\234\200\345\260\217\345\214\226\345\210\260\346\211\230\347\233\230", nullptr));
        radioButton->setText(QCoreApplication::translate("SettingView", "\351\200\200\345\207\272\347\250\213\345\272\217", nullptr));
        toolBox->setItemText(toolBox->indexOf(page), QCoreApplication::translate("SettingView", "\345\205\263\351\227\255\344\270\273\351\235\242\346\235\277", nullptr));
        pushButton_10->setText(QCoreApplication::translate("SettingView", "\345\257\274\345\205\245", nullptr));
        pushButton_9->setText(QCoreApplication::translate("SettingView", "\351\207\215\347\275\256", nullptr));
        label_5->setText(QCoreApplication::translate("SettingView", "Default", nullptr));
        toolBox->setItemText(toolBox->indexOf(page_2), QCoreApplication::translate("SettingView", "\350\207\252\345\256\232\344\271\211\344\270\273\351\242\230", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("SettingView", "\351\253\230\347\272\247\350\256\276\347\275\256", nullptr));
        checkBox->setText(QCoreApplication::translate("SettingView", "\346\230\257\345\220\246\345\220\257\347\224\250\346\241\214\351\235\242\346\255\214\350\257\215", nullptr));
        label_6->setText(QCoreApplication::translate("SettingView", "\351\205\215\350\211\262\346\226\271\346\241\210", nullptr));
        pushButton_4->setText(QCoreApplication::translate("SettingView", "\346\234\252\346\222\255\346\224\276", nullptr));
        pushButton_3->setText(QCoreApplication::translate("SettingView", "\345\267\262\346\222\255\346\224\276", nullptr));
        label_7->setText(QCoreApplication::translate("SettingView", "\345\255\227\344\275\223\346\226\271\346\241\210", nullptr));
        pushButton_14->setText(QCoreApplication::translate("SettingView", "Ctrl + Up", nullptr));
        label_8->setText(QCoreApplication::translate("SettingView", "\351\237\263\351\207\217\345\207\217", nullptr));
        pushButton_11->setText(QCoreApplication::translate("SettingView", "Space", nullptr));
        label_12->setText(QCoreApplication::translate("SettingView", "\351\237\263\351\207\217\345\212\240", nullptr));
        label_11->setText(QCoreApplication::translate("SettingView", "\344\270\213\344\270\200\351\246\226", nullptr));
        pushButton_13->setText(QCoreApplication::translate("SettingView", "Ctrl + R", nullptr));
        pushButton_15->setText(QCoreApplication::translate("SettingView", "Ctrl + Down", nullptr));
        label_10->setText(QCoreApplication::translate("SettingView", "\344\270\212\344\270\200\351\246\226", nullptr));
        label_9->setText(QCoreApplication::translate("SettingView", "\346\222\255\346\224\276/\346\232\202\345\201\234", nullptr));
        pushButton_12->setText(QCoreApplication::translate("SettingView", "Ctrl + L", nullptr));
        label_13->setText(QCoreApplication::translate("SettingView", "\350\276\223\345\207\272\350\256\276\345\244\207", nullptr));
        pushButton_7->setText(QCoreApplication::translate("SettingView", "\345\272\224\347\224\250", nullptr));
        CancelButton->setText(QCoreApplication::translate("SettingView", "\345\217\226\346\266\210", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SettingView: public Ui_SettingView {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETTINGVIEW_H
