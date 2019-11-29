import QtQuick 2.0

Item {
    width: 200
    height: 200
    property alias circleColor: circle.color
    property alias contantText: contant.text

    Rectangle {
        id: circle
        color: "#612cdb"
        radius: width*0.5
        anchors.fill: parent

        Text {
            id: contant
            x: 88
            y: 79
            color: "#fafafa"
            text: qsTr("Text")
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.verticalCenter: parent.verticalCenter
            font.pixelSize: 20
        }
    }

}
