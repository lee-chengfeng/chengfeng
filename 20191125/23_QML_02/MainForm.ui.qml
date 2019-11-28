import QtQuick 2.4

//Item {
//    width: 400
//    height: 400
//}

Rectangle{
    property alias mouseArea:mouseArea
    property alias topRect:topRect
    width: 360
    height: 360
    MouseArea{
        id:mouseArea
        anchors.fill:parent
    }
    Rectangle{
        rotation: 45
        x: 40
        y: 60
        width: 100
        height: 100
        color: "red"
    }

    Rectangle{
        id: topRect
        opacity: 0.6
        scale: 0.8
        x: 135
        y: 60
        width: 100
        height: 100
        radius: 8//绘制圆角矩形的角半径
        gradient: Gradient{//渐变梯度
            GradientStop{                   //渐变梯度在位置1的时候是浅绿色
                position: 0.0;color: "aqua"
            }
            GradientStop{                   //渐变梯度在位置1的时候是蓝绿色
                position: 1.0;color: "teal"
            }
        }

        //为矩形添加一个3像素的蓝色边框
        border{
            width: 3;color: "blue"
        }
    }
}
/*
gradient
位置和颜色属性描述渐变中给定位置使用的颜色，由渐变停止表示。
默认位置为 0.0;默认颜色为黑色。
scale
此属性保存此项目的比例因子。
opacity
小于1.0的比例将导致以较小的尺寸呈现项目，而大于1.0的比例将以较大的尺寸呈现项目。 负比例会导致项目在渲染时被镜像。
此属性保存项目的不透明度
。 不透明度指定为0.0（完全透明）和1.0（完全不透明）之间的数字。 默认值为1.0。
*/
