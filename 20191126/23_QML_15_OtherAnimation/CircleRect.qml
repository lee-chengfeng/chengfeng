import QtQuick 2.0

Rectangle{
    width: 80
    height: 80
    //颜色变化动画
    ColorAnimation on color{
        from: "blue"
        to: "aqua"
        duration: 10000
        loops: Animation.Infinite
    }
    //旋转动画
    RotationAnimation on rotation {
        from: 0
        to: 360
        duration: 10000
        direction: RotationAnimation.Clockwise
        loops: Animation.Infinite
    }
    //圆角动画
    NumberAnimation on radius {
        from: 0
        to: 40

        duration: 10000
        loops: Animation.Infinite
    }
    //x轴位移动画
    PropertyAnimation on x{
        from: 50
        to: 500
        duration: 10000
        loops: Animation.Infinite
        easing.type: Easing.InOutBack
    }
}
