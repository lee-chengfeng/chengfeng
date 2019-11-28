import QtQuick 2.0

Rectangle{
    id:btn
    width:100;height: 62

    color: "teal"
    border.color: "aqua"
    border.width: 3

    Text {
        id:label
        anchors.centerIn: parent
        //pointSize就是字体的大小
        font.pointSize: 16
        text:"开始"
    }
    MouseArea{
        anchors.fill: parent
        onClicked: {
            //当按钮被按下的时候，边框和内部填充的颜色改变
            label.text = "按钮已经按下！"
            label.font.pointSize = 11
            btn.color = "aqua"
            btn.border.color = "teal"
        }
    }
}
