#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    model = new QFileSystemModel(this);
    model->setRootPath(QDir::currentPath());

    ui->treeView->setModel(model);//设置数据模型
    ui->listView->setModel(model);
    ui->tableView->setModel(model);

    connect(ui->treeView,SIGNAL(clicked(QModelIndex)),
            ui->listView,SLOT(setRootIndex(QModelIndex)));
    connect(ui->treeView,SIGNAL(clicked(QModelIndex)),
            ui->tableView,SLOT(setRootIndex(QModelIndex)));//Toot Root


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_treeView_clicked(const QModelIndex &index)
//void on_<widget name>_<signal name>(<signal parameters>);这种方式不需要写connect
//就会自动将widget name中的信号signal name和这个槽void on_<widget name>_<signal name>(<signal parameters>)链接起来。
{
    ui->checkBox_dir->setChecked(model->isDir(index));
    ui->label_path->setText(model->filePath(index));
    ui->label_type->setText(model->type(index));

    ui->label_name->setText(model->fileName(index));

    int sz = model->size(index)/1024;

    if(sz < 1024)
        ui->label_size->setText(QString("%1 KB").arg(sz));
    else
        ui->label_size->setText(QString::asprintf("%.1f MB",sz/1024.0));

}
