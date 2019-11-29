import QtQuick 2.7
import QtQuick.Window 2.2
import QtQuick.Controls 2.4
import QtQuick.Dialogs 1.2
import Qt.labs.calendar 1.0
ApplicationWindow {
    visible: true
    width: 320
    height: 280
    title: qsTr("Dialogs")

    MainForm{
        id: main
        anchors.fill: parent
        btnSelect.onClicked: dateDialog.open()
        btnOpen.onClicked: fileDialog.open()
        btnFont.onClicked:fontDialog.open()
        btnColor.onClicked:colorDialog.open()
    }
    Dialog{
        id: dateDialog
        title: "选择日期"
        width : 275
        height: 300
        //import QtQuick.Dialogs 1.2---StandardButton
        standardButtons: StandardButton.Save | StandardButton.Cancle
        onAccepted: main.date.text= calendar.selectedDate.toLocaleDateString

        //import Qt.labs.calendar 1.0
        /*
        sudo apt install qml-module-qt-labs-calendar
        sudo apt install qml-module-qt-labs-folderlistmodel
        sudo apt install qml-module-qt-labs-settings
        安装完了之后需要重新启动Qt（最好电脑一起启动）,fou
        */
        //以下功能在Qt5.11中未编译通过
//        Calendar{application
//            id: calendar
//            //双击日历等同保存功能
//            //onDoubleClicked: dateDialog.click(StandardButton.Save)
//        }
    }
    FileDialog{
        id:fileDialog
        title: "打开"
        nameFilters: ["Text files (*.txt)","Image files (*.jpg *.png)","All files(*)"]
        onAccepted: main.file.text = fileDialog.fileUrl//没有自动提示代码编写
    }
    FontDialog{
        id:fontDialog
        title:"字体"
        font: Qt.font({family: "宋体",pointSize: 12,weight:Font.Normal})

        modality: Qt.WindowModal
        onAccepted: main.content.font = fontDialog.font
    }
    ColorDialog{
        id: colorDialog
        title: "颜色"
        modality:Qt.WindowModal
        onAccepted: main.content.textColor = colorDialog.color
    }
}
