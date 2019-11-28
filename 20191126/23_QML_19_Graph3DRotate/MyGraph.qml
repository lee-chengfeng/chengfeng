import QtQuick 2.0

Rectangle{
    width: animg.width
    height: animg.height
    transform: Rotation{
        //设置原点
        origin.x: animg.width/2
        origin.y: animg.height/2
        axis{
            x:0
            y:1//围绕y轴进行旋转
            z:0
        }
        //定义角度angle上的动画
        NumberAnimation on angle{
            from: 0
            to: 360
            duration: 20000
            loops:Animation.Infinite
        }
    }

    AnimatedImage{
        id: animg
        source: "image/desktop.jpg"
    }
}
