#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_horizontalSlider_valueChanged(int value)
{
    ui->battery->setpowerLevel(value);
    QString str = QStringLiteral("当前电量：")+QString::asprintf("%d %%",value);
    ui->lineEdit->setText(str);
}
