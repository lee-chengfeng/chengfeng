import QtQuick 2.0

Rectangle{
    //需要给对象发信号
    id:rect2
    width: 80
    height: 80
    color: "lightgreen"
    radius: 10

    Text {
        anchors.centerIn: parent
        font.pointSize: 12
        text: "信号处理"
    }
//以下代码错误，未找出原因，在下面重写就好了
//    MouseArea{
//        anchors.fill: parent
//        onClicked: PropertyAction{
//            target: rect2               //动画应用于标识rect2的矩形
//            property: "y"               //y轴方向运动的动画
//            from: 30                    //起点
//            to: 300                     //终点
//            duration: 3000              //运动事件，单位毫秒
//            loops:3                     //运动三个周期
//            easing.type:Easing.Linear   //匀速现行运动
//        }
//    }
    MouseArea{
        anchors.fill: parent
        onClicked: PropertyAnimation{
            target: rect2               //动画应用于标识rect2的矩形
            property: "y"               //y轴方向运动的动画
            from: 30                    //起点
            to: 90                      //终点
            duration: 3000              //运动事件，单位毫秒
            loops: 3                    //运动三个周期
            easing.type: Easing.Linear  //匀速线性运动
        }
    }
}
