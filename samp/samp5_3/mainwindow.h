#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QStandardItemModel>
#include <QItemSelectionModel>

#include <QFileDialog>
#include <QTextStream>

//注意以上两个类的定义


#define FixedColumnCount 6

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
private:
    QLabel *LabCurFile;
    QLabel *LabCellPos;
    QLabel *LabCellText;

   QStandardItemModel *theModel;        //标准数据模型
   QItemSelectionModel *theSelection;   //Item选择模型

   void iniModelFromStringList(QStringList&);

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
   void on_currentChanged(const QModelIndex &current, const QModelIndex &previous);

   void on_actOpen_triggered();//打开文件

   void on_actAppend_triggered();

   void on_actInsert_triggered();

   void on_actDelete_triggered();

   void on_actModelData_triggered();

   void on_actSave_triggered();

   void on_actAlignCenter_triggered();

   void on_actAlignLeft_triggered();

   void on_actAlignRight_triggered();

   void on_actFontBold_triggered(bool checked);



private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
