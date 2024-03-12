import QtQuick 2.15
import QtQuick.Controls 2.15
Rectangle {
    width: parent.width*0.97
    height: parent.height*0.10
    anchors.horizontalCenter: parent.horizontalCenter
    property string chapter_name: ""
    property int pos: 0
    Rectangle {
        width: parent.width
        height: parent.height
        MouseArea {
            anchors.fill: parent
            onClicked: {
                rect3.visible= !rect3.visible
            }
        }
        Rectangle {
            id: rect1
            width: parent.width
            height: parent.height/2
            color: Qt.rgba(252/255,248/255,227/255)
            Text {
                x: 15
                text: chapter_name
                font.pointSize: 18
                anchors.verticalCenter: parent.verticalCenter
                color: Qt.rgba(138/255,113/255,79/255)
            }
        }
        Rectangle {
            id: rect2
            y: rect1.y+parent.height/2
            width: parent.width
            height: parent.height/2
            color: "white"
            border.color: "yellow"

            Text {
                x: 15
                text: "包括数字三角形模型、最长上升子序列模型、背包模型、状态机、状态压缩DP、区间DP、树形DP、数位DP、单调队列优化DP、斜率优化DP等内容"
                font.pointSize: 12
                anchors.verticalCenter: parent.verticalCenter
            }
        }
    }

    Rectangle {
        id: rect3
        y: rect2.y+rect2.height
        width: parent.width*0.96
        height: (parent.parent.height-(parent.y+parent.height))*0.95
        anchors.horizontalCenter: parent.horizontalCenter
        color: "white"
        visible: true
        border.color: Qt.rgba(220/255,220/255,220/255)
        border.width: 1
        ClassificationList {
            y: rect.heightrect.y
        }

    }




}
