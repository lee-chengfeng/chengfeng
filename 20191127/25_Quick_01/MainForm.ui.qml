import QtQuick 2.4
import QtQuick.Layouts 1.3
import QtQuick.Controls 2.4


Item {
    width: 640
    height: 480

    property alias button1:button1
    property alias button2:button2
    //import QtQuick.Layouts---RowLayout
    RowLayout{
        anchors.centerIn: parent
        //import QtQuick.Controls---Button
        Button{
            id:button1
            text: qsTr("press me 1")
        }
        Button{
            id:button2
            text: qsTr("press me 2")
        }
    }
}
