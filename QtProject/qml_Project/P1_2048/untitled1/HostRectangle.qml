import QtQuick 2.15
import QtQuick.Controls 2.5

Rectangle{  // 创建矩形图形
    id:host
    width: 420
    height: width
    color: "gray"
    opacity: 1
    radius: 10  // 圆角半径（以像素为单位）

    property int mx
    property int my
    property int axis
    property int polar
    property int lbs
    property int score

    //var 与 property的区别
//    在 QML 中，var 用于声明一个变量并自动推断其类型，
//    而 property 用于声明对象属性，可以设置其类型和其他元数据（如读写权限、默认值等）。
//    Var 可以在函数内部或作为局部变量使用，而 property 必须在对象级别上声明。
    signal itemsig(var a)
    signal slide_left()
    signal slide_right()
    signal slide_up()
    signal slide_down()

    /*数据*/
    Item { // 基本视觉元素，表示屏幕上的矩形区域
        id: item
        property var itemArray:[0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0]
    }
    Text {
        id: score_number
        x:80
        y:-100
        font.pointSize: 20
        text: qsTr("0")
    }
    Text {
        id: max_number
        x:140
        y:-135
        font.pointSize: 20
        text: qsTr("0")
    }
    onScoreChanged: {
        score_number.text= score
    }
    Button{
        id:fina
//        anchors.horizontalCenter: parent.horizontalCenter
//        anchors.verticalCenter: parent.verticalCenter
        visible: false
        text: "重新开始"

        onClicked:{
            item.itemArray = {}
        }
    }
    /*布局格子*/
    Grid{
        id: layout_bottom  // 布局_底部
        anchors.centerIn: parent //一种布局属性，用于将一个元素居中对齐到另一个元素或父元素的中心点
        spacing: 4 //间距
        rows: 4 //行数
        columns: 4 //列数
        Repeater{ //一个重复器，其中包含一个模型为16的从属接收器。
            model:16 //重复执行其子项或子组件的次数为 16 次。
            SlaveRec{} //一个从属的接收器组件。
        }
    }


    /*随机方块*/
    RandomRec{
        id:rand
    }

    /*滑动检测*/
    MouseArea{ //提供有关鼠标事件的信息，例如单击、移动和滚动。它可用于检测用户与 QML 用户界面中的项目的交互，并触发相应的操作或行为。
        id:mousearea
        anchors.fill: parent //用于将一个组件填充父组件的所有空间。它会自动调整自身大小和位置来适应父组件的大小和位置。该属性通常用于在qml布局中实现自适应效果。
        onPressed:{ //一个交互事件，常用于按钮等控件上。当用户点击该控件时，该事件会被触发并执行其相关的操作。
            rand.state="hide" //关闭 QML 引擎中的随机数生成器。这可以提高应用程序的可重复性，因为随机数生成器的输出将不再受到系统时间、硬件配置等因素的影响。
            mx = mouseX //内置属性，它代表了当前鼠标在组件中的 x 轴坐标位置
            my = mouseY
        }
//        onClicked 与 onPressed 的区别
//        onClicked 只有在用户点击并释放按钮时触发，而 onPressed 在用户按下按钮时立即触发。
//        onClicked 不考虑用户是否移动了鼠标或手指，只有在点击位置不变时才触发，而 onPressed 则允许用户拖动鼠标或手指，同时也会持续触发。

        onClicked: {
            mx -= mouseX
            my -= mouseY
            axis = Math.abs(mx)>Math.abs(my)?mx:my
            polar = axis>0?1:0
            if((mx==0)&&(my==0)) return//点击不算做滑动
            if((axis==mx)&&(polar==1)) {
                slide_left()
                console.log("左划")
            }
            if((axis==mx)&&(polar==0)) {
                slide_right()
                console.log("右划")
            }
            if((axis==my)&&(polar==1)) {
                slide_up()
                console.log("上划")
            }
            if((axis==my)&&(polar==0)) {
                slide_down()
                console.log("下划")
            }
        }
    }

    /******************在空闲位置随机产生方块******************/
    property var freeArray:[0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0]
    property var rand_pos
    property var rand_num
    function random_rec(){
        var zero = 0
        for(var i=0;i<16;i++){//寻找空闲位
            if(item.itemArray[i] === 0){
                freeArray[zero] = i
                zero++
            }
        }
        if(zero !== 0){//仍有空位
            rand_pos = Math.floor(Math.random()*zero) // Math.floor 向下取整 Math.random()在0-1中生成随机数
            console.log("rand_pos:",rand_pos+1)
            rand_num = Math.pow(2,Math.floor(Math.random()*2)+1)
            item.itemArray[freeArray[rand_pos]] = rand_num
            console.log("rand_num:",rand_num)
            freeArray={}
        }else//无空位，退出
        {
            console.error("game over")
            console.error(score)
            //提示分数，刷新纪录，重新开始
            max_number.text = score
            //fina.visible = true
        }
    }

    /******************统一矩阵，简化算法*******************/
    function r_2_l(){//左右互换下标
        var i=0
        var dt0,dt1,dt2,dt3
        for(i;i<4;i++){
            dt0 = item.itemArray[0+i*4]
            dt1 = item.itemArray[1+i*4]
            dt2 = item.itemArray[2+i*4]
            dt3 = item.itemArray[3+i*4]
            item.itemArray[0+i*4] = dt3
            item.itemArray[1+i*4] = dt2
            item.itemArray[2+i*4] = dt1
            item.itemArray[3+i*4] = dt0
        }
    }
    function u_2_l(){//对角线互换下标
        var i=0
        var dt1,dt2,dt3,dt6,dt7,dt11
        dt1 = item.itemArray[1]
        dt2 = item.itemArray[2]
        dt3 = item.itemArray[3]
        dt6 = item.itemArray[6]
        dt7 = item.itemArray[7]
        dt11 = item.itemArray[11]
        item.itemArray[1] = item.itemArray[4]
        item.itemArray[2] = item.itemArray[8]
        item.itemArray[3] = item.itemArray[12]
        item.itemArray[6] = item.itemArray[9]
        item.itemArray[7] = item.itemArray[13]
        item.itemArray[11]= item.itemArray[14]
        item.itemArray[4] = dt1
        item.itemArray[8] = dt2
        item.itemArray[12]= dt3
        item.itemArray[9] = dt6
        item.itemArray[13]= dt7
        item.itemArray[14]= dt11
    }
    function d_2_l(mode){
        if(mode === "end"){//先左右，再对角线
            r_2_l()
            u_2_l()
        }
        if(mode === "start"){//先对角线，再                                                                                                                                                           左右
            u_2_l()
            r_2_l()
        }
    }
    /*************************缩进***********************/
    function move_retract(){
        var i=0


        for(i;i<4;i++){
            if(item.itemArray[0+i*4] === 0){  //==: 只判断数值,不比较类型 ===: 比较类型且判断数值
                item.itemArray[0+i*4] = item.itemArray[1+i*4]
                item.itemArray[1+i*4] = item.itemArray[2+i*4]
                item.itemArray[2+i*4] = item.itemArray[3+i*4]
                item.itemArray[3+i*4] = 0
            }
            if(item.itemArray[1+i*4] === 0){
                item.itemArray[1+i*4] = item.itemArray[2+i*4]
                item.itemArray[2+i*4] = item.itemArray[3+i*4]
                item.itemArray[3+i*4] = 0
            }
            if(item.itemArray[2+i*4] === 0){
                item.itemArray[2+i*4] = item.itemArray[3+i*4]
                item.itemArray[3+i*4] = 0
            }
        }
    }

    /***************************合并***********************/
    function add(){
        var i=0
        for(i;i<4;i++)
        {
            move_retract()
            if(item.itemArray[0+i*4]===item.itemArray[1+i*4]){//1=2
                item.itemArray[0+i*4] = 2*item.itemArray[0+i*4]
                score += item.itemArray[0+i*4]
                item.itemArray[1+i*4] = 0
                if(item.itemArray[2+i*4]===item.itemArray[3+i*4]){//3=4
                    item.itemArray[1+i*4] = 2*item.itemArray[2+i*4]
                    score += item.itemArray[1+i*4]
                    item.itemArray[2+i*4] = 0
                    item.itemArray[3+i*4] = 0
                }
            }else if(item.itemArray[1+i*4]===item.itemArray[2+i*4]){//2=3
                item.itemArray[1+i*4] = 2*item.itemArray[1+i*4]
                score += item.itemArray[1+i*4]
                item.itemArray[2+i*4] = item.itemArray[3+i*4]
                item.itemArray[2+i*4] = 0
            }else if(item.itemArray[2+i*4]===item.itemArray[3+i*4]){//3=4
                item.itemArray[2+i*4] = 2*item.itemArray[2+i*4]
                score += item.itemArray[2+i*4]
                item.itemArray[3+i*4] = 0
            }else{
                score += 0
            }
            move_retract()
        }

    }
    /**************************处理滑动，合并算法***************************/
    Connections{
        target: host // 指定了连接的目标对象为host
        function onSlide_left(){ //host对象发出名为onSlide_left()的信号时
            add() //合并
            random_rec()
            itemsig(item.itemArray)
        }
    }
    Connections{
        target: host
        function onSlide_right(){
            r_2_l()
            add()
            r_2_l()
            random_rec()
            itemsig(item.itemArray)
        }
    }
    Connections{
        target: host
        function onSlide_up(){
            u_2_l()
            add()
            u_2_l()
            random_rec()
            itemsig(item.itemArray)
        }
    }
    Connections{
        target: host
        function onSlide_down(){
            d_2_l("start")
            add()
            d_2_l("end")
            random_rec()
            itemsig(item.itemArray)
        }
    }
    /*重新布局*/
    List{
        id:list
        numArray: item.itemArray
    }


}
