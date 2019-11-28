import QtQuick 2.7

Rectangle{
    //属性及别名；把一个对象的属性起别名，使得对象的属性可以在对象的外部进行访问
    property alias mouseArea: mouseArea   //MouseArea的属性别名
    property alias textEdit: textEdit     //TextEdit的属性别名

    width: 400
    height: 500

    MouseArea{
        id:mouseArea
        anchors.fill:parent                 //填充满父项，通过parent关键字访问父对象
    }

    TextEdit{
        id:textEdit
        text: qsTr("enter some text...")

        verticalAlignment: Text.AlignVCenter//设置垂直对其方式

        anchors.top: parent.top             //铆接到父窗口的顶端

        anchors.horizontalCenter: parent.horizontalCenter//水平居中到父窗口的中心
        anchors.topMargin: 20               //顶端空白
        Rectangle{                          //text中放置rectangle的意义是什么？只是为了整洁，把文本框在方框里面么？
            anchors.fill:parent             //填充满父项
            anchors.margins: -10            //边缘向外扩张10个宽度
            color: "transparent"            //透明颜色
            border.width: 1                 //边缘宽度
        }
    }

}
/*
  这里把MouseArea看成Rectangle的一个属性（QML中的子对象也可视为其父对象的属性），取其id（mouseArea）为属性名，并给它定义一个别名“mouseArea”，这样做的目的是为了在外部QML文档（main.qml）中也能访问到MouseArea。因为MouseArea内置了一个onClicked属性，它是一个回调（鼠标单击事件），定义了别名后，就可在main.qml代码中访问这个属性
  */

