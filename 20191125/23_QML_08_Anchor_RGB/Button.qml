import QtQuick 2.0


Rectangle{
    id:btn
    width:100;height: 62

    color: "teal"
    border.color: "aqua"
    border.width: 3
    Text {
        id: label
        anchors.centerIn: parent
        font.pointSize: 16
        text: "开始"
    }

    MouseArea{
        anchors.fill:parent
        onClicked: {
            label.text = "按钮已按下"
            label.font.pointSize = 11
            btn.color = "aqua"
            btn.border.color = "teal"
            /* 改变changingRect1的右锚属性 */
            chgRect1.anchors.left = undefined
            chgRect1.anchors.right = rRect.right
            /* 改变changingRect2的右锚属性 */
            chgRect2.anchors.left = undefined
            chgRect2.anchors.right = rRect.right
        }
    }
}
/*
这里先用“chgRect2.anchors.right = rRect.right”指定右锚属性，由于此时元素的左锚属性尚未解除，执行后，矩形位置并不会移动，而是宽度自动“拉长”到与redRect右对齐，之后即使再解除左锚属性也无济于事，故用户在编程改变布局时，一定要先将元素的旧锚解除，新设置的锚才能生效！
*/
