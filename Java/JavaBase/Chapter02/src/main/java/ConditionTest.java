/**
 * @version v1.0
 * @Date:2023-10-08
 * @Description:
 *  条件运算符的使用
 * @Author: x.t.
 */
public class ConditionTest {
    public static void main(String[] args) {
        /*
        * 条件运算符（三元运算符）：
        * (条件表达式)? 表达式1:表达式2
        * 说明：
        * ① 条件表达式是boolean类
        * ② 如果条件表达式的结果是true，则执行表达式1。否则执行表达式2。
        * ③ 两个表达式的类型必须是系统的或者是兼容的否则 不能被变量接收
        * ④ 开发中，凡是可以使用条件运算符的位置，都可以改写为条件运算符。
        * 建议：在二者都能使用的情况下，推荐使用条件运算符，效率相对高一些
        * */
        String info =(2 > 1)?"表达式1":"表达式2";
        System.out.println(info);
        System.out.println((2 > 1)?1:"表达式2");
        // String str1 =(2 > 1)? 1 :"表达式2";
        // String str2 =(2 <= 1)? 1 :"表达式2";
        //
    }
}
