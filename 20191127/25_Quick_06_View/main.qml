import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.Controls 2.4
import QtQuick.Dialogs 1.2


ApplicationWindow {
    visible: true
    width: 640
    height: 480
    title: qsTr("世界艺术珍品")

    MainForm{
        anchors.fill: parent
        //信号，单机选项列表执行的代码
        tableView.onClicked:{
            //把tablebiew中的索引给到tabview，改变当前显示的tab
            tabView.currentIndex = tableView.currentRow;//这里无法识别Error: Cannot assign to non-existent property "currentIndex"，改为使用变量的方案---错误的原因：把tableview tabview的名字弄混了
            //var index = tableView.currentRow;
            //改变当前的source
            scrolimg.source = "images/" + tabView.getTab(tabView.currentIndex).title + ".jpg";
        }
        //切换Tab视图选项只想的代码
        tabView.onCurrentIndexChanged:{
            tableView.selection.clear();
            tableView.selection.select(tabView.currentIndex);
            scrolimg.source = "images/" + tabView.getTab(tabView.currentIndex).title + ".jpg"
        }
    }

}
/*
var类型是通用属性类型，可以引用任何数据类型。
它等效于常规JavaScript变量。 例如，var属性可以存储数字，字符串，对象，数组和函数：
 */
