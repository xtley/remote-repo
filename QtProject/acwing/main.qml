import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.15
Window {
    width: 1040
    height: 800
    visible: true
    title: qsTr("acwing")
    Image {
        id: bg1
        anchors.horizontalCenter: parent.horizontalCenter/*居中*/
        //fillMode: Image.PreserveAspectFit/*保持原始横纵比*/
        width: parent.width
        height: parent.height
        source: 'images/background.png'
    }

    Rectangle {
        id: rect1
        x: 0+parent.width/2-width/2
        y: parent.height*0.06
        width: parent.width*0.7
        height: parent.height*0.85
        color: "white"
        Text {
            x: 10
            y: 15
            id: text1
            antialiasing: true
            text: "算法提高课"
            color: Qt.rgba(13/255,113/255,187/255)
            font.pointSize: 18
        }
        Button {
            id: btn1
            width: text1.width*0.7
            height: text1.height
            x: text1.x+text1.width+20
            y: text1.y
            antialiasing: true
            Rectangle {
                id: btn1_rec1
                color: Qt.rgba(92/255,184/255,92/255) // 设置背景颜色为蓝色
                radius: 6 // 圆角半径
                anchors.fill: parent // 填充整个按钮
            }
            Text {
                text: "进行中"
                color: "white" // 文本颜色为白色
                font.pixelSize: Math.min(parent.width,parent.height)/2  // 字体大小为16像素
                anchors.centerIn: parent
            }
        }
        ProjectBar {
            x: text1.x
            y: text1.y+100
            chapter_name: "第一章 动态规划"
            pos: 0
        }
//        ProjectBar {
//            x: text1.x
//            y: text1.y+100+1*height
//            chapter_name: "第二章 搜索"
//            pos: 1
//        }
//        ProjectBar {
//            x: text1.x
//            y: text1.y+100+2*height
//            chapter_name: "第三章 图论"
//            pos: 2
//        }
//        ProjectBar {
//            x: text1.x
//            y: text1.y+100+3*height
//            chapter_name: "第四章 高级数据结构"
//            pos: 3
//        }
//        ProjectBar {
//            x: text1.x
//            y: text1.y+100+4*height
//            chapter_name: "第五章 数学知识"
//            pos: 4
//        }
//        ProjectBar {
//            x: text1.x
//            y: text1.y+100+5*height
//            chapter_name: "第六章 基础算法"
//            pos: 5
//        }

    }
}
