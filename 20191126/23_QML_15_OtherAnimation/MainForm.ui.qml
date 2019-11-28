import QtQuick 2.4

Rectangle {
    property alias mouseArea: mouseArea

    width: 360
    height: 360
    //这里的填充没有被使用？
    MouseArea {
        id: mouseArea
        anchors.fill: parent
    }

    CircleRect {
        x: 50
        y: 30
    }
}
