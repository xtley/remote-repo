/**
 * @version v1.0
 * @Date:2023-10-08
 * @Description: TODO(一句话描述该类的功能)
 * @Author: x.t.
 */
public class SwitchCaseTest1 {
    public static void main(String[] args) {
        // 使用switch-case实现: 对学生成绩大于等于60分的,输出"合格".低于60分的,输出"不合格".
        // 定义一个学生成绩的变量
        int score = 34;
        switch(score / 10) {
            case 0:
            case 1:
            case 2:
            case 3:
            case 4:
            case 5:
                System.out.println("不及格");
                break;
            case 6:
            case 7:
            case 8:
            case 9:
            case 10:
                System.out.println("及格");
                break;
            default:
                System.out.println("输入非法");
                break;
        }

        switch(score / 60) {
            case 0:
                System.out.println("不及格");
                break;
            case 1:
                System.out.println("及格");
                break;
            default:
                System.out.println("输入非法");
                break;
        }
    }
}
