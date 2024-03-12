/**
 * @version v1.0
 * @Date:2023-10-08
 * @Description: TODO(一句话描述该类的功能)
 * @Author: x.t.
 */
public class DoWhileTest {
    public static void main(String[] args) {
        /*
        * ①：初始化条件
        * ②：循环条件 -----> 一定式boolean类型的变量或表达式
        * ③：循环体
        * ④：迭代部分
        * do-while格式
        * ①
        * do{
        *   ③
        *   ④
        * }while(②);
        * 执行过程：① - ③ - ④ - ② - ③ - ④ - ... - ②
        *
        *
        *
        *
        *
        *
        *
        *
        *
        *
        *
        *
        * */

        int i = 1,count =0;
        do{
            if(i % 2 ==0) {
                System.out.println(i);
                count+=i;
            }
            i++;
        }while(i<=100);
        System.out.println(count);


    }
}
