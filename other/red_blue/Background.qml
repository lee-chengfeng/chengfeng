import QtQuick 2.0

Item {

    //定义一个给circle加宽的事件，然后在sender和receiver里面分别给事件赋值
    property Circle target: null
    focus: true//不明白什么意思？？？
    Keys.onPressed: {
        if(event.key===Qt.Key_Plus)
        {
            target.width+=10;
        }else if(event.key===Qt.Key_Minus)
        {
            target.width-=10;
        }
    }



    Rectangle {
        id: background
        color: "#abecd6"
        gradient: Gradient {
            GradientStop {
                position: 0
                color: "#abecd6"
            }

            GradientStop {
                position: 1
                color: "#fbed96"
            }
        }
        anchors.fill: parent
    }

}
