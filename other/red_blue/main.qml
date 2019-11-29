import QtQuick 2.12
import QtQuick.Window 2.12

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    Background {
        id: background
        anchors.fill: parent

        //target-sender赋值
        target: sender//注意这个事件是在背景下面，在sender之前

        Sender {
            id: sender
            //最重要的一步，给receiver赋值,当target由null转换为receiver的时候，触发sender的槽函数---onTargetChanged:
            //send: 就会与receiver的槽函数receive
            target: receiver
            x: 15
            y: 152
            circleColor: "#1706d3"
            contantText: "Sender"
            anchors.verticalCenter: parent.verticalCenter
        }

        Receiver {
            id: receiver
            x: 266
            y: 157

            width: sender.width//把receiver的宽度与sender的宽度动态绑定

            contantText: "Receiver"
            anchors.verticalCenter: parent.verticalCenter
        }
    }
}
