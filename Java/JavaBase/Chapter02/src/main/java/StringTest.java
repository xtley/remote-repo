/**
 * @version v1.0
 * @Date:2023-10-07
 * @Description:
 *   基本数据类型与String的运算
 * @Author: x.t.
 */
public class StringTest {
    public static void main(String[] args) {
        // String类型属于引用类型，俗称字符串
        // String类型的变量，可以使用一对“”的方式赋值
        // String声明的字符串内部，可以包含0个，1个或多个字符。

        String str1 ="Hello World!";
        System.out.println("str1");
        System.out.println(str1);

        String str2 = ""; //''
        String str3 = "a"; // char c1 = 'a';

        // String与基本数据类型变量间的运算（8种，包括boolean）
        // String与基本数据类型变量间只能做连接运算，使用“+”表示
        // 运算的结果是String类型

        int num1 = 10;
        boolean b1 = true;
        String str4 = "hello";
        System.out.println(str4 + b1);
        String str5 = str4 + b1;
        String str6 = str4 + b1 + num1;
        System.out.println(str6); // hellotrue10

        // 思考？ 如下的声明
        //String str7 = b1 + num1 + str4;
        // 不通过 boolean和int不能做运算 `要想连接只能String参与`


        // 如何将String类型的变量转换为基本数据类型
        int num2 = 10;
        String str7 = num2 + ""; //"10"

        String str8 = "abc"; // 不能考虑转换为基本数据类型的。

        String str9 = num2 + "";
        //int num3 = (int)str9; 无法转换 str9是一个类引用类型 编译不通过

        int num3 = Integer.parseInt(str9);
        System.out.println(num3+1);


    }

}
