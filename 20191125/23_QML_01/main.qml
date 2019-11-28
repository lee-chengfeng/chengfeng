import QtQuick 2.9              //导入Qt Quick 2.9库
import QtQuick.Window 2.2       //导入Qt Quick窗体库

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")
    MainForm {
        anchors.fill: parent
        //利用起的别名对对象的属性进行访问,当mouseArea被点击的是偶，在控制台输出对应字符串
        mouseArea.onClicked: {
            console.log(qsTr('Clicked on background. Text: "' + textEdit.text + '"'))
        }
    }
}
/*
Window 对象---visible 属性
MainForm 子对象
*/
