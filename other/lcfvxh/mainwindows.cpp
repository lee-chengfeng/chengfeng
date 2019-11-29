#include "mainwindows.h"
#include "ui_mainwindows.h"

MainWindows::MainWindows(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainWindows)
{
    ui->setupUi(this);
    initMainWindow();
}

MainWindows::~MainWindows()
{
    delete ui;
}
void MainWindows::initMainWindow()
{
    myUdpSocket = new QUdpSocket(this);
    myUdpPort = 23232;
    myUdpSocket->bind(myUdpPort,QUdpSocket::ShareAddress|QUdpSocket::ReuseAddressHint);
    connect(myUdpSocket,SIGNAL(readyRead()),this,SLOT(recvAndProcessChatMsg()));
    //myfsrv = new FileSrvDlg(this);
    //connect(myfsrv, SIGNAL(sendFileName(QString)), this, SLOT(getSfileName (QString)));


}
void MainWindows::recvAndProcessChatMsg()
{
    return;
}
