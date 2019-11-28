import QtQuick 2.4

Rectangle {
    //指定别名，是的外部可以对对象的属性进行修改、访问
    property alias mouseArea: mouseArea

    property alias textEdit: textEdit

    width: 360
    height: 360
    //指定id,并指定布局充满父窗口
    MouseArea {
        id: mouseArea
        anchors.fill: parent
    }
    //这里的文本编辑框是做什么用的？没有使用
    TextEdit {
        id: textEdit
        visible: false
    }

    RotateRect {
        x: 50
        y: 50
    }
}
