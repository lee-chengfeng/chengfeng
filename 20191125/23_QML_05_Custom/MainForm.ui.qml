import QtQuick 2.4

//Item {
//    width: 400
//    height: 400
//}


Rectangle{
    property alias mouseArea:mouseArea
    width: 360
    height: 360

    MouseArea{
        id:mouseArea
        anchors.fill:parent
    }
    Button{
        x:25;y:25
    }
}
