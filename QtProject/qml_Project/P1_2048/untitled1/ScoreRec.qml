import QtQuick 2.15

Rectangle {
    property int scr // property 用于定义变量
    Column{
        Text {  // 文本控件
            id: record_font
            font.family: "微软雅黑"  //字体家族
            antialiasing: true //用于抗锯齿
            font.pointSize: 20 //字体大小
            text: qsTr("历史记录：") // 显示的界面上的字体
            color: "black" //字体颜色
        }

        Text {
            id: score_font
            font.family: "微软雅黑"
            antialiasing: true
            font.pointSize: 20
            text: qsTr("分数：")
            color: "black"
        }

    }

}
