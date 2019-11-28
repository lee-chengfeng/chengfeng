import QtQuick 2.0

Rectangle{
    id:rect3
    width: 80
    height: 80
    color: "aqua"
    radius: 10
    Text {
        anchors.centerIn: parent
        font.pointSize: 12
        text:"独立元素"

    }
    //建立独立的动画对象，不绑定在任何属性和对象上面
    PropertyAnimation{
        id:animation
        target: rect3
        properties: "x,y"
        duration: 1000
        easing.type: Easing.InOutBack//运动到半程增加过冲，然后减少
    }

    //这里的xy轴在页面上怎么定位的没有能理解
    MouseArea{
        anchors.fill:parent
        onClicked: {
            animation.from = 100//这里的起点、终点的位置怎么理解？
            animation.to = 200
            animation.running = true
        }
    }
}
