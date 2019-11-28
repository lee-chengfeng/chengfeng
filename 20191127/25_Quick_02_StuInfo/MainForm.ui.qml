import QtQuick 2.7
import QtQuick.Layouts 1.3
import QtQuick.Controls 2.4
import QtQuick.Controls 1.4
Item {
    width: 640
    height: 480
    //定义别名，在main.qml中引用

    property alias name:name
    property alias age:age
    //property alias sex:sexGroup
    property alias spec:speCBox
    property alias hobby:hobbyGrid
    property alias submit:submit
    property alias details:stuInfo

    RowLayout{
        x:50;y:35

        spacing: 10
        ColumnLayout{
            spacing: 8
            RowLayout{
                spacing: 0
                Label{//Label对应的是control
                    text: "姓名"
                }
                TextField{
                    id:name
                    placeholderText: qsTr("请输入...")//当文本框内容为空的时候显示的内容，引导用户操作
                    focus:true
                }
            }
            RowLayout{
                spacing: 0
                Label{
                    text:"年龄"
                }
                TextField{
                    id:age
                    //下面这句话不解其意；validator-验证器，只有输入的字符符合要求的时候才能被文本框接受
                    validator: IntValidator{//整形验证器
                        bottom: 16;top:26
                    }
                }
            }
            GroupBox{
                id:group1
                title:qsTr("性别")
                Layout.fillWidth: true//如果此属性为true，则在遵守给定约束的情况下，项目将尽可能宽。
                //quick里面的ColumnLayout RowLayout GridLayout同qml中的Column Row Grid,但quick定位功能更加强大
                RowLayout{
                    //control1.4支持
                    //只在某一组里面的单选按钮，只有一个能够被选中，互斥选项组
                    ExclusiveGroup {
                        id: sexGroup
                    }
                    RadioButton{
                        text: qsTr("男")
                        checked: true
                        exclusiveGroup: sexGroup
                        //exclusiveGroup:sexGroup//这一行属性不支持,在建立execlusivegroup对象之后可以显示
                        Layout.minimumWidth: 65
                    }
                    RadioButton{
                        text: qsTr("女")
                        exclusiveGroup:sexGroup
                        Layout.minimumWidth: 65
                    }
                }
            }
            RowLayout{
                spacing: 0
                Label{
                    text: "专业"
                }
                ComboBox{
                    id: speCBox
                    Layout.fillWidth: true
                    currentIndex: 0
                    model: ListModel{
                        ListElement{
                            text: "计算机"
                        }
                        ListElement{
                            text: "通信工程"
                        }
                        ListElement{
                            text: "信息网络"
                        }
                    }
                    //另一种写法：
                    //model: ["计算机","通信工程","信息网络"]
                    width: 200
                }
            }
            GroupBox{
                id: group2
                title: qsTr("爱好")

                Layout.fillWidth: true
                GridLayout{
                    id: hobbyGrid
                    columns: 3
                    CheckBox{
                        text: qsTr("旅游")
                        checked:true
                    }
                    CheckBox{
                        text: qsTr("游泳")
                        checked:true
                    }
                    CheckBox{
                        text: qsTr("篮球")
                    }
                    CheckBox{
                        text: qsTr("唱歌")
                    }
                    CheckBox{
                        text: qsTr("跳舞")
                    }
                    CheckBox{
                        text: qsTr("网购")
                    }
                    CheckBox{
                        text: qsTr("看电视")
                        checked:true
                    }
                    CheckBox{
                        text: qsTr("其他")
                        checked:true
                    }
                }
            }
            Button{
                id: submit
                anchors.right: group2.right
                text: "提交"
            }
        }
        ColumnLayout{
            Layout.alignment: Qt.AlignTop
            Label{
                text: "基本信息"
                font.pixelSize: 15//像素点大小
                font.bold: true
            }
            TextArea{
                id: stuInfo
                Layout.fillHeight: true
                width: 240
                text: "学生个人资料..."
                font.pixelSize: 14
            }
        }
    }
}
