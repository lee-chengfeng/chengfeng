import QtQuick 2.7
import QtQuick.Layouts 1.3
import QtQuick.Controls 2.4
import QtQuick.Controls 1.3

Item {
    width: 780
    height: 320

    property alias tableView: tableView     //TableViews视图-左
    property alias tabView: tabView         //TableView视图-中
    property alias scrolimg: scrolimg       //TableView-右
    RowLayout {
        anchors.fill: parent
        SplitView {
            anchors.fill: parent
            //不明白这个的为什么是无效的属性
            //orientation: Qt.Horizontal
            TableView {//关于图片名称与图片作者的信息，行显示
                id: tableView
                width: 300
                TableViewColumn {
                    role: "title"//这里的title需要添加引号，否则绑定不上listmodel中定义的对象,model/view框架
                    title: "名称"
                    horizontalAlignment: Text.AlignHCenter
                    width: 100
                }
                TableViewColumn {
                    role: "author"
                    title: "作者"
                    horizontalAlignment: Text.AlignHCenter
                    width: 200
                }
                model: libraryModel
            }
            TabView {//Tab切换视图
                id: tabView//视图标识
                width: 215
                height: 300
                Tab {
                    //选项页
                    title: "蒙娜丽莎"//选项页的标签文本
                    Image {//选项页需要载入的图片

                        source: "images/蒙娜丽莎.jpg"
                    }
                }
                Tab {
                    title: "大卫"
                    Image {
                        source: "images/大卫.jpg"
                    }
                }
                Tab {
                    title: "圣母"
                    Image {
                        source: "images/圣母.jpg"
                    }
                }
            }
            ScrollView {//单独页面视图，默认显示蒙娜丽莎
                Image {
                    id: scrolimg
                    source: "images/蒙娜丽莎.jpg"
                }
            }
        }
    }
    ListModel{//给title author中添加元素
        id: libraryModel
        ListElement{        //定义列表，列表元素在ListModel定义内定义，并表示将使用ListView或Repeater项目显示的列表中的项目。
            title: "蒙娜丽莎"//数据项  与title绑定
            author: "达 芬奇"//数据项 与author绑定
        }
        ListElement{
            title:"大卫"
            author:"米开朗基罗"
        }
        ListElement{
            title: "圣母"
            author:"拉斐尔"
        }
    }
}
