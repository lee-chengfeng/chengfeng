import QtQuick 2.9
import QtQuick.Window 2.2

Window {
    visible: true
    width: 3840 / 4
    height: 2400 / 4
    title: qsTr("Hello World")
    MainForm{
        anchors.fill: parent

        mouseArea.onClicked: {
            console.log(qsTr('clicked on background. text:"'+textEdit.text+'"'))
        }
    }
}
