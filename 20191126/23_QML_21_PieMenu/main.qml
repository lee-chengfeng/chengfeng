import QtQuick 2.9
import QtQuick.Window 2.2
//import QtQuick.Extras 1.4//缺少库文件，无法加载
import QtQuick.Controls 2.0

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    MainForm{
        anchors.fill: parent
        mouseArea.onClicked: {
            pieMenu.popup(mouseArea.mouseX,mouseArea.mouseY)

        }
    }

    PieMenu{
        id: pieMenu
        triggerMode: TriggerMode.TriggerOnRelease
        MenuItem{
            text: "动作1"
            onTriggered: print("动作1")
        }

        MenuItem{
            text: "动作2"
            onTriggered: print("动作2")
        }
        MenuItem{
            text: "动作3"
            onTriggered: print("动作3")
        }
    }

}
