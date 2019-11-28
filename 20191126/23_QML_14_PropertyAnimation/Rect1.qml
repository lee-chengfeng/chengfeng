import QtQuick 2.0

Rectangle{
    width:80
    height: 80
    color: "orange"

    radius: 10
    Text {
        anchors.centerIn: parent
        text: qsTr("属性值源")
    }

    PropertyAnimation on x{             //一个动画被应用为属性值源
        from:50
        to:500
        duration: 30000
        loops: Animation.Infinite       //无限循环
        easing.type: Easing.OutBounce   //easing属性中可以设置动画的缓和曲线
    }
}
