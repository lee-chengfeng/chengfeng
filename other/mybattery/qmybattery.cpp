#include "qmybattery.h"

QmyBattery::QmyBattery(QWidget *parent) : QWidget(parent)
{

}

void QmyBattery::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    QPainter painter(this);
    QRect rect(0,0,width(),height());

    painter.setViewport(rect);

    painter.setWindow(0,0,120,50);
    painter.setRenderHint(QPainter::Antialiasing);
    painter.setRenderHint(QPainter::TextAntialiasing);
    //Qpen pen;//QPen不可以被重载
    pen.setWidth(2);
    pen.setColor(mColorBorder);
    pen.setStyle(Qt::SolidLine);
    pen.setCapStyle(Qt::FlatCap);//???
    pen.setJoinStyle(Qt::BevelJoin);//??
    painter.setPen(pen);
    QBrush brush;
    brush.setColor(mColorBack);
    brush.setStyle(Qt::SolidPattern);
    painter.setBrush(brush);
    rect.setRect(1,1,109,48);
    painter.drawRect(rect);
    brush.setColor(mColorBorder);
    painter.setBrush(brush);
    rect.setRect(110,15,10,20);
    painter.drawRect(rect);

    //电池,根据实际设置画刷和画笔
    if(mPowerLevel>mWarnLeven)
    {
        brush.setColor(mColorPower);
        pen.setColor(mColorPower);
    }
    else {
        brush.setColor(mColorWaring);
        pen.setColor(mColorWaring);
    }
    painter.setBrush(brush);
    painter.setPen(pen);

    //在点亮大于0的情况下就进行绘图
    if(mPowerLevel > 0)
    {
        rect.setRect(5,5,mPowerLevel,40);
        painter.drawRect(rect);
    }
    //绘制电量百分比
    QFontMetrics textSize(this->font());
    QString powStr = QString::asprintf("%d%%",mPowerLevel);
    QRect textRect = textSize.boundingRect(powStr);//***得到字符串的rect
    painter.setFont(this->font());
    pen.setColor(mColorBorder);
    painter.setPen(pen);
    painter.drawText(55-textRect.width()/2,23+textRect.height(),powStr);
}

void QmyBattery::setpowerLevel(int pow)
{
    mPowerLevel = pow;
    emit powerLevelChanged(pow);
    repaint();
}

int QmyBattery::powerLevel()
{
    return mPowerLevel;
}

void QmyBattery::setWarnLevel(int warn)
{
    mWarnLeven = warn;
    repaint();
}

int QmyBattery::warnLevel()
{
    return mWarnLeven;
}

QSize QmyBattery::sizeHint()
{
    int H = this->height();
    int W = H * 12/5;
    QSize size(W,H);
    return size;
}

