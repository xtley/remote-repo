/**
 * @version v1.0
 * @Date:2023-10-08
 * @Description: TODO(一句话描述该类的功能)
 * @Author: x.t.
 */
public class LogicExer {
    public static void main(String[] args) {
        int  a=20,b=20;
        boolean bo1 = (++a % 3 ==0)&&(a++ % 7 ==0);
        System.out.println("a: "+ a);
        System.out.println("bo1: "+ bo1);
        boolean bo2 = (b++ % 3 ==0)&&(++b % 7 ==0);
        System.out.println("b: "+ b);
        System.out.println("bo2: "+ bo2);
    }
}
