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

//在这里字体加粗的操函数在UI里面没有默认的，但是斜体或者下划线可以直接使用
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
    //旧的信号与槽的写法
    //这里之前调试一直不通过的原因是QString写成了QSTRING，老的写法里面把信号与槽函数转化为了字符串，没有类型检查，所以编译通过但是运行不正常
    //connect(comboFont,SIGNAL(currentIndexChanged(const QString &)),
    //this,SLOT(on_comboFont_currentIndexChanged(const QString &)));

    /*第二种信号与槽的写法
     * error: no matching function for call to ‘QWMainWind::connect(QFontComboBox*&, <unresolved overloaded function type>, QWMainWind*, void (QWMainWind::*)(const QString&))’
        connect(comboFont,&QFontComboBox::currentIndexChanged,this,&QWMainWind::on_comboFont_currentIndexChanged);
     * 重点，难点
     *   这里QFontComboBox::currentIndexChanged函数被重载了，需要使用函数指针进行指定是哪个函数
     *  void currentIndexChanged(int index)
     *  void currentIndexChanged(const QString &)
     */
    void (QFontComboBox:: *point)(const QString &) = &QFontComboBox::currentIndexChanged;
    connect(comboFont,point,this,&QWMainWind::on_comboFont_currentIndexChanged);

    //这里使用connect链接没有效果，未找到其中原因
    //connect(ui->actFontBold,SIGNAL(triggered(true)),this,SLOT(on_actFontBold_triggered(bool checked)));
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
//斜体、下划线使用信号与槽的机制实现，也可以在UI里面设置信号与槽，UI默认带斜体与下划线的信号与槽
void QWMainWind::on_actFontItalic_triggered(bool checked){
    QTextCharFormat fmt;
    fmt = ui->txtEdit->currentCharFormat();
    if(checked)
        fmt.setFontItalic(true);
    else
        fmt.setFontItalic(false);
    ui->txtEdit->mergeCurrentCharFormat(fmt);
}

void QWMainWind::on_actFontUnder_triggered(bool checked){
    QTextCharFormat fmt;
    fmt = ui->txtEdit->currentCharFormat();
    if(checked)
        fmt.setFontUnderline(true);
    else
        fmt.setFontUnderline(false);
    ui->txtEdit->mergeCurrentCharFormat(fmt);
}


QWMainWind::~QWMainWind()
{
    delete ui;
}
