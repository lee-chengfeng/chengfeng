import QtQuick 2.1
import QtQuick.Window 2.1
import QtQuick.Controls 2.1
import QtQuick.Layouts 1.1
import QtMultimedia 5.1
ApplicationWindow {
//两个不同的window有什么区别？
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    MediaPlayer{
        //MediaPlayer是不占用空间的，所以可以放在任何地方
        id:playMusic
        source: "/home/linux/Music/华晨宇 - Here We Are.mp3"
        autoPlay: true
    }


    header: ToolBar {
//        clip: true              //超出的控件是否显示，true表示朝大户的部分不显示
//        Rectangle{
//            width: 40
//            height: 40
//            color: "red"
//        }

        RowLayout {
            anchors.fill:parent
            ToolButton{
                //Layout.preferredHeight: 20
                //height: 40//在布局里面需要使用布局修改对象的长宽，单独修改属性不行
                icon.source: "qrc:/icons/grid.png"
            }
            ToolButton{
                icon.source: "qrc:/icons/settings.png"
            }
            ToolButton{
                icon.source: "qrc:/icons/filter.png"
            }
            ToolButton{
                icon.source: "qrc:/icons/message.png"
            }
            ToolButton{
                icon.source: "qrc:/icons/music.png"
            }
            ToolButton{
                icon.source: "qrc:/icons/cloud.png"
            }
            ToolButton{
                icon.source: "qrc:/icons/bluetooth.png"
            }
            ToolButton{
                icon.source: "qrc:/icons/cart.png"
            }
            Item {
                Layout.fillWidth: true
                //item是基础空间，大多数空间都继承与item,这里的item是填充所有的空间
            }
            ToolButton{
                icon.source: "qrc:/icons/power.png"
                onClicked: Qt.quit()
            }
            /*------------------------------------------------
            ToolButton {
                text: qsTr("<")
                onClicked: stack.pop()
            }

            Label{
                text: "Title"
                //elide: Label.ElideRight
                horizontalAlignment: Qt.AlignHCenter
                verticalAlignment: Qt.AlignVCenter
                Layout.fillWidth: true
            }

            ToolButton{
                text: qsTr(" ")
                onClicked: Menu.open()
            }
            */

        }
    }
    /*
    RowLayout{
        spacing: 115
        anchors.fill:parent
        anchors.margins: 70
    }
    */
    RowLayout{
        //把复用的slider放在布局里面
        height: 150//布局的高度，如果不赋值就会默认读取子控件的值
        Repeater{
            model: 7
            Slider{
                //对象自动填满布局
                Layout.fillHeight: true
                Layout.fillWidth: true
                orientation: Qt.Vertical//垂直
                from: 0
                to:100
                value:10//当前默认值设置
            }

        }

    }
}
