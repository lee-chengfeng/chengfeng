import QtQuick 2.4

//Item {
//    width: 400
//    height: 400
//}
Rectangle {
    property alias mouseArea: mouseArea

    width: 3840 / 4
    height: 2400 / 4
    MouseArea {
        id: mouseArea
        anchors.fill: parent
    }
    Image {
        //这里的坐标是相对于父窗口的
        x: 0
        y: 0
        width: 3840 / 4
        height: 2400 / 4
        source: "image/Hummingbird_by_Shu_Le.jpg"
        //source: ":/image/Hummingbird_by_Shu_Le.jpg"//这里的:/去除，否则格式不识别
        fillMode: Image.PreserveAspectCrop//当图片属性与设置属性不一致的时候如何处理？图像按比例缩放以填充，必要时裁剪
        clip: true
    }
}
/*
clip: true
此属性保存是否启用裁剪。 默认剪辑值为false。
如果启用了剪切，则一个项目会将其自己的画以及其子对象的画剪切到其边界矩形。
*/
