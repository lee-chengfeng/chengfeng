import QtQuick 2.4

FocusScope{
    property alias label:label.text
    property alias text:input.text

    Row{
        spacing: 5
        Text {
            id: label
            text: qsTr("标签")
        }
        Rectangle{
            width: 100
            height: 20
            color: "white"
            border.color: "color"
            TextEdit{
                id:input
                anchors.fill:parent
                anchors.margins: 4
                focus:true
                text:"请输入内容"
            }
        }
    }
}
