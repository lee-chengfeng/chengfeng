#include "client.h"
#include "ui_client.h"

Client::Client(QWidget *parent) :
    QMainWindow(parent),
    shareMemory("www.newfiber.com.cn"),                                     //设置共享内存标志名www.newfiber.com.cn
    ui(new Ui::Client)
{
    ui->setupUi(this);
    ui->mainToolBar->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);      //图标旁显示文本
    ui->actStop->setEnabled(false);

    labelSocketState=new QLabel("Socket状态：");
    labelSocketState->setMinimumWidth(200);
    ui->statusBar->addWidget(labelSocketState);

    QString localIP=getLocalIP();                                           //本机IP
    //this->setWindowTitle(this->windowTitle()+"----本机IP："+localIP);
    this->setWindowTitle("Server");
    ui->comboTargetIP->addItem(localIP);

    udpSocket=new QUdpSocket(this);                                         //用于与连接的客户端通讯的QTcpSocket

    connect(udpSocket,SIGNAL(stateChanged(QAbstractSocket::SocketState)),
            this,SLOT(onSocketStateChange(QAbstractSocket::SocketState)));
    onSocketStateChange(udpSocket->state());

    connect(udpSocket,SIGNAL(readyRead()),
            this,SLOT(onSocketReadyRead()));
}

Client::~Client()
{
    delete ui;
}

//获取本机IP地址,私有功能，不对外公开
QString Client::getLocalIP()
{
    QString hostName=QHostInfo::localHostName();                            //本地主机名
    QHostInfo   hostInfo=QHostInfo::fromName(hostName);
    QString   localIP="";

    QList<QHostAddress> addList=hostInfo.addresses();//

    if (!addList.isEmpty())
        for (int i=0;i<addList.count();i++)
        {
            QHostAddress aHost=addList.at(i);
            if (QAbstractSocket::IPv4Protocol==aHost.protocol())
            {
                localIP=aHost.toString();
                break;
            }
        }
    return localIP;
}


//读取socket传入的数据槽函数
void Client::onSocketReadyRead()
{
    //读取收到的数据报
    while(udpSocket->hasPendingDatagrams())
    {
        QByteArray datagram;
        datagram.resize(udpSocket->pendingDatagramSize());

        QHostAddress peerAddr;
        quint16 peerPort;
        udpSocket->readDatagram(datagram.data(),datagram.size(),&peerAddr,&peerPort);
        QString str=datagram.data();
        //调用函数把读到的信息放到共享内存，目前仅做成读文本信息，没有做成读socket数据，简单修改即可实现
        on_writeShareMemory_clicked();

        QString peer="[From "+peerAddr.toString()+":"+QString::number(peerPort)+"] ";
        //plainTextEdit组件追加文本
        ui->plainTextEdit->appendPlainText(peer+str);
        //把读到的RGB信息分解
        QStringList rgbList =  str.split(",");
        //---可根据字段数量灵活遍历数据，进行内存空间的写入，不会因为at越界导致程序崩溃
        QString rgb = colorCommand(rgbList);
        //---以下写法不够灵活，在字段数量变化的时候需要人为调整
        //QString rgb = QString("background-color: rgb(%1,%2,%3)").
                //arg(rgbList.at(0)).arg(rgbList.at(1)).arg(rgbList.at(2));
        //设置消息发送按钮的颜色
        ui->btnSend->setStyleSheet(rgb);
    }
}

//udp链接状态在状态栏显示槽函数
void Client::onSocketStateChange(QAbstractSocket::SocketState socketState)
{
    //除了能够明确链接和未连接的状态，其他状态还需要查资料，后续完善
    switch(socketState)
    {
    case QAbstractSocket::UnconnectedState:
        labelSocketState->setText("scoket状态：UnconnectedState");
        //未链接的时候链接按钮使能、断开按钮使不能
        ui->actStart->setEnabled(true);
        ui->actStop->setEnabled(false);
        break;
    case QAbstractSocket::HostLookupState:
        labelSocketState->setText("scoket状态：HostLookupState");
        break;
    case QAbstractSocket::ConnectingState:
        labelSocketState->setText("scoket状态：ConnectingState");
        break;

    case QAbstractSocket::ConnectedState:
        labelSocketState->setText("scoket状态：ConnectedState");\
        //链接的时候链接按钮使不能、断开按钮使能
        ui->actStart->setEnabled(false);
        ui->actStop->setEnabled(true);
        break;

    case QAbstractSocket::BoundState:
        labelSocketState->setText("scoket状态：BoundState");
        ui->actStart->setEnabled(false);
        ui->actStop->setEnabled(true);
        break;

    case QAbstractSocket::ClosingState:
        labelSocketState->setText("scoket状态：ClosingState");
        break;

    case QAbstractSocket::ListeningState:
        labelSocketState->setText("scoket状态：ListeningState");
    }
}

//客户端RGB信息发送按钮槽函数
void Client::on_btnSend_clicked()
{
    QString targetIP=ui->comboTargetIP->currentText();      //目标IP
    QHostAddress targetAddr(targetIP);

    quint16 targetPort=ui->spinTargetPort->value();//目标port
    //rgb是动态的每次都需要重新读取
    QString r = ui->redLineEdit->text();
    QString g = ui->greenLineEdit->text();
    QString b = ui->blueLineEdit->text();
    QString msg;                                            //发送的消息内容
    msg.append(r);
    msg.append(",");
    msg.append(g);
    msg.append(",");
    msg.append(b);

    QByteArray  str=msg.toUtf8();
    udpSocket->writeDatagram(str,targetAddr,targetPort);    //发出数据报

    ui->plainTextEdit->appendPlainText("[out] "+msg);

    ui->redLineEdit->setFocus();
}

//端口绑定槽函数
void Client::on_actStart_triggered()
{
    quint16 port=ui->spinBindPort->value();                 //本机UDP端口
    if (udpSocket->bind(port))                              //绑定端口成功
    {
        ui->plainTextEdit->appendPlainText("**已成功绑定");
        ui->plainTextEdit->appendPlainText("**绑定端口："
                                           +QString::number(udpSocket->localPort()));
        ui->actStart->setEnabled(false);
        ui->actStop->setEnabled(true);
    }
    else
        ui->plainTextEdit->appendPlainText("**绑定失败");
}

//端口解绑槽函数
void Client::on_actStop_triggered()
{
    udpSocket->abort();                                         //不能解除绑定
    ui->actStart->setEnabled(true);
    ui->actStop->setEnabled(false);
    ui->plainTextEdit->appendPlainText("**已解除绑定");
}

//plainTextEdit组件清空槽函数
void Client::on_actClear_triggered()
{
    ui->plainTextEdit->clear();
}

//获取主机信息槽函数，linux正常，windows下还需完善多网卡
void Client::on_actHostInfo_triggered()
{
    //本机地址按钮，windows下需要完善已经激活的网口信息的判断，目前没有实现，仅做了网络信息的遍历
    QString hostName=QHostInfo::localHostName();                //本地主机名
    ui->plainTextEdit->appendPlainText("本机主机名："+hostName+"\n");
    QHostInfo   hostInfo=QHostInfo::fromName(hostName);

    QList<QHostAddress> addList=hostInfo.addresses();//
    if (!addList.isEmpty())
        for (int i=0;i<addList.count();i++)
        {
            QHostAddress aHost=addList.at(i);
            if (QAbstractSocket::IPv4Protocol==aHost.protocol())
            {
                QString IP=aHost.toString();
                ui->plainTextEdit->appendPlainText("本机IP地址："+aHost.toString());
                if (ui->comboTargetIP->findText(IP)<0)
                    ui->comboTargetIP->addItem(IP);
            }
        }
}

void Client::on_setPushButtonColor_clicked()
{
    //界面上的RGB信息是动态的每次都需要重新读取
    QString r = ui->redLineEdit->text();
    QString g = ui->greenLineEdit->text();
    QString b = ui->blueLineEdit->text();
    QString rgb = QString("background-color: rgb(%1,%2,%3)").arg(r).arg(g).arg(b);
    ui->btnSend->setStyleSheet(rgb);
}

//从共享内存段中分离进程
void Client::detach()
{
    if (!shareMemory.detach())
        ui->plainTextEdit->appendPlainText(tr("Unable to detach from shared memory."));
}

//读共享内存槽函数
void Client::on_readShareMemory_clicked()
{  
    //为什么加入共享内存段总是错误？共享内存的创建程序只能写内存，不能读，共享内存的读写程序需要分开
    if (!shareMemory.attach()) {
        ui->plainTextEdit->appendPlainText(tr("Unable to attach to shared memory segment.\n" \
                                               "Load RGB info first."));
        return;
    }

    QString rgb;
    shareMemory.lock();                                 //加锁，对共享内存内容进行读取
    char *to = (char*)shareMemory.data();                       //显示数据以判定内存空间里面是否有需要的数据
    rgb = to;
    ui->plainTextEdit->appendPlainText("share memory read："+rgb);
    QStringList rgbList =  rgb.split(",");
    rgb = colorCommand(rgbList);
    ui->btnSend->setStyleSheet(rgb);
    shareMemory.unlock();                               //解锁，释放临界资源
    shareMemory.detach();                               //从共享内存段中分离进程
}



//写共享内存槽函数
void Client::on_writeShareMemory_clicked()
{
    //动态读取需要写入共享内存的数据
    QString r = ui->redLineEdit->text();
    QString g = ui->greenLineEdit->text();
    QString b = ui->blueLineEdit->text();
    QString  msg;                                        //发送的消息内容
    msg.append(r);
    msg.append(",");
    msg.append(g);
    msg.append(",");
    msg.append(b);
    int size = msg.size();

    if (shareMemory.isAttached())
        detach();
    //创建共享内存
    if (!shareMemory.create(size)) {
        ui->plainTextEdit->appendPlainText(tr("Unable to create shared memory segment."));
        return;
    }

    shareMemory.lock();                                     //加锁，对共享内存内容进行读取
    char *to = (char*)shareMemory.data();
    QByteArray ba = msg.toLatin1();
    const char *from=ba.data();                             //QString转char*****
    memcpy(to, from, qMin(shareMemory.size(), size));
    shareMemory.unlock();                                   //解锁，释放临界资源
    QString temp = to;
    ui->plainTextEdit->appendPlainText("share memory write："+temp);   //显示数据用于判定写进内存的数据是否正确
}

//RGB信息的拼接
QString Client::colorCommand(QStringList &rgbList)
{
    QList<QString>::Iterator it = rgbList.begin(),itend = rgbList.end();
    QString rgb = "background-color: rgb(";
    int i;
    for (i = 0;it != itend-1;it++,i++) {
        rgb.append(rgbList.at(i));
        rgb.append(",");
    }
    rgb.append(rgbList.at(i));
    rgb.append(")");
    return rgb;
}
