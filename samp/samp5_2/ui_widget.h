/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.11.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListView>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QGridLayout *gridLayout_5;
    QSplitter *splitter;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_3;
    QGridLayout *gridLayout_2;
    QPushButton *btnInit;
    QPushButton *btnAppend;
    QPushButton *btnInsert;
    QPushButton *btnDel;
    QPushButton *btnClear;
    QListView *listView;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_4;
    QVBoxLayout *verticalLayout;
    QPushButton *btnClearText;
    QPushButton *btnDisplay;
    QPlainTextEdit *plainTextEdit;
    QGroupBox *groupBox_3;
    QGridLayout *gridLayout;
    QLabel *label;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QStringLiteral("Widget"));
        Widget->resize(611, 406);
        gridLayout_5 = new QGridLayout(Widget);
        gridLayout_5->setSpacing(6);
        gridLayout_5->setContentsMargins(11, 11, 11, 11);
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        splitter = new QSplitter(Widget);
        splitter->setObjectName(QStringLiteral("splitter"));
        splitter->setOrientation(Qt::Horizontal);
        groupBox = new QGroupBox(splitter);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        gridLayout_3 = new QGridLayout(groupBox);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setSpacing(6);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        btnInit = new QPushButton(groupBox);
        btnInit->setObjectName(QStringLiteral("btnInit"));

        gridLayout_2->addWidget(btnInit, 0, 0, 1, 1);

        btnAppend = new QPushButton(groupBox);
        btnAppend->setObjectName(QStringLiteral("btnAppend"));

        gridLayout_2->addWidget(btnAppend, 1, 0, 1, 1);

        btnInsert = new QPushButton(groupBox);
        btnInsert->setObjectName(QStringLiteral("btnInsert"));

        gridLayout_2->addWidget(btnInsert, 1, 1, 1, 1);

        btnDel = new QPushButton(groupBox);
        btnDel->setObjectName(QStringLiteral("btnDel"));

        gridLayout_2->addWidget(btnDel, 2, 0, 1, 1);

        btnClear = new QPushButton(groupBox);
        btnClear->setObjectName(QStringLiteral("btnClear"));

        gridLayout_2->addWidget(btnClear, 2, 1, 1, 1);


        gridLayout_3->addLayout(gridLayout_2, 0, 0, 1, 1);

        listView = new QListView(groupBox);
        listView->setObjectName(QStringLiteral("listView"));

        gridLayout_3->addWidget(listView, 1, 0, 1, 1);

        splitter->addWidget(groupBox);
        groupBox_2 = new QGroupBox(splitter);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        gridLayout_4 = new QGridLayout(groupBox_2);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        btnClearText = new QPushButton(groupBox_2);
        btnClearText->setObjectName(QStringLiteral("btnClearText"));

        verticalLayout->addWidget(btnClearText);

        btnDisplay = new QPushButton(groupBox_2);
        btnDisplay->setObjectName(QStringLiteral("btnDisplay"));

        verticalLayout->addWidget(btnDisplay);


        gridLayout_4->addLayout(verticalLayout, 0, 0, 1, 1);

        plainTextEdit = new QPlainTextEdit(groupBox_2);
        plainTextEdit->setObjectName(QStringLiteral("plainTextEdit"));

        gridLayout_4->addWidget(plainTextEdit, 1, 0, 1, 1);

        splitter->addWidget(groupBox_2);

        gridLayout_5->addWidget(splitter, 0, 0, 1, 1);

        groupBox_3 = new QGroupBox(Widget);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        gridLayout = new QGridLayout(groupBox_3);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label = new QLabel(groupBox_3);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);


        gridLayout_5->addWidget(groupBox_3, 1, 0, 1, 1);


        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Widget", nullptr));
        groupBox->setTitle(QApplication::translate("Widget", "GroupBox", nullptr));
        btnInit->setText(QApplication::translate("Widget", "\346\201\242\345\244\215\345\210\227\350\241\250", nullptr));
        btnAppend->setText(QApplication::translate("Widget", "\346\267\273\345\212\240\351\241\271", nullptr));
        btnInsert->setText(QApplication::translate("Widget", "\346\217\222\345\205\245\351\241\271", nullptr));
        btnDel->setText(QApplication::translate("Widget", "\345\210\240\351\231\244\345\275\223\345\211\215\351\241\271", nullptr));
        btnClear->setText(QApplication::translate("Widget", "\346\270\205\351\231\244\345\210\227\350\241\250", nullptr));
        groupBox_2->setTitle(QApplication::translate("Widget", "GroupBox", nullptr));
        btnClearText->setText(QApplication::translate("Widget", "\346\270\205\347\251\272\346\226\207\346\234\254", nullptr));
        btnDisplay->setText(QApplication::translate("Widget", "\346\230\276\347\244\272\346\225\260\346\215\256\346\250\241\345\236\213\347\232\204stringlist", nullptr));
        groupBox_3->setTitle(QString());
        label->setText(QApplication::translate("Widget", "\345\275\223\345\211\215\351\241\271\347\232\204modelindex", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
