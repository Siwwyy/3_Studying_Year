/********************************************************************************
** Form generated from reading UI file 'calculator.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CALCULATOR_H
#define UI_CALCULATOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Calculator
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QPushButton *Button0;
    QPushButton *MemoryAdd;
    QPushButton *Division;
    QLineEdit *Display;
    QPushButton *Equals;
    QPushButton *Adding;
    QPushButton *Button3;
    QPushButton *Button6;
    QPushButton *Subtraction;
    QPushButton *AC;
    QPushButton *Button2;
    QPushButton *Multiplication;
    QPushButton *Button8;
    QPushButton *Button9;
    QPushButton *Button7;
    QPushButton *MemoryClean;
    QPushButton *Button5;
    QPushButton *Button1;
    QPushButton *Button4;
    QPushButton *ChangeSign;
    QPushButton *MemoryGet;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Calculator)
    {
        if (Calculator->objectName().isEmpty())
            Calculator->setObjectName(QString::fromUtf8("Calculator"));
        Calculator->resize(800, 264);
        Calculator->setStyleSheet(QString::fromUtf8(""));
        centralwidget = new QWidget(Calculator);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        Button0 = new QPushButton(centralwidget);
        Button0->setObjectName(QString::fromUtf8("Button0"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Button0->sizePolicy().hasHeightForWidth());
        Button0->setSizePolicy(sizePolicy);
        QFont font;
        font.setPointSize(14);
        Button0->setFont(font);
        Button0->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"	background-color: #C0C0C0;\n"
"	border: 1px solid gray;\n"
"	padding: 5px;\n"
"}\n"
"\n"
"QPushButton:pressed\n"
"{\n"
"	background-color: #A9A9A9;\n"
"	border: 1px solid gray;\n"
"	padding: 5px;\n"
"}"));

        gridLayout->addWidget(Button0, 4, 1, 1, 1);

        MemoryAdd = new QPushButton(centralwidget);
        MemoryAdd->setObjectName(QString::fromUtf8("MemoryAdd"));
        sizePolicy.setHeightForWidth(MemoryAdd->sizePolicy().hasHeightForWidth());
        MemoryAdd->setSizePolicy(sizePolicy);
        MemoryAdd->setFont(font);
        MemoryAdd->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"	background-color: #FF8C00;\n"
"	border: 1px solid gray;\n"
"	padding: 5px;\n"
"}\n"
"\n"
"QPushButton:pressed\n"
"{\n"
"	background-color: #A9A9A9;\n"
"	border: 1px solid gray;\n"
"	padding: 5px;\n"
"}"));

        gridLayout->addWidget(MemoryAdd, 1, 4, 1, 1);

        Division = new QPushButton(centralwidget);
        Division->setObjectName(QString::fromUtf8("Division"));
        sizePolicy.setHeightForWidth(Division->sizePolicy().hasHeightForWidth());
        Division->setSizePolicy(sizePolicy);
        Division->setFont(font);
        Division->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"	background-color: #FF8C00;\n"
"	border: 1px solid gray;\n"
"	padding: 5px;\n"
"}\n"
"\n"
"QPushButton:pressed\n"
"{\n"
"	background-color: #A9A9A9;\n"
"	border: 1px solid gray;\n"
"	padding: 5px;\n"
"}"));

        gridLayout->addWidget(Division, 1, 3, 1, 1);

        Display = new QLineEdit(centralwidget);
        Display->setObjectName(QString::fromUtf8("Display"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(Display->sizePolicy().hasHeightForWidth());
        Display->setSizePolicy(sizePolicy1);
        QPalette palette;
        QBrush brush(QColor(255, 255, 255, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush1(QColor(128, 128, 128, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette.setBrush(QPalette::Active, QPalette::Light, brush);
        palette.setBrush(QPalette::Active, QPalette::Midlight, brush);
        QBrush brush2(QColor(127, 127, 127, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Dark, brush2);
        QBrush brush3(QColor(170, 170, 170, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Mid, brush3);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        palette.setBrush(QPalette::Active, QPalette::BrightText, brush);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette.setBrush(QPalette::Active, QPalette::Window, brush1);
        QBrush brush4(QColor(0, 0, 0, 255));
        brush4.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Shadow, brush4);
        palette.setBrush(QPalette::Active, QPalette::AlternateBase, brush);
        QBrush brush5(QColor(255, 255, 220, 255));
        brush5.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::ToolTipBase, brush5);
        palette.setBrush(QPalette::Active, QPalette::ToolTipText, brush4);
        QBrush brush6(QColor(0, 0, 0, 128));
        brush6.setStyle(Qt::SolidPattern);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Active, QPalette::PlaceholderText, brush6);
#endif
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Light, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Midlight, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Dark, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::Mid, brush3);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette.setBrush(QPalette::Inactive, QPalette::BrightText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Shadow, brush4);
        palette.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush5);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush4);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush6);
#endif
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Light, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Midlight, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Dark, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Mid, brush3);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush);
        palette.setBrush(QPalette::Disabled, QPalette::BrightText, brush);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Shadow, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush5);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush4);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush6);
#endif
        Display->setPalette(palette);
        QFont font1;
        font1.setFamily(QString::fromUtf8("Arial"));
        font1.setPointSize(28);
        font1.setBold(false);
        font1.setWeight(50);
        Display->setFont(font1);
        Display->setStyleSheet(QString::fromUtf8("QLineEdit\n"
"{\n"
"	background-color: gray;\n"
"	border: 1px solid gray;\n"
"	color: #FFFFFF;\n"
"}"));

        gridLayout->addWidget(Display, 0, 0, 1, 5);

        Equals = new QPushButton(centralwidget);
        Equals->setObjectName(QString::fromUtf8("Equals"));
        sizePolicy.setHeightForWidth(Equals->sizePolicy().hasHeightForWidth());
        Equals->setSizePolicy(sizePolicy);
        Equals->setFont(font);
        Equals->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"	background-color: #FF8C00;\n"
"	border: 1px solid gray;\n"
"	padding: 5px;\n"
"}\n"
"\n"
"QPushButton:pressed\n"
"{\n"
"	background-color: #A9A9A9;\n"
"	border: 1px solid gray;\n"
"	padding: 5px;\n"
"}"));

        gridLayout->addWidget(Equals, 4, 4, 1, 1);

        Adding = new QPushButton(centralwidget);
        Adding->setObjectName(QString::fromUtf8("Adding"));
        sizePolicy.setHeightForWidth(Adding->sizePolicy().hasHeightForWidth());
        Adding->setSizePolicy(sizePolicy);
        Adding->setFont(font);
        Adding->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"	background-color: #FF8C00;\n"
"	border: 1px solid gray;\n"
"	padding: 5px;\n"
"}\n"
"\n"
"QPushButton:pressed\n"
"{\n"
"	background-color: #A9A9A9;\n"
"	border: 1px solid gray;\n"
"	padding: 5px;\n"
"}"));

        gridLayout->addWidget(Adding, 3, 3, 1, 1);

        Button3 = new QPushButton(centralwidget);
        Button3->setObjectName(QString::fromUtf8("Button3"));
        sizePolicy.setHeightForWidth(Button3->sizePolicy().hasHeightForWidth());
        Button3->setSizePolicy(sizePolicy);
        Button3->setFont(font);
        Button3->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"	background-color: #C0C0C0;\n"
"	border: 1px solid gray;\n"
"	padding: 5px;\n"
"}\n"
"\n"
"QPushButton:pressed\n"
"{\n"
"	background-color: #A9A9A9;\n"
"	border: 1px solid gray;\n"
"	padding: 5px;\n"
"}"));

        gridLayout->addWidget(Button3, 3, 2, 1, 1);

        Button6 = new QPushButton(centralwidget);
        Button6->setObjectName(QString::fromUtf8("Button6"));
        sizePolicy.setHeightForWidth(Button6->sizePolicy().hasHeightForWidth());
        Button6->setSizePolicy(sizePolicy);
        Button6->setFont(font);
        Button6->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"	background-color: #C0C0C0;\n"
"	border: 1px solid gray;\n"
"	padding: 5px;\n"
"}\n"
"\n"
"QPushButton:pressed\n"
"{\n"
"	background-color: #A9A9A9;\n"
"	border: 1px solid gray;\n"
"	padding: 5px;\n"
"}"));

        gridLayout->addWidget(Button6, 2, 2, 1, 1);

        Subtraction = new QPushButton(centralwidget);
        Subtraction->setObjectName(QString::fromUtf8("Subtraction"));
        sizePolicy.setHeightForWidth(Subtraction->sizePolicy().hasHeightForWidth());
        Subtraction->setSizePolicy(sizePolicy);
        Subtraction->setFont(font);
        Subtraction->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"	background-color: #FF8C00;\n"
"	border: 1px solid gray;\n"
"	padding: 5px;\n"
"}\n"
"\n"
"QPushButton:pressed\n"
"{\n"
"	background-color: #A9A9A9;\n"
"	border: 1px solid gray;\n"
"	padding: 5px;\n"
"}"));

        gridLayout->addWidget(Subtraction, 4, 3, 1, 1);

        AC = new QPushButton(centralwidget);
        AC->setObjectName(QString::fromUtf8("AC"));
        sizePolicy.setHeightForWidth(AC->sizePolicy().hasHeightForWidth());
        AC->setSizePolicy(sizePolicy);
        AC->setFont(font);
        AC->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"	background-color: #C0C0C0;\n"
"	border: 1px solid gray;\n"
"	padding: 5px;\n"
"}\n"
"\n"
"QPushButton:pressed\n"
"{\n"
"	background-color: #A9A9A9;\n"
"	border: 1px solid gray;\n"
"	padding: 5px;\n"
"}"));

        gridLayout->addWidget(AC, 4, 0, 1, 1);

        Button2 = new QPushButton(centralwidget);
        Button2->setObjectName(QString::fromUtf8("Button2"));
        sizePolicy.setHeightForWidth(Button2->sizePolicy().hasHeightForWidth());
        Button2->setSizePolicy(sizePolicy);
        Button2->setFont(font);
        Button2->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"	background-color: #C0C0C0;\n"
"	border: 1px solid gray;\n"
"	padding: 5px;\n"
"}\n"
"\n"
"QPushButton:pressed\n"
"{\n"
"	background-color: #A9A9A9;\n"
"	border: 1px solid gray;\n"
"	padding: 5px;\n"
"}"));

        gridLayout->addWidget(Button2, 3, 1, 1, 1);

        Multiplication = new QPushButton(centralwidget);
        Multiplication->setObjectName(QString::fromUtf8("Multiplication"));
        sizePolicy.setHeightForWidth(Multiplication->sizePolicy().hasHeightForWidth());
        Multiplication->setSizePolicy(sizePolicy);
        Multiplication->setFont(font);
        Multiplication->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"	background-color: #FF8C00;\n"
"	border: 1px solid gray;\n"
"	padding: 5px;\n"
"}\n"
"\n"
"QPushButton:pressed\n"
"{\n"
"	background-color: #A9A9A9;\n"
"	border: 1px solid gray;\n"
"	padding: 5px;\n"
"}"));

        gridLayout->addWidget(Multiplication, 2, 3, 1, 1);

        Button8 = new QPushButton(centralwidget);
        Button8->setObjectName(QString::fromUtf8("Button8"));
        sizePolicy.setHeightForWidth(Button8->sizePolicy().hasHeightForWidth());
        Button8->setSizePolicy(sizePolicy);
        Button8->setFont(font);
        Button8->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"	background-color: #C0C0C0;\n"
"	border: 1px solid gray;\n"
"	padding: 5px;\n"
"}\n"
"\n"
"QPushButton:pressed\n"
"{\n"
"	background-color: #A9A9A9;\n"
"	border: 1px solid gray;\n"
"	padding: 5px;\n"
"}"));

        gridLayout->addWidget(Button8, 1, 1, 1, 1);

        Button9 = new QPushButton(centralwidget);
        Button9->setObjectName(QString::fromUtf8("Button9"));
        sizePolicy.setHeightForWidth(Button9->sizePolicy().hasHeightForWidth());
        Button9->setSizePolicy(sizePolicy);
        Button9->setFont(font);
        Button9->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"	background-color: #C0C0C0;\n"
"	border: 1px solid gray;\n"
"	padding: 5px;\n"
"}\n"
"\n"
"QPushButton:pressed\n"
"{\n"
"	background-color: #A9A9A9;\n"
"	border: 1px solid gray;\n"
"	padding: 5px;\n"
"}"));

        gridLayout->addWidget(Button9, 1, 2, 1, 1);

        Button7 = new QPushButton(centralwidget);
        Button7->setObjectName(QString::fromUtf8("Button7"));
        sizePolicy.setHeightForWidth(Button7->sizePolicy().hasHeightForWidth());
        Button7->setSizePolicy(sizePolicy);
        Button7->setFont(font);
        Button7->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"	background-color: #C0C0C0;\n"
"	border: 1px solid gray;\n"
"	padding: 5px;\n"
"}\n"
"\n"
"QPushButton:pressed\n"
"{\n"
"	background-color: #A9A9A9;\n"
"	border: 1px solid gray;\n"
"	padding: 5px;\n"
"}"));

        gridLayout->addWidget(Button7, 1, 0, 1, 1);

        MemoryClean = new QPushButton(centralwidget);
        MemoryClean->setObjectName(QString::fromUtf8("MemoryClean"));
        sizePolicy.setHeightForWidth(MemoryClean->sizePolicy().hasHeightForWidth());
        MemoryClean->setSizePolicy(sizePolicy);
        MemoryClean->setFont(font);
        MemoryClean->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"	background-color: #FF8C00;\n"
"	border: 1px solid gray;\n"
"	padding: 5px;\n"
"}\n"
"\n"
"QPushButton:pressed\n"
"{\n"
"	background-color: #A9A9A9;\n"
"	border: 1px solid gray;\n"
"	padding: 5px;\n"
"}"));

        gridLayout->addWidget(MemoryClean, 2, 4, 1, 1);

        Button5 = new QPushButton(centralwidget);
        Button5->setObjectName(QString::fromUtf8("Button5"));
        sizePolicy.setHeightForWidth(Button5->sizePolicy().hasHeightForWidth());
        Button5->setSizePolicy(sizePolicy);
        Button5->setFont(font);
        Button5->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"	background-color: #C0C0C0;\n"
"	border: 1px solid gray;\n"
"	padding: 5px;\n"
"}\n"
"\n"
"QPushButton:pressed\n"
"{\n"
"	background-color: #A9A9A9;\n"
"	border: 1px solid gray;\n"
"	padding: 5px;\n"
"}"));

        gridLayout->addWidget(Button5, 2, 1, 1, 1);

        Button1 = new QPushButton(centralwidget);
        Button1->setObjectName(QString::fromUtf8("Button1"));
        sizePolicy.setHeightForWidth(Button1->sizePolicy().hasHeightForWidth());
        Button1->setSizePolicy(sizePolicy);
        Button1->setFont(font);
        Button1->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"	background-color: #C0C0C0;\n"
"	border: 1px solid gray;\n"
"	padding: 5px;\n"
"}\n"
"\n"
"QPushButton:pressed\n"
"{\n"
"	background-color: #A9A9A9;\n"
"	border: 1px solid gray;\n"
"	padding: 5px;\n"
"}"));

        gridLayout->addWidget(Button1, 3, 0, 1, 1);

        Button4 = new QPushButton(centralwidget);
        Button4->setObjectName(QString::fromUtf8("Button4"));
        sizePolicy.setHeightForWidth(Button4->sizePolicy().hasHeightForWidth());
        Button4->setSizePolicy(sizePolicy);
        Button4->setFont(font);
        Button4->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"	background-color: #C0C0C0;\n"
"	border: 1px solid gray;\n"
"	padding: 5px;\n"
"}\n"
"\n"
"QPushButton:pressed\n"
"{\n"
"	background-color: #A9A9A9;\n"
"	border: 1px solid gray;\n"
"	padding: 5px;\n"
"}"));

        gridLayout->addWidget(Button4, 2, 0, 1, 1);

        ChangeSign = new QPushButton(centralwidget);
        ChangeSign->setObjectName(QString::fromUtf8("ChangeSign"));
        sizePolicy.setHeightForWidth(ChangeSign->sizePolicy().hasHeightForWidth());
        ChangeSign->setSizePolicy(sizePolicy);
        ChangeSign->setFont(font);
        ChangeSign->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"	background-color: #C0C0C0;\n"
"	border: 1px solid gray;\n"
"	padding: 5px;\n"
"}\n"
"\n"
"QPushButton:pressed\n"
"{\n"
"	background-color: #A9A9A9;\n"
"	border: 1px solid gray;\n"
"	padding: 5px;\n"
"}"));

        gridLayout->addWidget(ChangeSign, 4, 2, 1, 1);

        MemoryGet = new QPushButton(centralwidget);
        MemoryGet->setObjectName(QString::fromUtf8("MemoryGet"));
        sizePolicy.setHeightForWidth(MemoryGet->sizePolicy().hasHeightForWidth());
        MemoryGet->setSizePolicy(sizePolicy);
        MemoryGet->setFont(font);
        MemoryGet->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"	background-color: #FF8C00;\n"
"	border: 1px solid gray;\n"
"	padding: 5px;\n"
"}\n"
"\n"
"QPushButton:pressed\n"
"{\n"
"	background-color: #A9A9A9;\n"
"	border: 1px solid gray;\n"
"	padding: 5px;\n"
"}"));

        gridLayout->addWidget(MemoryGet, 3, 4, 1, 1);

        Calculator->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(Calculator);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        Calculator->setStatusBar(statusbar);

        retranslateUi(Calculator);

        QMetaObject::connectSlotsByName(Calculator);
    } // setupUi

    void retranslateUi(QMainWindow *Calculator)
    {
        Calculator->setWindowTitle(QCoreApplication::translate("Calculator", "Calculator", nullptr));
        Button0->setText(QCoreApplication::translate("Calculator", "0", nullptr));
        MemoryAdd->setText(QCoreApplication::translate("Calculator", "M+", nullptr));
        Division->setText(QCoreApplication::translate("Calculator", "/", nullptr));
        Display->setText(QCoreApplication::translate("Calculator", "0.0", nullptr));
        Equals->setText(QCoreApplication::translate("Calculator", "=", nullptr));
        Adding->setText(QCoreApplication::translate("Calculator", "+", nullptr));
        Button3->setText(QCoreApplication::translate("Calculator", "3", nullptr));
        Button6->setText(QCoreApplication::translate("Calculator", "6", nullptr));
        Subtraction->setText(QCoreApplication::translate("Calculator", "-", nullptr));
        AC->setText(QCoreApplication::translate("Calculator", "AC", nullptr));
        Button2->setText(QCoreApplication::translate("Calculator", "2", nullptr));
        Multiplication->setText(QCoreApplication::translate("Calculator", "*", nullptr));
        Button8->setText(QCoreApplication::translate("Calculator", "8", nullptr));
        Button9->setText(QCoreApplication::translate("Calculator", "9", nullptr));
        Button7->setText(QCoreApplication::translate("Calculator", "7", nullptr));
        MemoryClean->setText(QCoreApplication::translate("Calculator", "M-", nullptr));
        Button5->setText(QCoreApplication::translate("Calculator", "5", nullptr));
        Button1->setText(QCoreApplication::translate("Calculator", "1", nullptr));
        Button4->setText(QCoreApplication::translate("Calculator", "4", nullptr));
        ChangeSign->setText(QCoreApplication::translate("Calculator", "+/-", nullptr));
        MemoryGet->setText(QCoreApplication::translate("Calculator", "M", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Calculator: public Ui_Calculator {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CALCULATOR_H
