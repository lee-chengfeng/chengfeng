import QtQuick 2.4

Rectangle {
    property alias mouseArea: mouseArea

    width: 200
    height: 200
    MouseArea {
        id: mouseArea
        anchors.fill: parent
    }
    /*
    Flow {
        anchors.fill: parent
        anchors.margins: 15 //元素与窗口左上角的距离是15个像素
        //设置组件之间的间距
        spacing: 5

        //一下添加flow定位的成员
        RedRectangle {
        }
        BlueRectangle {
        }
        GreenRectangle {
        }
    }

    Row{
        x:25;y:25
        spacing:10
        layoutDirection: Qt.RightToLeft//使元素从右向左进行排列
        RedRectangle {
        }
        BlueRectangle {
        }
        GreenRectangle {
        }

    }

    //默认是垂直排列
    Column{
        x:25;y:25
        spacing:2
        //layoutDirection: Qt.RightToLeft//使元素从右向左进行排列
        RedRectangle {
        }
        BlueRectangle {
        }
        GreenRectangle {
        }

    }
    */
    Grid{
        x:140;y:120
        //从左往右排，设置5列，列满就换行
        columns: 5
        spacing:5
        //layoutDirection: Qt.RightToLeft//使元素从右向左进行排列
        RedRectangle {
        }
        RedRectangle {
        }
        RedRectangle {
        }
        RedRectangle {
        }
        RedRectangle {
        }
        RedRectangle {
        }
        RedRectangle {
        }
        RedRectangle {
        }
        RedRectangle {
        }
    }
}
