/**
 * @version v1.0
 * @Date:2023-10-08
 * @Description:
 *      位运算符
 * @Author: x.t.
 */
public class BitTest {
    public static void main(String[] args) {
        /*
               左移 右移 无符号右移 按位与 按位或 按位异或 按位取反（无 无符号左移 <<<）
           1.  <<  >>   >>>      &     |     ^       ~
           2. 上面这些位运算符都是针对数值类型的变量或常量进行运算，运算的结果也是数值
           3. <<: 在一定范围内每向左移动一位，就在原有的基础上 * 2 即 x<< y = x*2^y （对于正数 负数都适用）
                  正负数都采用：采用右补0的方式，左边多余截去
           4. 高效的方式计算2*8？
              2<<8 或 8 << 1
           5. >>: 每向右移动一位，就在原有的基础上 /2 即 x>> y = x/(2^y) ，不能整除的时候向下取整
                  正数：左补0 右多余截去
                  负数：左补1 右多余截去
           6. >>>：使用一次都变成正数
                  正数：左补0 右多余截去
                  负数：左补0 右多余截去
                  将 ---------
                         ------------
                  中间部位做置换

        */

        int num1 = 7;
        System.out.println("num1 << 1: " + (num1<<1)); // 14
        System.out.println("num1 << 2: " + (num1<<2)); // 28
        System.out.println("num1 << 3: " + (num1<<3)); // 56
        System.out.println("num1 << 28: " + (num1<<28)); // 1879048192
        System.out.println("num1 << 29: " + (num1<<29)); // -536870912 过犹不及

        int num2 = -7;
        System.out.println("num2 << 1: " + (num2<<1)); // -14
        System.out.println("num2 << 2: " + (num2<<2)); // -28
        System.out.println("num2 << 3: " + (num2<<3)); //-56

        int num3 = 7;
        System.out.println("num3 >> 1: " + (num3>>1)); // 3
        System.out.println("num3 >> 2: " + (num3>>2)); // 1
        System.out.println("num3 >> 3: " + (num3>>3)); // 0

        int num4 = -7;
        System.out.println("num4 >>> 1: " + (num4>>>1)); // 2147483644
        System.out.println("num4 >>> 2: " + (num4>>>2)); // 1073741822
        System.out.println("num4 >>> 3: " + (num4>>>3)); // 536870911
        System.out.println("num4 >>> 3: " + (num4>>>16)); // 65535

        // 交换变量的值
        // 方式1：声明一个临时变量 （推荐）
        // int temp = m;
        // m = n;
        // n = temp;

        // 方式2：优点：不需要临时变量。 缺点：难，适用性差。只适用于数值类型，且可能出现数据溢出的情况。
        //   m = m + n; // 30 = 10 + 20;
        //   n = m - n; // 10 = 30 - 20;
        //   m = m - n; // 20 = 30 - 10;

        // 方式3：原理：x^x=0
        // a^b:如果a、b两个值不相同，则异或结果为1。如果a、b两个值相同，异或结果为
        // m = m ^ n;
        // n = m ^ n;
        // m = m ^ n;
        // System.out.println(1^1); 0


    }
}
