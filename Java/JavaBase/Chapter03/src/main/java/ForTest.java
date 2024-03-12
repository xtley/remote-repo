/**
 * @version v1.0
 * @Date:2023-10-08
 * @Description: TODO(一句话描述该类的功能)
 * @Author: x.t.
 */
public class ForTest {
    public static void main(String[] args) {
        /*
        * for循环的格式
        * for(①;②;④) {
        *     ③
        * }
        * ①：初始化条件
        * ②：循环条件 -----> 一定式boolean类型的变量或表达式
        * ③：循环体
        * ④：迭代部分
        * 执行过程：① - ② - ③ - ④ - ② - ③ - ④ -.... -
        *
        *
        *
        *
        *
        *
        * */
        for(int i=1;i<=5;i++) {
            System.out.println("HelloWorld");
        }
        int num = 1;
        for(System.out.println("a");num<3; System.out.println("c"),num++) {
            System.out.println("b");
        }
    }
}
