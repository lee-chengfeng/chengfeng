import QtQuick 2.9
import QtQuick.Window 2.2

Window {
    //定位窗口的位置
    x:1000
    y:1000
    visible: true
    width: 640
    height: 480
    title: qsTr("Text")

    MainForm{
        anchors.fill : parent
        mouseArea.onClicked: {
            console.log('Clicked on background.Text:"'+textEdit.text+'"')
        }
    }
}
