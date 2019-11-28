import QtQuick 2.4

Rectangle {
    property alias mouseArea: mouseArea

    width: 360
    height: 360
    MouseArea {
        id: mouseArea
        anchors.fill: parent
    }
    Grid {
        x: 25
        y: 25
        spacing: 4

        //用重复器为Grid添加元素成员
        Repeater {
            //制定16个重复元素
            model: 16
            Rectangle {
                width: 48
                height: 48
                color: "aqua"
                Text {
                    anchors.centerIn: parent
                    color: "black"
                    font.pointSize: 20
                    //指定text的文本是被复用的序号
                    text: index
                }
            }
        }
    }
}
