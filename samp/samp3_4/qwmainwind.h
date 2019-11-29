#ifndef QWMAINWIND_H
#define QWMAINWIND_H

#include <QMainWindow>
#include <QLabel>
#include <QProgressBar>
#include <QFontComboBox>
#include <QSpinBox>

#include <QTextCharFormat>


namespace Ui {
class QWMainWind;
}

class QWMainWind : public QMainWindow
{
    Q_OBJECT

private:
    QLabel *flabCurFile;
    QProgressBar *progressBar1;
    QSpinBox *spinFontSize;
    QFontComboBox *comboFont;
    void iniUI();
    void on_actFontBold_triggered(bool checked);
    void on_txtEdit_copyAvalilable(bool b);
    void on_txtEdit_selectionChanged();

    void iniSignalSlots();
private slots:
    void on_spinBoxFontSize_valueChanged(int arg1);//改变字体大小
    void on_comboFont_currentIndexChanged(const QString &arg1);//选择字体

public:
    explicit QWMainWind(QWidget *parent = nullptr);
    ~QWMainWind();

private:
    Ui::QWMainWind *ui;
};

#endif // QWMAINWIND_H
