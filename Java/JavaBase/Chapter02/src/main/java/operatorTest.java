/**
 * @version v1.0
 * @Date:2023-10-07
 * @Description: TODO(一句话描述该类的功能)
 * @Author: x.t.
 */
public class operatorTest {
    // 测试运算符的使用1：算术运算符的使用
    // 1. + - + - * / % (前)++ (后)++ (前)-- (后)-- +
    public static void main(String[] args) {
        int m1 = 12;
        int n1 = 5;
        int k1 = m1 / n1;
        System.out.println(k1);

        System.out.println(m1 / n1 * n1);

        // 取模（或取余）： %
        int i1 = 12;
        int j1 = 5;
        System.out.println(i1 % j1);

        // 开发中，经常用来判断某个数num1能整除另外一个数num2。 num1%num2 =0

        int a1 =10;
        int b1 = ++a1;
        System.out.println("a1 = " + a1 + ",b1 = " + b1);

        int a2 = 10;
        int b2 = a2++;
        System.out.println("a2 = " + a2 + ",b2 = " + b2);

        // 练习1：
        int i = 1;
        int j = i++ + ++i * i++;
        System.out.println("j = " + j);

        // 练习2：
        int i2 =2;
        int j2 = i2++;
        System.out.println(j); //2

        int m =2;
        m = m++;
        // (1) 先取m的值”2“放操作数栈 (2) m再自增,m=3 (3) 再把操作数栈中的”2“赋值给m,m=2
        System.out.println(m); //2
    }
}
