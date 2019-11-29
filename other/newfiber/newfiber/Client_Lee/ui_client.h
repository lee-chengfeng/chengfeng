/********************************************************************************
** Form generated from reading UI file 'client.ui'
**
** Created by: Qt User Interface Compiler version 5.9.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CLIENT_H
#define UI_CLIENT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Client
{
public:
    QAction *actStart;
    QAction *actStop;
    QAction *actQuit;
    QAction *actHostInfo;
    QAction *actClear;
    QWidget *centralWidget;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QLineEdit *greenLineEdit;
    QLineEdit *blueLineEdit;
    QLabel *greenLabel;
    QLabel *blueLabel;
    QLabel *redLabel;
    QLineEdit *redLineEdit;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QSpinBox *spinBindPort;
    QLabel *label_3;
    QComboBox *comboTargetIP;
    QLabel *label_4;
    QSpinBox *spinTargetPort;
    QToolButton *btnSend;
    QPlainTextEdit *plainTextEdit;
    QPushButton *setPushButtonColor;
    QPushButton *readShareMemory;
    QPushButton *writeShareMemory;
    QMenuBar *menuBar;
    QStatusBar *statusBar;
    QToolBar *mainToolBar;

    void setupUi(QMainWindow *Client)
    {
        if (Client->objectName().isEmpty())
            Client->setObjectName(QStringLiteral("Client"));
        Client->resize(564, 428);
        actStart = new QAction(Client);
        actStart->setObjectName(QStringLiteral("actStart"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/images/620.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        actStart->setIcon(icon);
        QFont font;
        font.setFamily(QString::fromUtf8("\345\256\213\344\275\223"));
        actStart->setFont(font);
        actStart->setMenuRole(QAction::TextHeuristicRole);
        actStop = new QAction(Client);
        actStop->setObjectName(QStringLiteral("actStop"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/images/624.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        actStop->setIcon(icon1);
        actQuit = new QAction(Client);
        actQuit->setObjectName(QStringLiteral("actQuit"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/images/132.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        actQuit->setIcon(icon2);
        actQuit->setIconVisibleInMenu(true);
        actHostInfo = new QAction(Client);
        actHostInfo->setObjectName(QStringLiteral("actHostInfo"));
        actHostInfo->setEnabled(true);
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/images/110.JPG"), QSize(), QIcon::Normal, QIcon::Off);
        actHostInfo->setIcon(icon3);
        actClear = new QAction(Client);
        actClear->setObjectName(QStringLiteral("actClear"));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/images/212.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        actClear->setIcon(icon4);
        centralWidget = new QWidget(Client);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(40, 50, 191, 192));
        QFont font1;
        font1.setFamily(QStringLiteral("Arial"));
        font1.setPointSize(20);
        groupBox->setFont(font1);
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        greenLineEdit = new QLineEdit(groupBox);
        greenLineEdit->setObjectName(QStringLiteral("greenLineEdit"));

        gridLayout->addWidget(greenLineEdit, 1, 1, 1, 1);

        blueLineEdit = new QLineEdit(groupBox);
        blueLineEdit->setObjectName(QStringLiteral("blueLineEdit"));

        gridLayout->addWidget(blueLineEdit, 2, 1, 1, 1);

        greenLabel = new QLabel(groupBox);
        greenLabel->setObjectName(QStringLiteral("greenLabel"));

        gridLayout->addWidget(greenLabel, 1, 0, 1, 1);

        blueLabel = new QLabel(groupBox);
        blueLabel->setObjectName(QStringLiteral("blueLabel"));

        gridLayout->addWidget(blueLabel, 2, 0, 1, 1);

        redLabel = new QLabel(groupBox);
        redLabel->setObjectName(QStringLiteral("redLabel"));

        gridLayout->addWidget(redLabel, 0, 0, 1, 1);

        redLineEdit = new QLineEdit(groupBox);
        redLineEdit->setObjectName(QStringLiteral("redLineEdit"));

        gridLayout->addWidget(redLineEdit, 0, 1, 1, 1);

        layoutWidget = new QWidget(centralWidget);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 0, 544, 30));
        QFont font2;
        font2.setFamily(QStringLiteral("Arial"));
        font2.setPointSize(12);
        layoutWidget->setFont(font2);
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setFont(font2);
        label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout->addWidget(label);

        spinBindPort = new QSpinBox(layoutWidget);
        spinBindPort->setObjectName(QStringLiteral("spinBindPort"));
        spinBindPort->setFont(font2);
        spinBindPort->setMinimum(1);
        spinBindPort->setMaximum(65535);
        spinBindPort->setValue(1200);

        horizontalLayout->addWidget(spinBindPort);

        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setFont(font2);
        label_3->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout->addWidget(label_3);

        comboTargetIP = new QComboBox(layoutWidget);
        comboTargetIP->setObjectName(QStringLiteral("comboTargetIP"));
        comboTargetIP->setMinimumSize(QSize(120, 0));
        comboTargetIP->setFont(font2);
        comboTargetIP->setEditable(true);
        comboTargetIP->setDuplicatesEnabled(false);

        horizontalLayout->addWidget(comboTargetIP);

        label_4 = new QLabel(layoutWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setFont(font2);
        label_4->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout->addWidget(label_4);

        spinTargetPort = new QSpinBox(layoutWidget);
        spinTargetPort->setObjectName(QStringLiteral("spinTargetPort"));
        spinTargetPort->setFont(font2);
        spinTargetPort->setMinimum(1);
        spinTargetPort->setMaximum(65535);
        spinTargetPort->setValue(3355);

        horizontalLayout->addWidget(spinTargetPort);

        btnSend = new QToolButton(centralWidget);
        btnSend->setObjectName(QStringLiteral("btnSend"));
        btnSend->setGeometry(QRect(330, 250, 131, 41));
        plainTextEdit = new QPlainTextEdit(centralWidget);
        plainTextEdit->setObjectName(QStringLiteral("plainTextEdit"));
        plainTextEdit->setGeometry(QRect(300, 50, 191, 191));
        setPushButtonColor = new QPushButton(centralWidget);
        setPushButtonColor->setObjectName(QStringLiteral("setPushButtonColor"));
        setPushButtonColor->setGeometry(QRect(70, 250, 131, 41));
        readShareMemory = new QPushButton(centralWidget);
        readShareMemory->setObjectName(QStringLiteral("readShareMemory"));
        readShareMemory->setGeometry(QRect(330, 300, 131, 41));
        writeShareMemory = new QPushButton(centralWidget);
        writeShareMemory->setObjectName(QStringLiteral("writeShareMemory"));
        writeShareMemory->setGeometry(QRect(70, 300, 131, 41));
        Client->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(Client);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 564, 23));
        Client->setMenuBar(menuBar);
        statusBar = new QStatusBar(Client);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        Client->setStatusBar(statusBar);
        mainToolBar = new QToolBar(Client);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        Client->addToolBar(Qt::TopToolBarArea, mainToolBar);

        mainToolBar->addAction(actStart);
        mainToolBar->addAction(actStop);
        mainToolBar->addAction(actClear);
        mainToolBar->addAction(actHostInfo);
        mainToolBar->addAction(actQuit);

        retranslateUi(Client);
        QObject::connect(actQuit, SIGNAL(triggered()), Client, SLOT(close()));

        QMetaObject::connectSlotsByName(Client);
    } // setupUi

    void retranslateUi(QMainWindow *Client)
    {
        Client->setWindowTitle(QApplication::translate("Client", "Client", Q_NULLPTR));
        actStart->setText(QApplication::translate("Client", "\347\273\221\345\256\232\347\253\257\345\217\243", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actStart->setToolTip(QApplication::translate("Client", "\347\273\221\345\256\232UDP\347\233\221\345\220\254\347\253\257\345\217\243", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        actStop->setText(QApplication::translate("Client", "\350\247\243\351\231\244\347\273\221\345\256\232", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actStop->setToolTip(QApplication::translate("Client", "\350\247\243\351\231\244UDP\347\233\221\345\220\254\347\253\257\345\217\243", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        actQuit->setText(QApplication::translate("Client", "\351\200\200\345\207\272", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actQuit->setToolTip(QApplication::translate("Client", "\351\200\200\345\207\272\346\234\254\347\250\213\345\272\217", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        actHostInfo->setText(QApplication::translate("Client", "\346\234\254\346\234\272\345\234\260\345\235\200", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actHostInfo->setToolTip(QApplication::translate("Client", "\350\216\267\345\217\226\346\234\254\346\234\272\345\234\260\345\235\200", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        actClear->setText(QApplication::translate("Client", "\346\270\205\347\251\272\346\226\207\346\234\254\346\241\206", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actClear->setToolTip(QApplication::translate("Client", "\346\270\205\347\251\272\346\226\207\346\234\254\346\241\206", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        groupBox->setTitle(QString());
        greenLineEdit->setText(QApplication::translate("Client", "200", Q_NULLPTR));
        blueLineEdit->setText(QApplication::translate("Client", "200", Q_NULLPTR));
        greenLabel->setText(QApplication::translate("Client", "\347\273\277\357\274\232", Q_NULLPTR));
        blueLabel->setText(QApplication::translate("Client", "\350\223\235\357\274\232", Q_NULLPTR));
        redLabel->setText(QApplication::translate("Client", "\347\272\242\357\274\232", Q_NULLPTR));
        redLineEdit->setText(QApplication::translate("Client", "0", Q_NULLPTR));
        label->setText(QApplication::translate("Client", "\347\273\221\345\256\232\347\253\257\345\217\243", Q_NULLPTR));
        label_3->setText(QApplication::translate("Client", "\347\233\256\346\240\207\345\234\260\345\235\200", Q_NULLPTR));
        comboTargetIP->clear();
        comboTargetIP->insertItems(0, QStringList()
         << QApplication::translate("Client", "127.0.0.1", Q_NULLPTR)
        );
        label_4->setText(QApplication::translate("Client", "\347\233\256\346\240\207\347\253\257\345\217\243", Q_NULLPTR));
        btnSend->setText(QApplication::translate("Client", "\345\217\221\351\200\201\346\266\210\346\201\257", Q_NULLPTR));
        setPushButtonColor->setText(QApplication::translate("Client", "\350\256\276\347\275\256\345\217\221\351\200\201\346\214\211\351\222\256\351\242\234\350\211\262", Q_NULLPTR));
        readShareMemory->setText(QApplication::translate("Client", "\350\257\273\345\205\261\344\272\253\345\206\205\345\255\230", Q_NULLPTR));
        writeShareMemory->setText(QApplication::translate("Client", "\345\206\231\345\205\261\344\272\253\345\206\205\345\255\230", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Client: public Ui_Client {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CLIENT_H
