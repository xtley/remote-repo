/**
 * @version v1.0
 * @Date:2023-10-08
 * @Description:
 *  逻辑运算符
 * @Author: x.t.
 */
public class LogicTest {
    public static void main(String[] args) {
        /*
              逻辑与 短路与 逻辑或 短路或 非 异或
            1. &     &&    |    ||   !   ^
            2。 说明
            ① 逻辑运算符针对的都是boolean 类型的变量进行的操作。
            ② 逻辑运算符的结果也是 boolean 类型。
            ③ 逻辑运算符常使用条件判断结构，循环结构中


            区分：& 和 &&
            相同点：两个符号表达的都是“且”的关系。只有当左右两边的类型值均为true时，结果才为true。
            不同点：
                执行过程：
                    1） 如果符号左边是 true ，则&,&& 都会执行符号右边的操作
                    2） 如果符号左边是fasle , 则 & 会继续执行符号右边的操作
                                             && 不会继续执行符号右边的操作。
            开发中：推荐使用&&

            | 和 || 与上面的 & 和 && 类似
            区分：| 和 ||
            相同点：两个符号表达的都是“或”的关系。只重要左右两边有一个的类型值为true时，结果就为true。
            不同点：
                执行过程：
                    1） 如果符号左边是 false ，则&,&& 都会执行符号右边的操作
                    2） 如果符号左边是 true , 则 | 会继续执行符号右边的操作
                                             || 不会继续执行符号右边的操作。
            开发中：推荐使用||
        */
        boolean b1 = true;
        int num1 = 10,num2 =10;
        if(b1 & (num1++ >0)) {
            System.out.println("床前明月光");
        }
        else {
            System.out.println("我叫郭德纲");
        }
        System.out.println("num1 = " + num1);


        if(b1 && (num2++ >0)) {
            System.out.println("床前明月光");
        }
        else {
            System.out.println("我叫郭德纲");
        }
        System.out.println("num2 = " + num2);

        // ************
        boolean b2 = false;
        System.out.println("num2 = " + num2);
        if(b2 & (num2++ >0)) {
            System.out.println("床前明月光");
        }
        else {
            System.out.println("我叫郭德纲");
        }
        System.out.println("num2 = " + num2);


        // 当 b2 不为真时 直接结束该判定
        if(b2 && (num2++ >0)) {
            System.out.println("床前明月光");
        }
        else {
            System.out.println("我叫郭德纲");
        }
        System.out.println("num2 = " + num2);
    }
}
