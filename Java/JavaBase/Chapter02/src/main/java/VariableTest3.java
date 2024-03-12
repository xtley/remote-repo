/**
 * @version v1.0
 * @Date:2023-10-06
 * @Description: TODO(一句话描述该类的功能)
 * @Author: x.t.
 */
public class VariableTest3 {
    public static void main(String[] args) {
        // 基本数据类型变量间的运算规则
        /*
            1.这里提到的可以做运算的基本数据类型有7中，不包含boolean类型。
            2.运算规则包括：
                ① 自动类型提升
                ② 强制类型转换
        */

        /*
            测试自动类型提升
            规则：
                当容量小的变量与容量大的变量做运算时，
                结果自动转换为容量大的数据类型。
                说明：此处的容量小或大，并非指占用的内存空间
                     的大小，而是指表示数据的范围的大小。
                     如：long(8字节)，float(4字节)
                     byte ---> short ---> int  --->   long  ---> float  ---> double
                     特别的：byte，short,char类型的变量之间做运算，结果为int型。
                     byte+byte = int
                     byte+short = int
                     short+short = int
        */
        int i1 = 10;
        int i2 =  i1;
        long l1 = i1;
        float f1 = l1;
        byte b1 = 12;
        int i3 = b1+i1;
        System.out.println(i3);

        // *****************************************
        // 特殊的情况1：
        byte b3 = 12;
        short s1 = 10;
        // 编译不通过
        //short s2=b3+s1;
        int i4 = b3+s1;

        // 特殊的情况2：
        byte b4 = 10;
        // 编译不通过
        //byte b5 = b3+b4;
        //short s2 = b3+b4;
        int i5 = b3+b4;

        // 特殊的情况3: char
        char c1 = 'a';
        // 编译不通过
        // char c2 = c1 + b3;
        int i6 = c1 + b3;
        char c2 = 'b';
        // 编译不通过
        // char c3 = c1+c2;
        int i7 = c1 + c2;

        // ****************************
        long l2 = 123L;
        long l3 = 123; // 理解为：自动类型提升

        //long l4 = 123123123123; // 此时123123123123理解为int类型，因为超出了int范围，所以报错。
        long l5 = 123123123123L; //此时的123123123123就是long类型

        // 练习2：
        float f2 = 12.3F;
        //float f3 =12.3; //不满足自动类型提升 是把double转为float是不可以的 所以报错了
        // 练习3:
        // 规定1：整型常量，规定为是int类型
        byte b5 = 10;
        // byte b6 = b5+ 1;
        int i8= b5 + 1;
        //规定2：浮点型常量，规定是double类型
        double db1 = b5+ 12.3;
        double cc = 35.3;
        System.out.println(cc);
        // 练习4:
        // 让数字开头，会产生二义性
        /* int 123L = 12;
           long l6 = 123L;
        */
    }
}
