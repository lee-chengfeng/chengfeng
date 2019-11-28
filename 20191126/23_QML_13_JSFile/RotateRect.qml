import QtQuick 2.0

import "myscript.js" as Logic

Rectangle{
    id:rect
    width: 60
    height: 60

    gradient: Gradient{
        GradientStop{
            position: 0.0
            color: "green"
        }
        GradientStop{
            position: 0.3
            color: "blue"
        }
        GradientStop{
            position: 1.0
            color: "red"
        }
    }

    Behavior on rotation {
        RotationAnimation{
            direction: RotationAnimation.Clockwise
        }
    }

    MouseArea{
        anchors.fill: parent
        //使用导入的js文件中定义的javascript
        onClicked: rect.rotation = Logic.getRandomNumber();
    }
}
