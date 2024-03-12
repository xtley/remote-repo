import java.util.Scanner;

/**
 * @version v1.0
 * @Date:2023-10-08
 * @Description: TODO(一句话描述该类的功能)
 * @Author: x.t.
 */
/*
* switch-case 与 if-else的转换
* ①：开发中凡是可以使用switch-case结构的场景，都可以改写为if-else。反之，不成立。
* ②：开发组，如果一个具体问题既可以使用switch-case，又可以使用if-else，推荐使用switch-case。
*    为什么？switch-case相较于if-else效率稍微高。
*
* */
public class SwitchCaseTest02 {
    public static void main(String[] args) {
        // 编写程序：从键盘上输入2023年的“month”和“day”,
        // 要求通过程序输入的日期为2023年的第几天。

        // 1.使用Scanner,从键盘获取2023年的month，day
        Scanner input = new Scanner(System.in);
        System.out.println("请输入2023年的月份");
        int month = input.nextInt(); //阻塞式方法 程序运行暂停 等待输入

        System.out.println("请输入2023年的天：");
        int day = input.nextInt();
        // 2.使用switch-case实现分支结构
        // 利用穿透性
        int sumDays = 0; //记录总天数
        switch(month) {
            case 12:
                sumDays += 31;
            case 11:
                sumDays += 30;
            case 10:
                sumDays += 21;
            case 9:
                sumDays += 30;
            case 8:
                sumDays += 31;
            case 7:
                sumDays += 31;
            case 6:
                sumDays += 30;
            case 5:
                sumDays += 31;
            case 4:
                sumDays += 30;
            case 3:
                sumDays += 31;
            case 2:
                sumDays += 28;
            case 1:
                sumDays += 31;
                break;
        }
        System.out.println(sumDays);



        input.close(); // 为了防止内存泄露
    }

}
