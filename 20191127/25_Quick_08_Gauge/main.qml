import QtQuick 2.9
import QtQuick.Window 2.2

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    MainForm{
        anchors.fill: parent
        //注意button的onClicked使用.号调用
        button1.onClicked: thermometer.value += 5
        button2.onClicked: thermometer.value -= 5
    }

}
