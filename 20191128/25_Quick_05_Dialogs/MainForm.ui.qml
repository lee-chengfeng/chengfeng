import QtQuick 2.9
import QtQuick.Layouts 1.2
import QtQuick.Controls 2.4

Item {
    property alias date: date
    property alias btnSelect: btnSelect
    property alias file: file
    property alias btnOpen: btnOpen
    property alias content: content
    property alias btnFont: btnFont
    property alias btnColor: btnColor

    width: 320
    height: 280

    ColumnLayout {
        anchors.centerIn: parent

        RowLayout {
            Label {
                text: "日期"
            }
            TextField {
                id: date
            }
            Button {
                id: btnSelect
                text: qsTr("选择...")
            }
        }
        RowLayout {
            Label {
                text: "文件"
            }
            TextField {
                id: file
            }
            Button {
                id: btnOpen
                text: qsTr("打开...")
            }
        }
        TextArea {
            id: content
            Layout.fillWidth: true
            text: "我喜欢Qt Quick编程"
            font.pixelSize: 14
        }
        RowLayout {
            Layout.alignment: Qt.AlignRight

            Button {
                id: btnFont
                text: qsTr("字体...")
            }
            Button {
                id: btnColor
                text: qsTr("颜色...")
            }
        }
    }
}
