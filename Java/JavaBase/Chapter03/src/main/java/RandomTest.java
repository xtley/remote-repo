/**
 * @version v1.0
 * @Date:2023-10-08
 * @Description: TODO(一句话描述该类的功能)
 * @Author: x.t.
 */
public class RandomTest {
    public static void main(String[] args) {
        System.out.println("Hello World!");
        // 如何获取一个随机数？
        /*
        * 1. 可以使用Java提供的API:Math类中的random()
        * 2. random()调用以后，会返回一个[0.0,1.0)范围的double型的随机数
        *
        * 3. 需求1：获取一个[0,100]范围内的随机整数
        *
        * */

        double d1 = Math.random();
        System.out.println("d1 = " + d1);

        int i = (int)(Math.random()*101); //[0.0,1.0) --> [0,101) --> [0,100]
        System.out.println(i);

        int j =(int)(Math.random()*100) + 1; // [0.0,1.0) --> [0.0,100.0) --> [0,99] --> [1,100]
        System.out.println();
    }
}
