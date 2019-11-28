import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.Controls 2.4
import QtQuick.Dialogs 1.2
//案例提交没有成功，后续在进一步的查找问题原因
ApplicationWindow {
    visible: true
    width: 640
    height: 480
    title: qsTr("StuInfo")

    MainForm{
        anchors.fill: parent
        //提交被点击时候的动作,先遍历兴趣爱好，然后在拼接字符串
        submit.onClicked: {
            var hobbyText = "";
            for(var i = 0;i<7;i++){
                //生成学生兴趣爱好文本,children表示子对象，利用for循环遍历子对象
                hobbyText += hobby.children[i].checked?(hobby.children[i].text + "、"):"";
            }
            if(hobby.children[7].checked){
                hobbyText += "...";
            }
            //最终生成完整学生信息
            details.text = "我的名字叫" + name.text + ",是个" + age.text + "岁" + sex.current.text + "生，所学专业是"
                    + spec.currentText + ",业余喜欢" + hobbyText;
            //detail.text = "我的名字叫" + name.text + ",是个" + age.text + "岁"  + "生，所学专业是"
                    //+ spec.currentText + ",业余喜欢" + hobbyText;
        }
    }
}
