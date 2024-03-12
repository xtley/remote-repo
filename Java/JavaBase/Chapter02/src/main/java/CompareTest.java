/**
 * @version v1.0
 * @Date:2023-10-08
 * @Description:
 *      比较运算符
 * @Author: x.t.
 */
public class CompareTest {
    public static void main(String[] args) {
        // ① instanceof 在面向对象的多态性讲解
        // ② == != > < >= <=
        // > < >= <= 上面这些符号只适用于除boolean类型之外的其他七种
        // 基本数据类型
        // 运算的结果为boolean类型
        // ③ == != 可以适用于引用数据类型
        // ④ 区分 == 与 =

        boolean bl1 = true;
        boolean bl2 = false;
        if(bl1 == bl2) {
            System.out.println("ok");
        }
        int m1 = 10;
        int m2 = 20;
        boolean compare1 = m1 > m2;
        System.out.println(compare1);

        int n1 = 10;
        int n2 = 20;
        System.out.println(n1 == n2); // false
        System.out.println(n1 =n2); // 把n2的值赋给n1再打印n1

        boolean b1 = false;
        boolean b2 = true;
        System.out.println(b1 == b2);
        System.out.println(b1 = b2); // true

        boolean b3 =false;
        if (b1 == true)
            System.out.println("结果为真");
        else System.out.println("结果为假");
    }
}
