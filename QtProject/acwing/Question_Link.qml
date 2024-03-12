import QtQuick 2.15

Rectangle {
    id: myRect
    width: parent.width*0.78
    height: 30
    color: "white"
    //anchors.right: parent.right
    Rectangle {
        id: bottom
        y: parent.height-1
        width: parent.width
        height: 1
        color: Qt.rgba(220/255,220/255,220/255)
    }

    Text {
        id: myText
        text: topic_title
        y: 1
        anchors.left: parent
        font.pixelSize: 18
        color: Qt.rgba(51/255,122/255,183/255) // 设置背景颜色为蓝色
        Rectangle {
            id: myunderline
            y: parent.height
            width: parent.width
            height: 0
            color: Qt.rgba(51/255,122/255,183/255) // 设置背景颜色为蓝色
        }
    }
    MouseArea {
        anchors.fill: parent
        hoverEnabled: true
        onEntered: {
            myRect.opacity = 0.8
            myRect.color = Qt.rgba(238/255,238/255,238/255)
            myunderline.height= 1
        }
        onExited: {
            myRect.opacity = 1
            myRect.color = "white"
            myunderline.height= 0
        }
    }
}
