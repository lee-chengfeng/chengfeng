import QtQuick 2.4

Rectangle{
    property alias rect4:rect4

    width: 360
    height: 360
    property alias textEdit: textEdit
    property alias mouseArea: mouseArea

    MouseArea{
        id:mouseArea
        anchors.fill:parent
    }

    TextEdit{
        id:textEdit
        visible: false
    }

    Column{
        x:50;y:50
        spacing: 5
        Rect1{

        }
        Rect2{

        }
        Rect3{

        }
        Rect4{
            id:rect4
        }

    }

}
