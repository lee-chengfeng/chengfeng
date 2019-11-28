import QtQuick 2.0
import QtQuick.Window 2.3

Window{
    visible: true
    height: 100
    width: 200
    title: qsTr("MouseArea")

    MainForm{
        anchors.fill: parent
        mouseArea.onClicked: {
            console.log(qsTr('Clicked on background. Text: "' + textEdit.text + '"'))
        }
    }

}
