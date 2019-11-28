import QtQuick 2.0

import QtGraphicalEffects 1.0

Rectangle{

    width: animg.width
    height: animg.height
    AnimatedImage{
        id:animg
        source: "movie/150120.gif"
    }

    BrightnessContrast{
        id:bright
        anchors.fill: animg
        source: animg
    }

    SequentialAnimation{
        id: imgAnim
        NumberAnimation{
            target: bright
            property: "brightness"//变暗
            to: -0.5
            duration: 3000
        }
        NumberAnimation{
            target: bright
            property: "contrast"//增加对比度
            to: 0.25
            duration: 2000
        }
    }

    MouseArea{
        anchors.fill: parent
        onClicked: {
            imgAnim.running = true//单机图像开启动画
        }
    }
}
