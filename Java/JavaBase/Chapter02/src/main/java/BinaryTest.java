/**
 * @version v1.0
 * @Date:2023-10-07
 * @Description: TODO(一句话描述该类的功能)
 * @Author: x.t.
 */
public class BinaryTest {

    /*
        十进制：数字组成：0-9
        二进制：数字组成：0-1,以0b或0B开头
        八进制：数字组成：0-7，以数字0开头表示
        十六进制：数字组成：0-9，a-f.以0x或0X开头表示。此处的a-f不区分大小写。
        
    */


    public static void main(String[] args) {
        int num1 = 123;
        int num2 = 0b101;
        int num3 = 0127;
        int num4 = 0x12aF;
        System.out.println(num1);
        System.out.println(num2);
        System.out.println(num3);
        System.out.println(num4);

    }

}
