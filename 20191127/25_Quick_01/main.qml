import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.Dialogs 1.2
import QtQuick.Controls 2.4


//ApplicationWindow需要control才能使用
ApplicationWindow{
    visible: true
    width: 640
    height: 480
    title:qsTr("hello world")
//import QtQuick.Controls 2.4---MenuBar,版本低了不行，否则会报错：qrc:/main.qml:14 MenuBar is not a type；帮助手册里面查看需要的版本号
    menuBar: MenuBar{
        Menu{
            title: qsTr("File")
            MenuItem{
                text: qsTr("&open")//这里的&符号取的是快捷键，会在o下面添加一条下划线
                onTriggered: console.log("Open action triggered")
            }
            MenuItem{
                text: qsTr("Exit")
                onTriggered: Qt.quit()
            }
        }
    }

    MainForm{
        anchors.fill: parent
        button1.onClicked: messageDialog.show(qsTr("Button 1 press"))
        button2.onClicked: messageDialog.show(qsTr("Button 2 press"))

    }

    MessageDialog{
        id: messageDialog
        //静态不改变的属性
        title: qsTr("May I have your attention please?")
        //可能会改变的属性，通过调用对象函数传参的形式进行调用
        function show(caption){
            messageDialog.text = caption
            messageDialog.open()
        }
    }

}
