/**
 * @version v1.0
 * @Date:2023-10-08
 * @Description:
 *      Scanner的使用
 * @Author: x.t.
 */
// 步骤1：导包 import java.util.Scanner
import java.util.Scanner;
public class ScannerTest {
    public static void main(String[] args) {
        /*
        * 1. 使用Scanner获取不同类型数据的步骤。
        *   步骤1：导包 import java.util.Scanner
        *   步骤2：提供（或创建）一个Scanner类的实例
        *   步骤3：调用Scanner类中的方法，获取指定类型的变量
        *   步骤4：关闭资源，调用Scanner类的close()
        * 2. Scanner 类中提供了获取byte \ short \ int \ long
        *    \float \double \boolean \ String类型变量的方法。
        *    注意：没有提供获取char类型变量的方法。需要使用Scannernext().charAt(0)
        * */
        // 步骤2：提供（或创建）一个Scanner类的实例
        Scanner scan = new Scanner(System.in);

        System.out.println("欢迎光临你来我往交友网");
        System.out.print("请输入你的网名:");
        // 步骤3：调用Scanner类中的方法，获取指定类型的变量
        String name = scan.next();

        System.out.print("请输入你的年龄:");
        int age = scan.nextInt();

        System.out.print("请输入你的体重:");
        double weight = scan.nextDouble();

        System.out.print("你是否单身:(单身：true;不单身：false)");
        boolean isSingle = scan.nextBoolean();

        System.out.print("请输入你的性别：(男\\女)");
        char gender = scan.next().charAt(0);

        System.out.println("网民：" + name + ",年龄： " + age +
                ",体重： " + weight + ",是否单身： " + isSingle +
                ",性别：" + gender);
        System.out.println("注册完成，欢迎继续进入体验");
        scan.close();

    }
}
