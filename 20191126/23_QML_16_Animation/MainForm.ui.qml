import QtQuick 2.9

Rectangle {
    property alias mouseArea: mouseArea

    width: 360
    height: 360

    MouseArea {
        id: mouseArea
        anchors.fill: parent
    }
    //调用组件
    AnimationRect {
    }
}
