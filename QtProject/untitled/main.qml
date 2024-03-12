import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.5  //添加 控件
Window {
    width: 640
    height: 480
    visible: true  // 窗口是否可见
    title: qsTr("Hello World")
    // x: 相对于父控件的坐标 左上角 坐标为(0,0)
    // y:
   /* minimumWidth: 400
    minimumHeight: 300
    maximumWidth: 500
    maximumHeight: 300*/  //修改最小和最大的高度和宽度 初始化 最大
    opacity: 1 // 0 - 1 默认1不透明

    signal mySig()   // <--信号与槽函数
    onMySig: {

    }  // -->

    onWidthChanged: { //系统自带的槽函数
        console.log("width",width);
    }

    Button {
        id: btn1
        width: 50
        height : 50
        objectName: "btn1"
        background: Rectangle {
            border.color: btn1.focus ? "blut" :"black"
        }
        onClicked: {
            console.log("btn1 clidked")
        }
        Keys.onRightPressed: {
            btn1.focus = true   //是否接受键盘鼠标事件
        }
    }

    Button {
        id: btn2
        x: 100
        width: 50
        height : 50
        objectName: "btn2"
        background: Rectangle {
            border.color: btn2.focus ? "blut" :"black"
        }
        onClicked: {
            console.log("btn2 clidked")
        }
        Keys.onRightPressed: {
            btn1.focus = true   //是否接受键盘鼠标事件
        }
    }
    onActiveFocusItemChanged: {
        console.log("active focus item changed",activeFocusItem,"object name: ",a)
    }

}
