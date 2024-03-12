import QtQuick 2.15

Rectangle {
    width: parent.width
    height: 10+question_cnt*parent.height*0.10
    anchors.horizontalCenter: parent.horizontalCenter
    property int question_cnt: 0
    Text {
        x: 20
        y: 10
        id: question_type
        text: "数字三角形模型"
        font.pointSize: 18
        color: Qt.rgba(119/255,136/255,153/255)
    }
    Question_Link {
        x: parent.width*0.2
        y: 10
        property string topic_title: "AcWing 1015. 摘花生"
    }
    Question_Link {
        x: parent.width*0.2
        y: 10+1*height
        property string topic_title: "AcWing 1018. 最低通行费"
    }
    Question_Link {
        x: parent.width*0.2
        y: 10+2*height
        property string topic_title: "AcWing 1027. 方格取数"
    }
    Question_Link {
        x: parent.width*0.2
        y: 10+3*height
        property string topic_title: "AcWing 275. 传纸条"
    }

}
