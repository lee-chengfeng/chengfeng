#include "mainwindow.h"
#include "ui_mainwindow.h"


void MainWindow::iniModelFromStringList(QStringList & aFileContent)// 生命 引用的 时候 不需要加 aFileContent
{
    int rowCnt = aFileContent.count();
    theModel->setRowCount(rowCnt-1);

    QString header = aFileContent.at(0);
    //  重点： 一个或 多个 空格 TAB 分开的 字符串， 分解为一个 stringlist
    QStringList headerList = header.split(QRegExp("\\s+"),QString::SkipEmptyParts);// 这一句 不能理解
    theModel->setHorizontalHeaderLabels(headerList);
    // 设置 表格数据
    int j;
    QStandardItem *aItem;

    for (int i = 0;i<rowCnt;i++) {
        QString aLineText = aFileContent.at(i);
        QStringList tmpList=aLineText.split(QRegExp("\\s+"),QString::SkipEmptyParts);
        for (j = 0;j<FixedColumnCount-1;j++) {
            // 未包含最后一列
            aItem = new QStandardItem(tmpList.at(j));
            theModel->setItem(i-1,j,aItem);
        }
        // 设置最后一 列
        aItem = new QStandardItem(headerList.at(j));
        aItem->setCheckable(true);// 设置为可以 checkable

        if(tmpList.at(j) == "0")//根据 条件 进行 判断，如果 最后 字符为零就UNchecked
            aItem->setCheckState(Qt::Unchecked);
        else
            aItem->setCheckState(Qt::Checked);
        theModel->setItem(i-1,j,aItem);
    }
}

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    theModel = new QStandardItemModel(2,FixedColumnCount,this);
    theSelection = new QItemSelectionModel(theModel);

    connect(theSelection,SIGNAL(currentChanged(QModeIndex,QModelIndex)),
            this,SLOT(on_currentChanged(QModelIndex,QModelIndex)));

    //为tableView设置数据模型，不明白selectmodel是什么意思
    ui->tableView->setModel(theModel);
    ui->tableView->setSelectionModel(theSelection);
    ui->tableView->setSelectionMode(QAbstractItemView::ExtendedSelection);//延申选择
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectItems);//选择行为：选择条目


    //setCentralWidget();//设置中心控件，找不到splitter

    //创建状态栏组件
    LabCurFile = new QLabel("当前文件：",this);
    LabCurFile->setMinimumWidth(200);

    LabCellPos = new QLabel("当前单元格：",this);
    LabCellPos->setMinimumWidth(180);
    LabCellPos->setAlignment(Qt::AlignHCenter);

    LabCellText = new QLabel("单元格内容：",this);
    LabCellText->setMinimumWidth(150);
    //添加状态栏组件
    ui->statusBar->addWidget(LabCurFile);
    ui->statusBar->addWidget(LabCellPos);
    ui->statusBar->addWidget(LabCellText);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_currentChanged(const QModelIndex &current, const QModelIndex &previous)
{
    if(current.isValid())
    {
        LabCellPos->setText(QString::asprintf("当前单元格：%d行,%d列",current.row(),current.column()));
        QStandardItem *aItem;
        aItem = theModel->itemFromIndex(current);
        this->LabCellText->setText("单元格内容："+aItem->text());
        QFont font = aItem->font();
        ui->actFontBold->setChecked(font.bold());//不理解---Returns true if weight() is a value greater than QFont::Medium; otherwise returns false.
    }
}

void MainWindow::on_actOpen_triggered()
{
    //获取应用程徐路径
    QString curPath = QCoreApplication::applicationFilePath();
    QString aFileName = QFileDialog::getOpenFileName(this,"打开一个文件",curPath,
                                                     "数据文件(*.txt);;所有文件(*.*)");//不理解
    if(aFileName.isEmpty())
    {
        return;
    }
    QStringList fFileContent;
    QFile aFile(aFileName);//以文件方式读出内容---QFile类提供了一个从文件中读取和写入文件的接口。

    if(aFile.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QTextStream aStream(&aFile);//以文本流的方式读出数据
        ui->plainTextEdit->clear();
        while(!aStream.atEnd())
        {
            QString str = aStream.readLine();
            ui->plainTextEdit->appendPlainText(str);//添加到文本框
            fFileContent.append(str);//添加到stringlist
        }
        aFile.close();

        this->LabCurFile->setText("当前文件："+aFileName);//状态栏显示当前文件名
        ui->actAppend->setEnabled(true);
        ui->actInsert->setEnabled(true);
        ui->actDelete->setEnabled(true);
        ui->actSave->setEnabled(true);

        iniModelFromStringList(fFileContent);//从stringlist的内容初始化内容
    }
}

void MainWindow::on_actAppend_triggered()
{
    QList<QStandardItem*> aItemList;
    QStandardItem *aItem;
    for (int i = 0;i<FixedColumnCount-1;i++) {
        aItem = new QStandardItem("0");
        aItemList << aItem;
    }

    //获取最后一列的表头文字
    QString str = theModel->headerData(theModel->columnCount()-1,Qt::Horizontal,Qt::DisplayRole).toString();
    aItem= new QStandardItem(str);
    aItem->setCheckable(true);
    aItemList <<aItem;
    //插入
    theModel->insertRow(theModel->rowCount(),aItemList);
    QModelIndex curIndex = theModel->index(theModel->rowCount(),0);//创建最后一行的的modelindex
    theSelection->clearSelection();//清空选择项
    theSelection->setCurrentIndex(curIndex,QItemSelectionModel::Select);//设置最后一行为选择的行
}

void MainWindow::on_actInsert_triggered()
{
    QList<QStandardItem*> aItemList;
    QStandardItem *aItem;
    for (int i = 0;i<FixedColumnCount-1;i++) {
        aItem = new QStandardItem("0");
        aItemList << aItem;
    }
    //获取表头文字
    QString str;
    str = theModel->headerData(theModel->columnCount()-1,Qt::Horizontal,Qt::DisplayRole).toString();
    aItem = new QStandardItem(str);
    aItem->setCheckable(true);
    aItemList<<aItem;

    QModelIndex curIndex = theSelection->currentIndex();
    theModel->insertRow(curIndex.row(),aItemList);//在当前行的前面插入
    theSelection->clearSelection();
    theSelection->setCurrentIndex(curIndex,QItemSelectionModel::Select);

}

void MainWindow::on_actDelete_triggered()//这里的plaintextedit如果固定大小，不随窗口改变，文本的输出可能是换行的，没有下面的滑动条
{
    QModelIndex curIndex = theSelection->currentIndex();
    if(curIndex.row() == theModel->rowCount()-1)
        theModel->removeRow(curIndex.row());
    else {
        theModel->removeRow(curIndex.row());
        theSelection->setCurrentIndex(curIndex,QItemSelectionModel::Select);
    }
}

void MainWindow::on_actModelData_triggered()
{
    ui->plainTextEdit->clear();
    QStandardItem *aItem;
    QString str;
    //获取表头文字
    int i,j;
    for (i = 0;i<theModel->columnCount();i++) {
        aItem = theModel->horizontalHeaderItem(i);//获取表头第i项的数据
        str = str+aItem->text()+"\t";
    }
    ui->plainTextEdit->appendPlainText(str);//添加为文本框的一行

    for (i = 0;i<theModel->rowCount();i++) {
        str = "";
        for (j = 0;j<theModel->columnCount()-1;j++) {
            aItem = theModel->item(i,j);
            str = str + aItem->text()+QString::asprintf("\t");
        }

        aItem = theModel->item(i,j);
        if(aItem->checkState() == Qt::Checked)
            str = str + "1";
        else
            str = str + "0";
        ui->plainTextEdit->appendPlainText(str);
    }
}

void MainWindow::on_actSave_triggered()
{
    QString curPath = QCoreApplication::applicationDirPath();
    QString aFileName = QFileDialog::getSaveFileName(this,tr("选择一个文件："),curPath,"井斜数据文件(*.txt);;所有文件(*.*)");

    if(aFileName.isEmpty())
        return;
    QFile aFile(aFileName);
    if(!(aFile.open(QIODevice::ReadWrite | QIODevice::Text |QIODevice::Truncate)))
        return;
    QTextStream aStream(&aFile);

    QStandardItem *aItem;

    int i,j;
    QString str;

    ui->plainTextEdit->clear();

    //获取表头文字
    for (i = 0;theModel->columnCount();i++) {
        aItem = theModel->horizontalHeaderItem(i);
        str = str + aItem->text()+"\t\t";
    }

    aStream<<str<<"\n";
    ui->plainTextEdit->appendPlainText(str);

    //获取数据区文字
    for (i = 0;i<theModel->rowCount();i++) {
        str = "";//这句话的意义是什么？
        for (j = 0;j<theModel->columnCount()-1;j++) {
            aItem = theModel->item(i,j);
            str = str + aItem->text()+QString::asprintf("\t\t");
        }

        aItem = theModel->item(i,j);

        if(aItem->checkState() == Qt::Checked)
        {
            str = str + "1";
        }
        else {
            str = str + "0";
        }

        ui->plainTextEdit->appendPlainText(str);

        aStream<<str<<"\n";
    }
}

void MainWindow::on_actAlignCenter_triggered()
{
    if(!theSelection->hasSelection())
        return;
    QModelIndexList selectedIndex = theSelection->selectedIndexes();

    QModelIndex aIndex;
    QStandardItem *aItem;
    for (int i = 0;i<selectedIndex.count();i++) {
        aIndex = selectedIndex.at(i);
        aItem = theModel->itemFromIndex(aIndex);
        aItem->setTextAlignment(Qt::AlignCenter);
    }
}

void MainWindow::on_actAlignLeft_triggered()
{
    if(!theSelection->hasSelection())
        return;
    QModelIndexList selectedIndex = theSelection->selectedIndexes();

    QModelIndex aIndex;
    QStandardItem *aItem;
    for (int i = 0;i<selectedIndex.count();i++) {
        aIndex = selectedIndex.at(i);
        aItem = theModel->itemFromIndex(aIndex);
        aItem->setTextAlignment(Qt::AlignLeft);
    }
}

void MainWindow::on_actAlignRight_triggered()
{
    if(!theSelection->hasSelection())//注意取反，否则失效
        return;
    QModelIndexList selectedIndex = theSelection->selectedIndexes();

    QModelIndex aIndex;
    QStandardItem *aItem;
    for (int i = 0;i<selectedIndex.count();i++) {
        aIndex = selectedIndex.at(i);
        aItem = theModel->itemFromIndex(aIndex);
        aItem->setTextAlignment(Qt::AlignRight);
    }
}

void MainWindow::on_actFontBold_triggered(bool checked)
{
    if(!theSelection->hasSelection())
        return;
    QModelIndexList selectedIndex = theSelection->selectedIndexes();

    QModelIndex aIndex;
    QStandardItem *aItem;
    for (int i = 0;i<selectedIndex.count();i++) {
        aIndex = selectedIndex.at(i);
        aItem = theModel->itemFromIndex(aIndex);

        QFont font = aItem->font();
        font.setBold(checked);

        aItem->setFont(font);
    }
}
