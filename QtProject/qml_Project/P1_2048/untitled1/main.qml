import QtQuick 2.15  //QtQuick 提供了QML引擎和语言基础结构所以在qml代码中必须添加该库
import QtQuick.Window 2.15 //提供顶级窗口的库,新建好工程后默认会使用其中的Window组件
import QtQuick.Controls 2.5 //模块提供了大量类似Qt Widgets模块的可重用组件

Window {
    width: 480 // 窗口宽度
    height: 640 //窗口高度
    maximumHeight: 640 //最大窗口高度
    maximumWidth: 480 //最大窗口宽度
    minimumHeight: 640 //最小窗口高度
    minimumWidth: 480 //最小窗口宽度
    visible: true // 窗口是否可见
    // qstr 将括号内的字符串本地化为当前语言环境。当应用程序需要支持多种语言时，可以使用此函数来提供不同语言的翻译文本。
    title: qsTr("2048") // 设置左上角窗口标题
    color: "white" // 设置窗口背景颜色

    ScoreRec{ // 记分版 自定义控件
        id: socre_page
        x: 30
        y: 60
    }

    HostRectangle{  //自定义控件
        id:host_page
        //x:30
        y:200
        anchors.horizontalCenter: parent.horizontalCenter
    }

}
