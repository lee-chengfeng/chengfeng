import QtQuick 2.0

Rectangle{
    width: 80
    height: 80
    color: "lightblue"
    radius: 10
    Text {
        anchors.centerIn: parent
        font.pointSize: 12
        text: "改变行为"
    }
    //x轴的运动
    Behavior on x{
        PropertyAnimation{
            duration: 1000
            easing.type: Easing.InQuart//加速运动

        }
    }
    //y轴的运行
    Behavior on y{
        PropertyAnimation{
            duration: 1000
            easing.type:Easing.InQuart
        }
    }
}
