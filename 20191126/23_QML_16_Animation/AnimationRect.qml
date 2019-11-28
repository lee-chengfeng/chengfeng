import QtQuick 2.9

Rectangle{
    width: 100
    height: 100
    color: "green"
    //XAnimator在2.7里面 2.0还没有
    ScaleAnimator on scale {
        from: 0.1
        to: 1
        duration: 7000
        loops: Animator.Infinite
    }

//x轴方向位移
    XAnimator on x{
        from: 10
        to: 100
        duration: 7000

        loops: Animator.Infinite
    }
//y轴方向位移
    YAnimator on y{
        from: 10
        to: 100
        duration: 7000
        loops: Animator.Infinite
    }
//缩放动画实现？？？没有效果
//    ScaleAnimator on scale {
//        from: 0.1
//        to: 1
//        duration: 7000
//        //在这里Animation  Animator两者的区别是什么？
//        loops: Animator.Infinite
//    }
//旋转动画实现
    RotationAnimation on rotation {
        from: 0
        to: 360
        duration: 7000
        loops: Animator.Infinite
    }
//透明度实现
    OpacityAnimator on opacity {
        from: 0
        to: 1
        duration: 7000
        loops: Animator.Infinite
    }

}
