#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QStringListModel>
namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT
private:
    QStringListModel *theModel;//数据模型
public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void on_listView_clicked(const QModelIndex &index);

    void on_btnInit_clicked();//UI里widget的名字最好不要带下划线
    void on_btnClear_clicked();
    void on_btnAppend_clicked();
    void on_btnInsert_clicked();
    void on_btnDel_clicked();

    void on_btnClearText_clicked();
    void on_btnDisplay_clicked();

private:
    Ui::Widget *ui;
};

#endif // WIDGET_H
