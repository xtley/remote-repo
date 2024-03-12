/**
 * @version v1.0
 * @Date:2023-10-08
 * @Description:
 *      分支结构之switch-case的使用
 * @Author: x.t.
 */
public class SwitchCaseTest {
    public static void main(String[] args) {
        /*
        * 1.语法格式
        * switch(表达式) {
        *    case 常量1:
        *           //执行语句1
        *           break;
        *    case 常量2:
        *           //执行语句2
        *           break;
        *    ...
        *    default:
        * }
        *
        *
        *
        *
        *
        *
        * */

        int num = 1;
        // 从第一个命中case的位置开始向后执行
        // 1. case后面有break就直接结束跳出当前switch
        // 2. case后面没有break，执行后面所有的语句。
        //    直到遇到break或者执行完这之后所有的 case,default语句。
        /*
        *  3. 说明：
        *  ①：switch中的表达式只能是特定的数据类型：如下：byte \ short \ char \ int \ 枚举(JDK5.0新增) \ String(JDK7.0新增)
        *  ②：case 后都是跟的常量，使用表达式与这些常量做相等的判断，不能进行范围的判断
        *  ③：开发中，使用switch-case时，通常case匹配的情况都有限。
        *  ④：break: 可以使用在switch-case中。一旦执行此break关键字，就跳出当前的switch-case结构
        *  ⑤：default：类似与if-else 中的else 可有可无,而且位置是灵活的
        * */
        switch(num) {
            default:
                System.out.println("other");
                break; //写在前面推荐加上
            case 0:
                System.out.println("zero");
                break;
            case 1:
                System.out.println("one");
                break;
            case 2:
                System.out.println("two");
                break;
            case 3:
                System.out.println("three");
                break;

        }
        // 另例：
        String season = "summer";
        switch(season) {
            case "spring":
                System.out.println("春来花开");
                break;
            case "summer":
                System.out.println("夏日炎炎");
                break;
            case "autumn":
                System.out.println("秋高气爽");
            case "winter":
                System.out.println("冬雪皑皑");
            default:
                System.out.println("季节输入有误");
                break;
        }

        // 错误的例子：编译不通过
//        int number = 20;
//        switch(number) {
//            case number > 0:
//                System.out.println("正数");
//            case number < 0:
//                System.out.println("负数");
//            default:
//                System.out.println("零");
//                break;
//        }

    }
}
