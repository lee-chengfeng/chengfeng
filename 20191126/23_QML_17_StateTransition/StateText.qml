import QtQuick 2.0

Text {
    id: stext
    color: "grey"
    font.family: "Helvetica"
    font.pointSize: 12
    font.bold: true//加粗
    MouseArea{
        id:mArea
        anchors.fill: parent
    }

    states: [//注意这里的属性用方括号,方括号里面是元素的所有状态的列表，如果只有一个状态则方括号可以省略
        State {
            //状态的名字，具备唯一性，默认为空
            name: "highlight"
            //当按下鼠标的时候进行状态改变
            when: mArea.pressed
            //状态对象，指定被改变的属性
            PropertyChanges {
                target: stext
                color: "red"
                font.pointSize: 25
                style: Text.Raised
                styleColor: "red"

            }
        }
    ]
    //动画周期
    transitions: [
        Transition {
            PropertyAnimation{
                duration: 1000
            }
        }
    ]
}
