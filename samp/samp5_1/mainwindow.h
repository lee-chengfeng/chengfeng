#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileSystemModel>
#include <QString>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
private:
    QFileSystemModel *model;//定义数据模版变量
public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private slots://这里必须写slots，否则被认为只普通函数处理，这里按on_widgetname_signalname(signal parameters)命名，不用写connect
    void on_treeView_clicked(const QModelIndex &index);
private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
