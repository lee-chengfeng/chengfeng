import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.Controls 2.4

//window需要倒入window;ApplicationWindow需要倒入controls
ApplicationWindow{
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    MainForm{
        anchors.fill: parent
        size.onValueChanged: {
            var scale = size.value//获取缩放比例
            img.width = 614.4*scale
            img.height = 384*scale
        }
        colourful.onCheckedChanged: {//切换彩色与黑白色
            desat.desaturation = colourful.checked ? 0.0 : 1.0
        }
        btn.onClicked: {//灰度小于0继续增大，灰度大于0.9就重新便会彩色
            if(desat.desaturation < 0.9){
                desat.desaturation += 0.1
            }else{
                desat.desaturation = 0.0//重新变回彩色
            }
            progreBar.value = desat.desaturation;//进度条的进度与灰度同步改变
        }
    }
}
