/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QWidget *centralWidget;
    QTableWidget *tableWidget;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_6;
    QHBoxLayout *horizontalLayout_3;
    QLineEdit *passportLine;
    QLineEdit *fioLine;
    QVBoxLayout *verticalLayout_7;
    QHBoxLayout *horizontalLayout_5;
    QLineEdit *stateNumberLine;
    QLineEdit *dateLine;
    QVBoxLayout *verticalLayout_10;
    QPushButton *pushInsertButton;
    QPushButton *pushDeleteButton;
    QPushButton *pushFindButton;
    QPushButton *pushInputFileButton;
    QPushButton *pushOutputFileButton;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout_8;
    QHBoxLayout *horizontalLayout_6;
    QSpinBox *spinBoxSize;
    QPushButton *pushSizeHashTableButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1036, 628);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        centralWidget = new QWidget(centralwidget);
        centralWidget->setObjectName("centralWidget");
        centralWidget->setGeometry(QRect(0, 0, 1031, 761));
        tableWidget = new QTableWidget(centralWidget);
        tableWidget->setObjectName("tableWidget");
        tableWidget->setGeometry(QRect(-10, 0, 671, 761));
        layoutWidget = new QWidget(centralWidget);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(660, 200, 381, 361));
        verticalLayout_6 = new QVBoxLayout(layoutWidget);
        verticalLayout_6->setSpacing(0);
        verticalLayout_6->setObjectName("verticalLayout_6");
        verticalLayout_6->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        passportLine = new QLineEdit(layoutWidget);
        passportLine->setObjectName("passportLine");
        QFont font;
        font.setPointSize(11);
        passportLine->setFont(font);

        horizontalLayout_3->addWidget(passportLine);

        fioLine = new QLineEdit(layoutWidget);
        fioLine->setObjectName("fioLine");
        fioLine->setFont(font);

        horizontalLayout_3->addWidget(fioLine);


        verticalLayout_6->addLayout(horizontalLayout_3);

        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setObjectName("verticalLayout_7");
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        stateNumberLine = new QLineEdit(layoutWidget);
        stateNumberLine->setObjectName("stateNumberLine");
        stateNumberLine->setFont(font);

        horizontalLayout_5->addWidget(stateNumberLine);

        dateLine = new QLineEdit(layoutWidget);
        dateLine->setObjectName("dateLine");
        dateLine->setFont(font);

        horizontalLayout_5->addWidget(dateLine);


        verticalLayout_7->addLayout(horizontalLayout_5);


        verticalLayout_6->addLayout(verticalLayout_7);

        verticalLayout_10 = new QVBoxLayout();
        verticalLayout_10->setObjectName("verticalLayout_10");
        verticalLayout_10->setSizeConstraint(QLayout::SizeConstraint::SetMaximumSize);
        verticalLayout_10->setContentsMargins(-1, 0, -1, 0);
        pushInsertButton = new QPushButton(layoutWidget);
        pushInsertButton->setObjectName("pushInsertButton");
        pushInsertButton->setMinimumSize(QSize(0, 20));

        verticalLayout_10->addWidget(pushInsertButton);

        pushDeleteButton = new QPushButton(layoutWidget);
        pushDeleteButton->setObjectName("pushDeleteButton");

        verticalLayout_10->addWidget(pushDeleteButton);

        pushFindButton = new QPushButton(layoutWidget);
        pushFindButton->setObjectName("pushFindButton");

        verticalLayout_10->addWidget(pushFindButton);

        pushInputFileButton = new QPushButton(layoutWidget);
        pushInputFileButton->setObjectName("pushInputFileButton");

        verticalLayout_10->addWidget(pushInputFileButton);

        pushOutputFileButton = new QPushButton(layoutWidget);
        pushOutputFileButton->setObjectName("pushOutputFileButton");

        verticalLayout_10->addWidget(pushOutputFileButton);


        verticalLayout_6->addLayout(verticalLayout_10);

        verticalLayoutWidget = new QWidget(centralWidget);
        verticalLayoutWidget->setObjectName("verticalLayoutWidget");
        verticalLayoutWidget->setGeometry(QRect(770, 50, 160, 80));
        verticalLayout_8 = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout_8->setObjectName("verticalLayout_8");
        verticalLayout_8->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName("horizontalLayout_6");
        spinBoxSize = new QSpinBox(verticalLayoutWidget);
        spinBoxSize->setObjectName("spinBoxSize");

        horizontalLayout_6->addWidget(spinBoxSize);


        verticalLayout_8->addLayout(horizontalLayout_6);

        pushSizeHashTableButton = new QPushButton(verticalLayoutWidget);
        pushSizeHashTableButton->setObjectName("pushSizeHashTableButton");

        verticalLayout_8->addWidget(pushSizeHashTableButton);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1036, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        passportLine->setInputMask(QCoreApplication::translate("MainWindow", "0000 000000", nullptr));
        passportLine->setText(QCoreApplication::translate("MainWindow", "1111 111111", nullptr));
        passportLine->setPlaceholderText(QCoreApplication::translate("MainWindow", "\320\237\320\260\321\201\320\277\320\276\321\200\321\202", nullptr));
        fioLine->setPlaceholderText(QCoreApplication::translate("MainWindow", "\320\244\320\230\320\236", nullptr));
        stateNumberLine->setInputMask(QCoreApplication::translate("MainWindow", "A000AA", nullptr));
        stateNumberLine->setText(QString());
        stateNumberLine->setPlaceholderText(QCoreApplication::translate("MainWindow", "\320\223\320\276\321\201. \320\275\320\276\320\274\320\265\321\200", nullptr));
        dateLine->setInputMask(QCoreApplication::translate("MainWindow", "00.00.0000", nullptr));
        dateLine->setText(QCoreApplication::translate("MainWindow", "10.07.2021", nullptr));
        dateLine->setPlaceholderText(QCoreApplication::translate("MainWindow", "\320\224\320\260\321\202\320\260", nullptr));
        pushInsertButton->setText(QCoreApplication::translate("MainWindow", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214", nullptr));
        pushDeleteButton->setText(QCoreApplication::translate("MainWindow", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214", nullptr));
        pushFindButton->setText(QCoreApplication::translate("MainWindow", "\320\235\320\260\320\271\321\202\320\270", nullptr));
        pushInputFileButton->setText(QCoreApplication::translate("MainWindow", "\320\241\321\207\320\270\321\202\320\260\321\202\321\214 \320\270\320\267 \321\204\320\260\320\271\320\273\320\260", nullptr));
        pushOutputFileButton->setText(QCoreApplication::translate("MainWindow", "\320\222\321\213\320\262\320\265\321\201\321\202\320\270 \320\262 \321\204\320\260\320\271\320\273", nullptr));
        pushSizeHashTableButton->setText(QCoreApplication::translate("MainWindow", "\320\227\320\260\320\264\320\260\321\202\321\214 \321\200\320\260\320\267\320\274\320\265\321\200 \321\205\321\202", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
