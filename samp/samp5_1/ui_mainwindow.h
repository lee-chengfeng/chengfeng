/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QTableView>
#include <QtWidgets/QTreeView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout_4;
    QSplitter *splitter_2;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QTreeView *treeView;
    QSplitter *splitter;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_2;
    QListView *listView;
    QGroupBox *groupBox_3;
    QGridLayout *gridLayout_3;
    QTableView *tableView;
    QGroupBox *groupBox_5;
    QVBoxLayout *verticalLayout;
    QLabel *label_path;
    QHBoxLayout *horizontalLayout;
    QLabel *label_name;
    QLabel *label_size;
    QLabel *label_type;
    QCheckBox *checkBox_dir;
    QMenuBar *menuBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(729, 570);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout_4 = new QGridLayout(centralWidget);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        splitter_2 = new QSplitter(centralWidget);
        splitter_2->setObjectName(QStringLiteral("splitter_2"));
        splitter_2->setOrientation(Qt::Horizontal);
        groupBox = new QGroupBox(splitter_2);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        treeView = new QTreeView(groupBox);
        treeView->setObjectName(QStringLiteral("treeView"));

        gridLayout->addWidget(treeView, 0, 0, 1, 1);

        splitter_2->addWidget(groupBox);
        splitter = new QSplitter(splitter_2);
        splitter->setObjectName(QStringLiteral("splitter"));
        splitter->setOrientation(Qt::Vertical);
        groupBox_2 = new QGroupBox(splitter);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        gridLayout_2 = new QGridLayout(groupBox_2);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        listView = new QListView(groupBox_2);
        listView->setObjectName(QStringLiteral("listView"));

        gridLayout_2->addWidget(listView, 0, 0, 1, 1);

        splitter->addWidget(groupBox_2);
        groupBox_3 = new QGroupBox(splitter);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        gridLayout_3 = new QGridLayout(groupBox_3);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        tableView = new QTableView(groupBox_3);
        tableView->setObjectName(QStringLiteral("tableView"));

        gridLayout_3->addWidget(tableView, 0, 0, 1, 1);

        splitter->addWidget(groupBox_3);
        splitter_2->addWidget(splitter);

        gridLayout_4->addWidget(splitter_2, 0, 0, 1, 1);

        groupBox_5 = new QGroupBox(centralWidget);
        groupBox_5->setObjectName(QStringLiteral("groupBox_5"));
        verticalLayout = new QVBoxLayout(groupBox_5);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label_path = new QLabel(groupBox_5);
        label_path->setObjectName(QStringLiteral("label_path"));

        verticalLayout->addWidget(label_path);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label_name = new QLabel(groupBox_5);
        label_name->setObjectName(QStringLiteral("label_name"));

        horizontalLayout->addWidget(label_name);

        label_size = new QLabel(groupBox_5);
        label_size->setObjectName(QStringLiteral("label_size"));

        horizontalLayout->addWidget(label_size);

        label_type = new QLabel(groupBox_5);
        label_type->setObjectName(QStringLiteral("label_type"));

        horizontalLayout->addWidget(label_type);

        checkBox_dir = new QCheckBox(groupBox_5);
        checkBox_dir->setObjectName(QStringLiteral("checkBox_dir"));

        horizontalLayout->addWidget(checkBox_dir);


        verticalLayout->addLayout(horizontalLayout);


        gridLayout_4->addWidget(groupBox_5, 1, 0, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 729, 23));
        MainWindow->setMenuBar(menuBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("MainWindow", "TreeView", Q_NULLPTR));
        groupBox_2->setTitle(QApplication::translate("MainWindow", "ListView", Q_NULLPTR));
        groupBox_3->setTitle(QApplication::translate("MainWindow", "TableView", Q_NULLPTR));
        groupBox_5->setTitle(QString());
        label_path->setText(QApplication::translate("MainWindow", "\346\226\207\344\273\266\350\267\257\345\276\204\357\274\232", Q_NULLPTR));
        label_name->setText(QApplication::translate("MainWindow", "\346\226\207\344\273\266\345\220\215\357\274\232", Q_NULLPTR));
        label_size->setText(QApplication::translate("MainWindow", "\346\226\207\344\273\266\345\244\247\345\260\217\357\274\232", Q_NULLPTR));
        label_type->setText(QApplication::translate("MainWindow", "\346\226\207\344\273\266\347\261\273\345\236\213\357\274\232", Q_NULLPTR));
        checkBox_dir->setText(QApplication::translate("MainWindow", "\350\212\202\347\202\271\346\230\257\347\233\256\345\275\225", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
