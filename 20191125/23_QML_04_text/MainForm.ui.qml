import QtQuick 2.4


Rectangle{

    property alias mouseArea :mouseArea
    width: 900
    height: 900
    MouseArea{
        id: mouseArea
        anchors.fill:parent
    }
/*
font-family 是规定一个字体列表，从左至右顺序从系统中检索，如果检索到了则使用，否则继续检索下一个，直到全部检索不到才使用系统默认字体（Windows中文版下就是宋体）。
Helvetica是一种被广泛使用的的西文字体
*/
    Text {
        x: 60
        y: 100
        color: "green"
        font.family: "Helvetica"
        font.pointSize: 24
        text: "hello Qt Quick!"
    }

    Text {
        x: 60
        y:140
        color: "green"
        font.family: "Helvetica"
        font.pointSize: 24
        text: "<b>Hello</b> <i>Qt Quick!</i>"
        //在进行html类型标记定义富文本的时候，字体属性根据富文本定义的格式进行变化  b应为加粗  i应为斜体
    }

    Text {
        x: 60
        y:180
        color: "green"
        font.family: "Helvetica"
        font.pointSize: 24
        //text-outline 属性规定文本轮廓。 轮廓风格是红色
        style: Text.Outline;styleColor: "red"
        text: "Hello Qt Quick!"
    }

    Text {
        width:200
        color: "green"
        font.family: "Helvetica"
        font.pointSize: 24
        horizontalAlignment: Text.AlignLeft
        verticalAlignment: Text.AlignTop
        //设置省略方式，多出的部分右边省略
        elide: Text.ElideRight
        text: "Hello Qt Quick!"
    }

    Text {
        width:200
        y: 30
        color: "green"
        font.family: "Helvetica"
        font.pointSize: 24
        horizontalAlignment: Text.AlignLeft
        //若不省略，则设置在单词字母的边界换行
        wrapMode: Text.WrapAnywhere
        text: "Hello Qt Quick!"
    }

}
/*
(a) text: "<b>Hello</b> <i>Qt Quick!</i>"：Text元素支持用HTML类型标记定义富文本，它有一个textFormat属性，默认值为Text.RichText（输出富文本）；若显式地指定为Text.PlainText，则会输出纯文本（连同HTML标记一起作为字符输出）。
(b) style: Text.Outline;styleColor:"blue"：style属性设置文本的样式，支持的文本样式有Text.Normal、Text.Outline、Text.Raised和Text.Sunken；styleColor属性设置样式的颜色，这里是蓝色。
(c) elide:Text.ElideRight：设置省略文本的部分内容来适合Text的宽度，若没有对Text明确设置width值，则elide属性将不起作用。elide可取的值有Text.ElideNone（默认，不省略）、Text.ElideLeft（从左边省略）、Text.ElideMiddle（从中间省略）和Text.ElideRight（从右边省略）。
(d) wrapMode:Text.WrapAnywhere：如果不希望使用elide省略显示方式，还可以通过wrapMode属性指定换行模式，本例中设为Text.WrapAnywhere，即只要达到边界（哪怕在一个单词的中间）都会进行换行；若不想这么做，可设为Text.WordWrap只在单词边界换行。
*/
