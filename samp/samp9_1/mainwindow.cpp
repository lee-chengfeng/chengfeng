#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    createChart();

}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::createChart()
{
    QChartView *chartView = new QChartView(this);
    QChart *chart = new QChart();
    chart->setTitle("简单函数曲线");
    chartView->setChart(chart);
    this->setCentralWidget(chartView);

    QLineSeries *series0 = new QLineSeries();
    QLineSeries *series1 = new QLineSeries();
    series0->setName("Sin曲线");
    series1->setName("Cos曲线");
    chart->addSeries(series0);//这个时候的0\1没有数据，没有x轴  y轴
    chart->addSeries(series1);

    qreal t=0,y1,y2,intv=0.1;
    int cnt = 100;
    for (int i = 0;i<cnt;i++) {
        y1 = qSin(t);//<QtMath>
        series0->append(t,y1);
        y2 = qSin(t+20);
        series1->append(t,y2);
        t+=intv;
    }
     QValueAxis *axisX = new QValueAxis;
     axisX->setRange(0,10);//设置坐标轴范围
     axisX->setTitleText("time(secs)");//标题

     QValueAxis *axisY = new QValueAxis;
     axisY->setRange(-2,2);
     axisY->setTitleText("value");

     chart->setAxisX(axisX,series0);//为series0设置x轴 y轴  x从0开始绘制
     chart->setAxisY(axisY,series0);

     chart->setAxisX(axisX,series1);//为series1设置x轴 y轴
     chart->setAxisY(axisY,series1);


}
