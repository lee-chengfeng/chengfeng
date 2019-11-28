import QtQuick 2.4
import QtQuick.Controls 2.4
import QtQuick.Layouts 1.3
import QtQuick.Controls.Styles 1.3
import QtQuick.Controls 1.5
Item {
    id:window

    width: 600
    height: 240
    property int columnWidth: window.width/5

    GridLayout{
        rowSpacing: 12
        columnSpacing: 30
        anchors.top: parent.top
        anchors.horizontalCenter: parent.horizontalCenter//在主窗体剧中
        anchors.margins: 30//锚距30

        Button{
            text: "标准按钮"
            implicitWidth: columnWidth

        }
        Button{
            text: "样式属性"
            //import QtQuick.Controls 1.5---style;import QtQuick.Controls.Styles 1.3---ButtonStyle
            style:ButtonStyle{
                background: BorderImage {
                    //id: name
                    source: "file"
                    //width: 100; height: 100
                    //border---边界
                    border.left: 4; border.top: 4
                    border.right: 4; border.bottom: 4
                }
            }
            implicitWidth: columnWidth
        }
        Button{
            text: "样式代理"
            style:buttonStyle//buttonStyle是在哪里定义的？
            implicitWidth: columnWidth//implicitWidth设定对象的隐式宽度
        }
        TextField{
            Layout.row: 1//指定在grid中的行号是1（第二行）
            implicitWidth: columnWidth//implicitWidth设定对象的隐式宽度
        }
        TextField{
            style: TextFieldStyle{
                background: BorderImage{
                    //设置背景图片为。。。
                    source: ""
                    border.left: 4; border.top: 4
                    border.right: 4; border.bottom: 4
                }
            }
            implicitWidth: columnWidth
        }
        TextField{
            style: textFieldStyle
            implicitWidth: columnWidth
        }
        Slider{
            id: slider1
            Layout.row: 2//指定初始在第三行
            value:0.5
            implicitWidth: columnWidth
        }
        Slider{
            id: slider2
            value:0.5
            implicitWidth: columnWidth

            style: SliderStyle{
                groove: BorderImage {
                    source: "file"
                    height: 6
                    border.top: 1
                    border.bottom: 1
                    border.left: 6
                    border.right: 6
                    BorderImage{
                        anchors.verticalCenter: parent.verticalCenter
                        source: ""

                        border.left: 5; border.top: 1
                        border.right: 5; border.bottom: 1

                        width: styleData.handleposition//***宽度到手柄（滑块的位置）
                        height: parent.height
                    }
                }
                handle:Item {
                    width: 13
                    height: 13
                    Image{
                        anchors.centerIn: parent
                        source: ""
                    }
                }
            }
        }
        Slider{
            id: slider3
            value: 0.5
            implicitWidth: columnWidth
            style:SliderStyle//SliderStyle为样式代理名称

        }
        ProgressBar{
            Layout.row: 3
            value:slider1.value
            implicitWidth: columnWidth
        }
        ProgressBar{
            Layout.row: 3
            value:slider2.value
            implicitWidth: columnWidth
        }
        ProgressBar{
            Layout.row: 3
            value:slider3.value
            implicitWidth: columnWidth
        }
    }
    //以下为定义各样式代理的代码
    property Component ButtonStyle:ButtonStyle{
        background: Rectangle{
            implicitHeight: 22
            implicitWidth: columnWidth

            //按钮被按下就获得焦点时变色*****
            color: control.pressed? "darkGray" : control.activeFocus ? "#cdd" : "#ccc"
            antialiasing: true
            border.color: "gray"
            radius: height/2//圆角型
            Rectangle{
                anchors.fill: parent
                anchors.margins: 1
                color: "transparent"
                antialiasing: true
                visible: !control.pressed
                border.color: "#aaffffff"//color的颜色表示不熟悉
                radius:height/2

            }
        }
    }
    property Component sliderStyle:SliderStyle{
        //Slider控件所使用的样式代理
        handle: Rectangle{
            width: 18
            height: 18
            color: control.pressed? "darkGray" : "lightGray"//按下的时候灰度改变
            border.color: "gray"
            antialiasing: true
            radius: height/2
            Rectangle{
                anchors.fill: parent
                anchors.margins: 1
                color: "transparent"
                antialiasing : true
                border.color: "#ee"
                radius:height/2
            }
        }
        groove: Rectangle{
            height: 8
            implicitWidth: columnWidth
            implicitHeight: 22
            antialiasing: true
            color: "#ccc"
            border.color: "#777"
            radius: height/2
            Rectangle{
                anchors.fill: parent
                anchors.margins:1
                color: "transparent"
                antialiasing : true
                border.color: "#66ffffff"
                radius: height/2
            }
        }
    }
    property Component progressBarStyle:ProgressBarStyle{
        background: BorderImage {
            source: "file"
            border.left: 2; border.top: 2
            border.right: 2; border.bottom: 2
        }
        progress: Item {
            clip: true
            BorderImage {
                anchors.fill: parent
                anchors.rightMargin:(control.value < control.maximumValue) ? -4 : 0
                source: "file"
                border.left: 10; border.top: 10
                Rectangle{
                    width: 1
                    color: "#a70"
                    opacity: 0.8
                    anchors.top: parent.top
                    anchors.bottom: parent.bottom

                    anchors.bottomMargin: 1
                    anchors.right: parent.right
                    visible:control.value < control.maximumValue
                    anchors.rightMargin: -parent.anchors.rightMargin
                }
            }
        }
    }

    property Component progressBarStyle2: ProgressBarStyle{
        //ProgressBar控件所使用的样式代理
        background: Rectangle{
            implicitWidth: columnWidth
            implicitHeight: 24
            color: "#f0f0f0"
            border.color: "gray"
        }
        progress:Rectangle{
            color: "#ccc"
            border.color: "gray"
            Rectangle{
                color: "transparent"
                border.color: "#44ffffff"
                anchors.fill: parent
                anchors.margins: 1
            }
        }
    }
}
