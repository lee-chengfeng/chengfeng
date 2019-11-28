import QtQuick 2.0

Rectangle{
    id:rect
    width: 60
    height: 60
    gradient: Gradient{
        GradientStop{
            position: 0.0;color: "yellow"
        }
        GradientStop{
            position: 0.33;color: "blue"
        }
        GradientStop{
            position: 1.0;color: "aqua"
        }
    }
    //定义javascript函数，返回随机旋转的角度
    function getRandomNumber(){
        return Math.random()*360;
    }
    //这个行为的含义是什么？
    Behavior on rotation {
        RotationAnimation{
            //方向：旋转动画.顺时针
            direction: RotationAnimation.Clockwise
        }
    }
    //鼠标区域指定，并指定事件
    MouseArea{
        anchors.fill:parent
        //*****
        onClicked: rect.rotation = getRandomNumber();//单击事件中调用javascript函数
    }
}
