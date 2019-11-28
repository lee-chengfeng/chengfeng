import QtQuick 2.4
import QtQuick.Controls 2.4
import QtQuick.Controls 1.4
import QtGraphicalEffects 1.0
import QtQuick.Layouts 1.2
Item {
    width: 890
    height: 460

    property alias img:img
    property alias desat:desat
    property alias size:size
    property alias colourful:colourful
    property alias btn:btn
    property alias progreBar:progreBar

    Image {
        id: img
        x:10;y:10
        width: 614.4
        height: 384
        source: "image/Flying_Whale_by_Shu_Le.jpg"
        fillMode: Image.Stretch //必须设置为拉伸模式才能够调整尺寸
        clip: true              //此属性保存是否启用裁剪。 默认剪辑值为false。
    }
    //当应用程序正在载入某些内容，或者UI被阻塞等待某个资源变为可用的时候，使用busyindicator提示用户耐心等待；例如在载入图片的时候
    BusyIndicator{//繁忙指示器应用于指示正在加载内容或UI阻塞等待资源可用时的活动。
        x:317.2;y:202
        running: img.width < 614.4*0.4
    }
    Desaturate{//将去饱和的像素值计算为源项目的原始RGB分量值的平均值。
        id: desat
        anchors.fill: img
        source: img
    }

    RowLayout{
        anchors.left: img.left
        y: 399
        spacing: 5
        Label{
            text: "尺寸"
        }
        Slider{
            id: size
            maximumValue: 1.0//算法不支持？？？import QtQuick.Controls 1.4是可以支持的，高版本不支持
            minimumValue: 0.1
            stepSize: 0.1
            value:1.0
        }
        Label{
            text: "彩色"
        }
        Switch{
            id: colourful
            checked: true
        }
        Button{
            id: btn
            text: "灰度值>>"
        }
        ProgressBar{
            id: progreBar
        }

    }
    ColumnLayout{
        anchors.top: img.top
        x:629.4
        spacing: 10
        RowLayout{
            spacing: 5
            Label{
                text: "小美人鱼"
                font.pixelSize: 14 //设置像素大小
                font.bold: true//设置加粗
            }
            SpinBox{
                id: age
                decimals: 0//设置精度
                value: 16
                minimumValue: 4
                maximumValue: 24
                suffix: "岁"//后缀
                font.pixelSize: 14//字号？？？

            }
        }
        Label{
            anchors.horizontalCenter: birthday.horizontalCenter//指定中心剧中的对象
            //文字与日历剧中对其
            text:"生日"
            font.pixelSize: 14
            font.bold: true
            color: "magenta"
        }
        Calendar{
            id: birthday
            minimumDate:"1991-09-01"
            //初始化显示的年月，value+1
            visibleYear: 2017 - age.value
            visibleMonth: 8
        }
    }



}
