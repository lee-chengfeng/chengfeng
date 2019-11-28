import QtQuick 2.9
import QtQuick.Window 2.2

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    MainForm{
        anchors.fill: parent
        mouseArea.onClicked: {
            rect4.x = mouseArea.mouseX
            rect4.y = mouseArea.mouseY
        }
    }
}