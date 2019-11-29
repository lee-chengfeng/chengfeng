#ifndef MAINWINDOWS_H
#define MAINWINDOWS_H

#include <QWidget>
#include <QMessageBox>
#include <QUdpSocket>
#include <QNetworkInterface>
#include <QDateTime>
#include <QFile>
#include <QFileDialog>
#include <QDomComment>

class FileSrvDlg;

namespace Ui {
class MainWindows;
}
enum ChatMsgType { ChatMsg, OnLine, OffLine, SfileName, RefFile };

class MainWindows : public QWidget
{
    Q_OBJECT

public:
    explicit MainWindows(QWidget *parent = nullptr);
    ~MainWindows();
    void initMainWindow();
private slots:
    void recvAndProcessChatMsg();
private:
    Ui::MainWindows *ui;
    QString myname = "";
    QUdpSocket *myUdpSocket;
    qint16 myUdpPort;
    QDomDocument myDoc;
    QString myFileName;
    FileSrvDlg *myfsrv;
};

#endif // MAINWINDOWS_H
