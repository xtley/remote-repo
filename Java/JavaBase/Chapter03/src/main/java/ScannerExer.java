/**
 * @version v1.0
 * @Date:2023-10-08
 * @Description: TODO(一句话描述该类的功能)
 * @Author: x.t.
 */
import java.util.Scanner;
public class ScannerExer {

    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        String a="是";
        if(a.equals("是")) {
            System.out.println(1);
        }
        else {
            System.out.println(2);
        }

        if(a == "是") {
            System.out.println(3);
        }
        else {
            System.out.println(4);
        }

        String str1 = "abc",str2 ="abc";
        System.out.println(str1==str2);  // 结果为ture
        // 因为在java中字符串的值是不可改变的，相同的字符串在内存中只会存储
        // 一份所以a和b指向的是同一个对象
        String b = new String("abc");
        String c = new String("abc");
        boolean bl1 = (b==c);
        System.out.println(bl1); // 值为false
        boolean bl2 = b.equals(c);
        System.out.println(bl2); //值为true

        // equals 判断内容是否一致
        // == 判断两边是否指向同一块内存
    }
}
