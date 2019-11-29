#include "qwmainwind.h"
#include "ui_qwmainwind.h"

QWMainWind::QWMainWind(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::QWMainWind)
{
    ui->setupUi(this);
    iniUI();
    iniSignalSlots();
}
void QWMainWind::on_actFontBold_triggered(bool checked)
{
    QTextCharFormat fmt;
    fmt = ui->txtEdit->currentCharFormat();
    if(checked)
        fmt.setFontWeight(QFont::Bold);
    else
        fmt.setFontWeight(QFont::Normal);
    ui->txtEdit->mergeCurrentCharFormat(fmt);
}

void QWMainWind::on_txtEdit_copyAvalilable(bool b)
{
    ui->actCut->setEnabled(b);
    ui->actCopy->setEnabled(b);
    ui->actPaste->setEnabled(ui->txtEdit->canPaste());

}

void QWMainWind::on_txtEdit_selectionChanged()
{
    QTextCharFormat fmt;
    fmt = ui->txtEdit->currentCharFormat();
    ui->actFontItalic->setChecked(fmt.fontItalic());
    ui->actFontBold->setChecked(fmt.font().bold());
    ui->actFontUnder->setChecked(fmt.fontUnderline());

}

void QWMainWind::iniSignalSlots()
{
    //信号与槽的关联
    connect(spinFontSize,SIGNAL(valueChanged(int)),
            this,SLOT(on_spinBoxFontSize_valueChanged(int)));
    connect(comboFont,SIGNAL(currentIndexChanged(const QSTRING &)),
            this,SLOT(on_comboFont_currentIndexChanged(const QString &)));
    connect(ui->actFontBold,SIGNAL(clienked(1)),this,SLOT(on_actFontBold_triggered(bool checked)));
}

void QWMainWind::on_spinBoxFontSize_valueChanged(int aFontSize)//改变字体的大小
{
    //改变字体大小的spinBox
    QTextCharFormat fmt;
    fmt.setFontPointSize(aFontSize);
    ui->txtEdit->mergeCurrentCharFormat(fmt);
    progressBar1->setValue(aFontSize);
}

void QWMainWind::on_comboFont_currentIndexChanged(const QString &arg1)
{
    //FontCombobox的相应，选择字体名称
    QTextCharFormat fmt;
    fmt.setFontFamily(arg1);
    ui->txtEdit->mergeCurrentCharFormat(fmt);
}

void QWMainWind::iniUI()
{
    flabCurFile = new QLabel;
    flabCurFile->setMinimumWidth(150);
    flabCurFile->setText("当前文件：");
    ui->statusBar->addWidget(flabCurFile);

    progressBar1 = new QProgressBar;
    progressBar1->setMaximumWidth(200);
    progressBar1->setMinimum(5);
    progressBar1->setMaximum(50);
    progressBar1->setValue(ui->txtEdit->font().pointSize());
    ui->statusBar->addWidget(progressBar1);

    spinFontSize = new QSpinBox;//上下加减的容器
    spinFontSize->setMaximum(5);
    spinFontSize->setMaximum(50);
    spinFontSize->setValue(ui->txtEdit->font().pointSize());//把当前字体的磅值传给QSpinBox
    spinFontSize->setMinimumWidth(50);

    ui->mainToolBar->addWidget(new QLabel("字体大小"));
    ui->mainToolBar->addWidget(spinFontSize);//为什么这里会报错，导致程序崩溃

    ui->mainToolBar->addSeparator();//分隔符
    ui->mainToolBar->addWidget(new QLabel("字体"));

    comboFont = new QFontComboBox;
    comboFont->setMinimumWidth(110);
    ui->mainToolBar->addWidget(comboFont);

    setCentralWidget(ui->txtEdit);
}
QWMainWind::~QWMainWind()
{
    delete ui;
}
