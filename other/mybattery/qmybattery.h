#ifndef QMYBATTERY_H
#define QMYBATTERY_H

#include <QWidget>
#include <QColor>
#include <QPainter>
#include <QPen>
class QmyBattery : public QWidget
{
    Q_OBJECT
public:
    explicit QmyBattery(QWidget *parent = nullptr);
private:
    QColor mColorBack = Qt::white;
    QColor mColorBorder = Qt::black;
    QColor mColorPower = Qt::green;
    QColor mColorWaring = Qt::red;

    int mPowerLevel = 60;
    int mWarnLeven = 20;


protected:
    void paintEvent(QPaintEvent *event) Q_DECL_OVERRIDE;
public:
    void setpowerLevel(int pow);
    int powerLevel();
    void setWarnLevel(int warn);
    int warnLevel();
    QSize sizeHint();
    QPen pen;
signals:
    void powerLevelChanged(int);

public slots:
};

#endif // QMYBATTERY_H
