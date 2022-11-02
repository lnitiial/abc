/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QWidget *widget;
    QGridLayout *gridLayout_2;
    QLabel *label_01;
    QLabel *label_22;
    QLabel *label_12;
    QLabel *label_21;
    QLabel *label_02;
    QLabel *label_13;
    QLabel *label_33;
    QLabel *label_23;
    QLabel *label_20;
    QLabel *label_00;
    QLabel *label_31;
    QLabel *label_32;
    QLabel *label_11;
    QLabel *label_30;
    QLabel *label_10;
    QLabel *label_03;
    QLabel *label_17;
    QLabel *label_18;
    QLabel *label_19;
    QPushButton *pushButton;
    QTextBrowser *textBrowser;
    QTextBrowser *textBrowser_2;
    QLabel *label_3;
    QLabel *label_2;
    QLabel *label_score;
    QLabel *label_best;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QStringLiteral("Widget"));
        Widget->resize(826, 868);
        QFont font;
        font.setFamily(QStringLiteral("Fog Sans"));
        font.setPointSize(13);
        Widget->setFont(font);
        Widget->setStyleSheet(QStringLiteral("background-color: rgb(250, 248, 239);"));
        widget = new QWidget(Widget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(130, 190, 563, 563));
        QFont font1;
        font1.setFamily(QStringLiteral("Fog Sans"));
        font1.setPointSize(39);
        font1.setBold(true);
        font1.setWeight(75);
        widget->setFont(font1);
        widget->setStyleSheet(QLatin1String("background-color: rgb(187, 173, 160);\n"
"border-radius:  7px;"));
        gridLayout_2 = new QGridLayout(widget);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        label_01 = new QLabel(widget);
        label_01->setObjectName(QStringLiteral("label_01"));
        label_01->setMaximumSize(QSize(122, 122));
        label_01->setFont(font1);
        label_01->setStyleSheet(QStringLiteral("background-color: rgb(205, 193, 180);"));
        label_01->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(label_01, 0, 1, 1, 1);

        label_22 = new QLabel(widget);
        label_22->setObjectName(QStringLiteral("label_22"));
        label_22->setMaximumSize(QSize(122, 122));
        label_22->setFont(font1);
        label_22->setStyleSheet(QStringLiteral("background-color: rgb(205, 193, 180);"));
        label_22->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(label_22, 2, 2, 1, 1);

        label_12 = new QLabel(widget);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setMaximumSize(QSize(122, 122));
        label_12->setFont(font1);
        label_12->setStyleSheet(QStringLiteral("background-color: rgb(205, 193, 180);"));
        label_12->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(label_12, 1, 2, 1, 1);

        label_21 = new QLabel(widget);
        label_21->setObjectName(QStringLiteral("label_21"));
        label_21->setMaximumSize(QSize(122, 122));
        label_21->setFont(font1);
        label_21->setStyleSheet(QStringLiteral("background-color: rgb(205, 193, 180);"));
        label_21->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(label_21, 2, 1, 1, 1);

        label_02 = new QLabel(widget);
        label_02->setObjectName(QStringLiteral("label_02"));
        label_02->setMaximumSize(QSize(122, 122));
        label_02->setFont(font1);
        label_02->setStyleSheet(QStringLiteral("background-color: rgb(205, 193, 180);"));
        label_02->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(label_02, 0, 2, 1, 1);

        label_13 = new QLabel(widget);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setMaximumSize(QSize(122, 122));
        QFont font2;
        font2.setFamily(QStringLiteral("Fog Sans"));
        font2.setPointSize(38);
        font2.setBold(true);
        font2.setWeight(75);
        label_13->setFont(font2);
        label_13->setStyleSheet(QStringLiteral("background-color: rgb(205, 193, 180);"));
        label_13->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(label_13, 1, 3, 1, 1);

        label_33 = new QLabel(widget);
        label_33->setObjectName(QStringLiteral("label_33"));
        label_33->setMaximumSize(QSize(122, 122));
        label_33->setFont(font1);
        label_33->setStyleSheet(QStringLiteral("background-color: rgb(205, 193, 180);"));
        label_33->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(label_33, 3, 3, 1, 1);

        label_23 = new QLabel(widget);
        label_23->setObjectName(QStringLiteral("label_23"));
        label_23->setMaximumSize(QSize(122, 122));
        label_23->setFont(font1);
        label_23->setStyleSheet(QStringLiteral("background-color: rgb(205, 193, 180);"));
        label_23->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(label_23, 2, 3, 1, 1);

        label_20 = new QLabel(widget);
        label_20->setObjectName(QStringLiteral("label_20"));
        label_20->setMaximumSize(QSize(122, 122));
        label_20->setFont(font1);
        label_20->setStyleSheet(QStringLiteral("background-color: rgb(205, 193, 180);"));
        label_20->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(label_20, 2, 0, 1, 1);

        label_00 = new QLabel(widget);
        label_00->setObjectName(QStringLiteral("label_00"));
        label_00->setMaximumSize(QSize(122, 122));
        label_00->setFont(font1);
        label_00->setStyleSheet(QLatin1String("QLabel\n"
"{\n"
"	background-color: rgb(205, 193, 180);\n"
"}\n"
""));
        label_00->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(label_00, 0, 0, 1, 1);

        label_31 = new QLabel(widget);
        label_31->setObjectName(QStringLiteral("label_31"));
        label_31->setMaximumSize(QSize(122, 122));
        label_31->setFont(font1);
        label_31->setStyleSheet(QStringLiteral("background-color: rgb(205, 193, 180);"));
        label_31->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(label_31, 3, 1, 1, 1);

        label_32 = new QLabel(widget);
        label_32->setObjectName(QStringLiteral("label_32"));
        label_32->setMaximumSize(QSize(122, 122));
        label_32->setFont(font1);
        label_32->setStyleSheet(QStringLiteral("background-color: rgb(205, 193, 180);"));
        label_32->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(label_32, 3, 2, 1, 1);

        label_11 = new QLabel(widget);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setMaximumSize(QSize(122, 122));
        label_11->setFont(font1);
        label_11->setStyleSheet(QStringLiteral("background-color: rgb(205, 193, 180);"));
        label_11->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(label_11, 1, 1, 1, 1);

        label_30 = new QLabel(widget);
        label_30->setObjectName(QStringLiteral("label_30"));
        label_30->setMaximumSize(QSize(122, 122));
        label_30->setFont(font1);
        label_30->setStyleSheet(QStringLiteral("background-color: rgb(205, 193, 180);"));
        label_30->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(label_30, 3, 0, 1, 1);

        label_10 = new QLabel(widget);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setEnabled(true);
        label_10->setMaximumSize(QSize(122, 122));
        label_10->setFont(font1);
        label_10->setStyleSheet(QStringLiteral("background-color: rgb(205, 193, 180);"));
        label_10->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(label_10, 1, 0, 1, 1);

        label_03 = new QLabel(widget);
        label_03->setObjectName(QStringLiteral("label_03"));
        label_03->setMaximumSize(QSize(122, 122));
        label_03->setFont(font1);
        label_03->setStyleSheet(QStringLiteral("background-color: rgb(205, 193, 180);"));
        label_03->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(label_03, 0, 3, 1, 1);

        label_17 = new QLabel(Widget);
        label_17->setObjectName(QStringLiteral("label_17"));
        label_17->setGeometry(QRect(130, 0, 271, 91));
        QFont font3;
        font3.setFamily(QStringLiteral("Fog Sans"));
        font3.setPointSize(61);
        font3.setBold(true);
        font3.setWeight(75);
        label_17->setFont(font3);
        label_17->setStyleSheet(QLatin1String("\n"
"color: rgb(119, 110, 101);"));
        label_18 = new QLabel(Widget);
        label_18->setObjectName(QStringLiteral("label_18"));
        label_18->setGeometry(QRect(430, 20, 111, 71));
        QFont font4;
        font4.setFamily(QStringLiteral("Fog Sans"));
        font4.setPointSize(14);
        label_18->setFont(font4);
        label_18->setStyleSheet(QLatin1String("background-color: rgb(187, 173, 160);\n"
"border-radius:  5px;"));
        label_19 = new QLabel(Widget);
        label_19->setObjectName(QStringLiteral("label_19"));
        label_19->setGeometry(QRect(550, 20, 140, 71));
        QFont font5;
        font5.setFamily(QStringLiteral("Fog Sans"));
        label_19->setFont(font5);
        label_19->setStyleSheet(QLatin1String("background-color: rgb(187, 173, 160);\n"
"border-radius:  5px;"));
        pushButton = new QPushButton(Widget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(550, 120, 140, 50));
        QFont font6;
        font6.setFamily(QStringLiteral("Fog Sans"));
        font6.setPointSize(11);
        font6.setBold(true);
        font6.setWeight(75);
        pushButton->setFont(font6);
        pushButton->setFocusPolicy(Qt::NoFocus);
        pushButton->setStyleSheet(QLatin1String("background-color: rgb(143,122,102);\n"
"color: rgb(255, 255, 255);\n"
"border-radius:  5px;"));
        textBrowser = new QTextBrowser(Widget);
        textBrowser->setObjectName(QStringLiteral("textBrowser"));
        textBrowser->setGeometry(QRect(130, 110, 411, 71));
        textBrowser->setFont(font5);
        textBrowser->setFocusPolicy(Qt::NoFocus);
        textBrowser->setStyleSheet(QStringLiteral("color: rgb(119, 110, 101);"));
        textBrowser->setFrameShape(QFrame::NoFrame);
        textBrowser_2 = new QTextBrowser(Widget);
        textBrowser_2->setObjectName(QStringLiteral("textBrowser_2"));
        textBrowser_2->setGeometry(QRect(120, 750, 631, 101));
        QFont font7;
        font7.setPointSize(39);
        textBrowser_2->setFont(font7);
        textBrowser_2->setFocusPolicy(Qt::NoFocus);
        textBrowser_2->setFrameShape(QFrame::NoFrame);
        label_3 = new QLabel(Widget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(450, 20, 61, 31));
        QFont font8;
        font8.setFamily(QStringLiteral("Fog Sans"));
        font8.setPointSize(9);
        font8.setBold(true);
        font8.setWeight(75);
        label_3->setFont(font8);
        label_3->setStyleSheet(QLatin1String("background-color: rgb(187, 173, 160);\n"
"color: rgb(238,228,218);"));
        label_3->setAlignment(Qt::AlignCenter);
        label_2 = new QLabel(Widget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(580, 30, 72, 15));
        label_2->setFont(font8);
        label_2->setStyleSheet(QLatin1String("background-color: rgb(187, 173, 160);\n"
"color: rgb(238,228,218);"));
        label_2->setTextFormat(Qt::PlainText);
        label_2->setAlignment(Qt::AlignCenter);
        label_score = new QLabel(Widget);
        label_score->setObjectName(QStringLiteral("label_score"));
        label_score->setGeometry(QRect(430, 50, 101, 41));
        QFont font9;
        font9.setFamily(QStringLiteral("Fog Sans"));
        font9.setPointSize(20);
        font9.setBold(true);
        font9.setWeight(75);
        label_score->setFont(font9);
        label_score->setStyleSheet(QLatin1String("background-color: rgb(187, 173, 160);\n"
"color: rgb(255,255,255);"));
        label_score->setAlignment(Qt::AlignCenter);
        label_best = new QLabel(Widget);
        label_best->setObjectName(QStringLiteral("label_best"));
        label_best->setGeometry(QRect(570, 50, 101, 41));
        label_best->setFont(font9);
        label_best->setStyleSheet(QLatin1String("background-color: rgb(187, 173, 160);\n"
"color: rgb(255,255,255);"));
        label_best->setAlignment(Qt::AlignCenter);
        widget->raise();
        label_17->raise();
        label_18->raise();
        label_19->raise();
        pushButton->raise();
        textBrowser->raise();
        textBrowser_2->raise();
        label_2->raise();
        label_3->raise();
        label_score->raise();
        label_best->raise();

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Widget", 0));
        label_01->setText(QString());
        label_22->setText(QString());
        label_12->setText(QString());
        label_21->setText(QString());
        label_02->setText(QString());
        label_13->setText(QString());
        label_33->setText(QString());
        label_23->setText(QString());
        label_20->setText(QString());
        label_00->setText(QString());
        label_31->setText(QString());
        label_32->setText(QString());
        label_11->setText(QString());
        label_30->setText(QString());
        label_10->setText(QString());
        label_03->setText(QString());
        label_17->setText(QApplication::translate("Widget", "2048", 0));
        label_18->setText(QString());
        label_19->setText(QString());
        pushButton->setText(QApplication::translate("Widget", "NEW GAME", 0));
        textBrowser->setHtml(QApplication::translate("Widget", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Fog Sans'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'clear sans,helvetica neue,Arial,sans-serif'; font-size:12pt; font-weight:600; color:#776e65; background-color:#faf8ef;\">Play 2048 Game Online</span><span style=\" font-family:'clear sans,helvetica neue,Arial,sans-serif'; font-size:12pt; color:#776e65; background-color:#faf8ef;\">\302\240</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'clear sans,helvetica neue,Arial,sans-serif'; font-size:12pt; color:#776e65; background-"
                        "color:#faf8ef;\">Join the number and getr to the  2048 tiles. </span></p></body></html>", 0));
        textBrowser_2->setHtml(QApplication::translate("Widget", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'SimSun'; font-size:39pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'clear sans,helvetica neue,Arial,sans-serif'; font-size:14pt; font-weight:600; color:#776e65; background-color:#faf8ef; text-transform:uppercase;\">HOW TO PLAY:</span><span style=\" font-family:'clear sans,helvetica neue,Arial,sans-serif'; font-size:14pt; color:#776e65; background-color:#faf8ef;\">\302\240Use your\302\240</span><span style=\" font-family:'clear sans,helvetica neue,Arial,sans-serif'; font-size:14pt; font-weight:600; color:#776e65; background-color:#faf8ef;\">arrow keys</span><span style=\" font-family:'clear sans,helvetic"
                        "a neue,Arial,sans-serif'; font-size:14pt; color:#776e65; background-color:#faf8ef;\">\302\240to move the tiles. </span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'clear sans,helvetica neue,Arial,sans-serif'; font-size:14pt; color:#776e65; background-color:#faf8ef;\">When  two  tiles  with  the  same  number   touch,   they\302\240</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'clear sans,helvetica neue,Arial,sans-serif'; font-size:14pt; font-weight:600; color:#776e65; background-color:#faf8ef;\">merge into one!</span></p></body></html>", 0));
        label_3->setText(QApplication::translate("Widget", "SCORE", 0));
        label_2->setText(QApplication::translate("Widget", "BEST", 0));
        label_score->setText(QApplication::translate("Widget", "2224", 0));
        label_best->setText(QApplication::translate("Widget", "2224", 0));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
