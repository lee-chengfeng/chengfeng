#ifndef CLIENT_H
#define CLIENT_H

#include <QMainWindow>
#include <QString>
#include <QHostInfo>
#include <QLabel>
#include <QUdpSocket>
#include <iostream>

#include <QSharedMemory>
#include <QBuffer>

namespace Ui {
class Client;
}

class Client : public QMainWindow
{
    Q_OBJECT

public:
    explicit Client(QWidget *parent = nullptr);
    ~Client();

public:
    QSharedMemory shareMemory;                          //共享内存对象

private slots:
    void on_btnSend_clicked();                          //客户端RGB信息发送按钮槽函数

    void onSocketStateChange(QAbstractSocket::SocketState socketState);//udp链接状态在状态栏显示槽函数

    void onSocketReadyRead();                           //读取socket传入的数据槽函数

    void on_actStart_triggered();                       //端口绑定槽函数

    void on_actStop_triggered();                        //端口解绑槽函数

    void on_actClear_triggered();                       //plainTextEdit组件清空槽函数

    void on_actHostInfo_triggered();                    //获取主机信息槽函数，linux正常，windows下还需完善多网卡

    void on_setPushButtonColor_clicked();               //设置发送按钮背景颜色槽函数

    void on_readShareMemory_clicked();                  //读共享内存槽函数

    void on_writeShareMemory_clicked();                 //写共享内存槽函数

private:
    Ui::Client *ui;
    QLabel  *labelSocketState;
    QUdpSocket  *udpSocket;                             //udpSocket对象建立
    QString getLocalIP();                               //获取本机IP地址,私有功能，不对外公开
    void detach();                                      //从共享内存段中分离进程
    QString colorCommand(QStringList &rgbList);         //RGB信息的拼接
};

#endif // CLIENT_H
