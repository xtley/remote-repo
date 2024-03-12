/**
 * @version v1.0
 * @Date:2023-10-08
 * @Description:
 *  赋值运算符
 * @Author: x.t.
 */
public class setValueTest {
    public static void main(String[] args) {
        // =
        // 会进行类型转换
        // += -= *= /= %=
        // 这些操作不会改变变量本身的类型
        int i = 5;

        int a2;
        int b2;
        // 连续赋值
        a2 = b2 = 10;
        int a3 = 10,b3 =10;

        byte by1 = 10;
        by1+=5; // by1= by1 + 5 操作会编译出错 应该写为 by1 = (byte)(by1+5);

        int m2 = 1;
        m2 *= 0.1; // <-->等价于 m2 = (int)(m2*0.1)
        System.out.println(m2); // 0
        // 练习：如何实现变量的值增加2
        // 方式1：
        int n1 = 10;
        n1 = n1 + 2;

        // 方式2：推荐
        int n2 = 10;
        n2 += 2;


        int n3 = 10;
        // n3++++; 错误的写法
        // 练习2：如何实现变量的值增加1

        // 方式1：
        int i1 = 10;
        i1 = i1 + 1;

        // 方式2：
        int i2 = 10;
        i2 += 1;

        // 方式3：推荐
        int i3 = 10;
        i3++;
    }
}
