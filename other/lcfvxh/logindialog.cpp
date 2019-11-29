#include "logindialog.h"
#include "ui_logindialog.h"

LoginDialog::LoginDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoginDialog)
{
    ui->setupUi(this);
    ui->pwdLineEdit->setFocus();

    /*两种常用的图片加载方式*/
    //加载微信图标-pixmap
    //icon = new QPixmap;
    int width = ui->label->width();
    int height = ui->label->height();

//    ui->label->clear();
//    icon.load("D:\\Users\\LEE\\Documents\\lcfvxh\\src\\wei.jpg");

//
//    ui->label->setPixmap(icon);

    //加载微信图表-image
    //weixin = new QImage;
    weixin.load("D:\\Users\\LEE\\Documents\\lcfvxh\\src\\wei.jpg");

    icon.scaled(width, height, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
    icon = QPixmap::fromImage(weixin);
    ui->label->clear();
    ui->label->setPixmap(QPixmap::fromImage(weixin));
}

LoginDialog::~LoginDialog()
{
    delete ui;
}

void LoginDialog::on_loginPushButton_clicked()
{
    showWeiChatWindow();
}

void LoginDialog::showWeiChatWindow()
{
    QFile file("userlog.xml");
    mydoc.setContent(&file);
    QDomElement root = mydoc.documentElement();
    if(root.hasChildNodes())
    {
        QDomNodeList userlist = root.childNodes();
        bool exist = false;
        for (int i = 0;i<userlist.count();i++)
        {
            QDomNode user = userlist.at(i);
            QDomNodeList record = user.childNodes();
            QString uname = record.at(0).toElement().text();
            QString pword = record.at(1).toElement().text();
            if(uname == ui->usrLineEdit->text())
            {
                exist = true;
                if(!(pword == ui->pwdLineEdit->text()))
                {
                    QMessageBox::warning(0,QObject::tr("提示"),"密码错误，请重新输入！");
                    ui->pwdLineEdit->clear();
                    ui->pwdLineEdit->setFocus();
                    return;

                }
            }
        }
        if(!exist)
        {
            QMessageBox::warning(0,QObject::tr("提示"),"此用户不存在，请重新输入！");
            ui->usrLineEdit->clear();
            ui->pwdLineEdit->clear();
            ui->usrLineEdit->setFocus();
            return;
        }
        weichatWindow = new MainWindows(0);
        weichatWindow->setWindowTitle(ui->usrLineEdit->text());
        weichatWindow->show();
    }
}
