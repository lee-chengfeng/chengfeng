import QtQuick 2.0

Circle {
    id:sender
    property int counter:0      //创建一个属性，初始化为0
    signal send(string value)
    property Receiver target: null//创建一个Receiver属性，名字是target，值为空;也可以说target的属性是receiver
    //property type name: value
    //当target的值发生改变的时候，将sender的send信号连接到target的槽函数上
    onTargetChanged: {
        send.connect(target.receive);
    }
    MouseArea{
        anchors.fill: parent//让点击时间在整个窗口有效
        onClicked: {//当click的时候发送send信号，同时改变值
            sender.counter++;
            sender.send(counter);
        }
        //当按钮按下的时候sender改为蓝色，抬起的时候改为红色
        onPressed: {
            sender.circleColor = "blue";
        }
        onReleased: {
            sender.circleColor = "red";
        }
    }

}
