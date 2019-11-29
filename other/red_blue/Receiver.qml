import QtQuick 2.0

Circle {//recerver继承至circie
    id:receiver
    circleColor: "#7544e6"
    function receive(value)//recerver的槽函数，当触发的时候内容改变
    {
        contantText = value;
        colornotify.running = true //当槽函数触发的时候启动动画
    }
    SequentialAnimation on circleColor {
        id:colornotify
        running: false//不希望一开始就有动画
        //如果是渐变色，动画效果不执行；如果希望两个按钮动画不同，可以设置两组动画
        ColorAnimation {//建立两个动画效果
            from: "red"
            to: "blue"
            duration: 200
        }
        ColorAnimation {
            from: "blue"
            to: "red"
            duration: 200
        }
    }
}
