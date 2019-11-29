import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.Controls 2.4
//sudo apt install qml-module-qtquick-extras
import QtQuick.Extras 1.4

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")


    MainForm{
        anchors.fill: parent
        //QtQuick.Extras
        CircularGauge{
            value: accelerating ? maximumValue : 0
            anchors.centerIn: parent
            property bool accelerating: false//默认是false
            Keys.onSpacePressed: accelerating = true//空格键按下的时候条件成立，这个时候value的值就是maximumValue
            Keys.onReleased: {
                if(event.key === Qt.key_Space)//三个等号是什么意思
                {
                    accelerating = false//在空格键抬起的时候恢复值
                    event.accepted = true//事件返回为accepted，结束事件循环
                }
            }
            Component.onCompleted: forceActiveFocus()
            //当值等于最大的时候，动画实现的周期设定
            Behavior on value {
                NumberAnimation{
                    duration: 1000//动画实现的周期
                }
            }
        }
    }
}
