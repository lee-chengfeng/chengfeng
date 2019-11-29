#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    QStringList theStrList;
    theStrList<<"北京"<<"上海"<<"天津"<<"河北";//初始化string

    theModel = new QStringListModel(this);
    theModel->setStringList(theStrList);
    ui->listView->setModel(theModel);
    //设置编辑出发的条件，在双击、选择并点击这两种条件下可以对所选项进行编辑
    ui->listView->setEditTriggers(QAbstractItemView::DoubleClicked | QAbstractItemView::SelectedClicked);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_listView_clicked(const QModelIndex &index)
{
    ui->label->setText(QString::asprintf("当前项:row=%d, column=%d",
                                         index.row(),index.column()));
}

void Widget::on_btnInit_clicked()
{
    QStringList theStrList;
    theStrList<<"北京"<<"上海"<<"天津"<<"河北";//初始化string
    theModel->setStringList(theStrList);
}
void Widget::on_btnClear_clicked()
{
    theModel->removeRows(0,theModel->rowCount());//清除从零到最末尾的行
}
void Widget::on_btnAppend_clicked()
{
    theModel->insertRow(theModel->rowCount());//在最后位置插入一个空行
    QModelIndex index = theModel->index(theModel->rowCount()-1,0);
    //获取最后一行的索引，这里的0代表什么含义？返回由给定的行、列和父索引指定的模型中的项的索引。
    //index(int row, int column, const QModelIndex &parent = QModelIndex()) const
    theModel->setData(index,"new item",Qt::DisplayRole);
    ui->listView->setCurrentIndex(index);//这一句的含义是什么？选中当前新添加的行
}
//以下这种写法是把选中的覆盖了实现的插入，如何才能不覆盖就实现插入操作？
void Widget::on_btnInsert_clicked()
{
    QModelIndex index;
    index = ui->listView->currentIndex();
    theModel->insertRow(index.row());//这里没有实现插入操作，所以直接覆盖所选的内容
    theModel->setData(index,"inserted item",Qt::DisplayRole);
    theModel->setData(index,Qt::AlignRight,Qt::TextAlignmentRole);//设置对齐方式？？？
     ui->listView->setCurrentIndex(index);
}

void Widget::on_btnDel_clicked()
{
    QModelIndex index;
    index = ui->listView->currentIndex();
    theModel->removeRow(index.row());//删除当前行
}

void Widget::on_btnClearText_clicked()
{
    ui->plainTextEdit->clear();
}
void Widget::on_btnDisplay_clicked()
{
    QStringList tmpList;
    tmpList = theModel->stringList();

    ui->plainTextEdit->clear();
    for (int i=0;i<tmpList.count();i++) {
        ui->plainTextEdit->appendPlainText(tmpList.at(i));
    }
}
