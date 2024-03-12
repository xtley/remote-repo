/**
 * @version v1.0
 * @Date:2023-10-06
 * @Description:
 *      测试整型和浮点型变量的使用
 *
 * @Author: x.t.
 */
public class VariableTest1 {
    public static void main(String[] args) {

        /*
          1.测试整型变量的使用
          byte  \ short  \ int  \ long
          字节 byte 位 bit(0 or 1)  1byte=8bit
        * 类型    占用存储空间      表数范围
        * byte   1字节=8bit位     -128-127
        * short  2字节            -2^15-2^15-1
        * int    4字节            -2^31-2^31-1(约21亿)
        * long   8字节            -2^63-2^63-1
        * */

        byte b1 = 12;
        byte b2 = 127;
        //byte b3 = 128;

        short s1 = 1234;

        int i1 = 123234123;

        // long类型定义时必须在常量后加L/l作为后缀
        long l1 = 123123123L;
        long l2 = 12312123l;

        // 通常使用 int


        /*
            2.测试浮点类型变量的使用

              byte  \ short  \ int  \ long
              字节 byte 位 bit(0 or 1)  1byte=8bit
            * 类型    占用存储空间      表数范围
              float   4字节           -3.403E38-3.403E38
              double  8字节           -1.798E308-1.798E308

              float可以精确到:7位有效数字
              双精度：精度时flaot的两倍，通常采用此类型

         */
        double d1 = 12.3;
        // 声明float时后面要加上 F/f作为后缀 否则会被当作double
        float f1 =12.3f;

        // 一般使用double 精度更高 float精度太差了

        // float类型表示范围对于long类型但是精度不高

        // 测试浮点型变量的精度
        System.out.println(0.1+0.2);  // 0.30000000000000004

    }
}
