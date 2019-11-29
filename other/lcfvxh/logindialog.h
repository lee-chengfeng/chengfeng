#ifndef LOGINDIALOG_H
#define LOGINDIALOG_H

#include <QDialog>
#include "mainwindows.h"

#include <QFile>
#include <QDomDocument>
#include <string>
#include <QMessageBox>
namespace Ui {
class LoginDialog;
}

class LoginDialog : public QDialog
{
    Q_OBJECT

public:
    explicit LoginDialog(QWidget *parent = nullptr);
    ~LoginDialog();
private slots:
    void on_loginPushButton_clicked();
    void showWeiChatWindow();
public:
    QPixmap icon;
    QImage weixin;

private:
    Ui::LoginDialog *ui;

    MainWindows *weichatWindow;
    QDomDocument mydoc;
};

#endif // LOGINDIALOG_H
