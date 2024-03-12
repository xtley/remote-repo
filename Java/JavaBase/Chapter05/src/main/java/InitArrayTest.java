/**
 * @version v1.0
 * @Date:2023-10-09
 * @Description:
 *  java初始化数组的几种方法：
 *
 * @Author: x.t.
 */
public class InitArrayTest {
    public static void main(String[] args) {
        // 1. 静态初始化；在声明数组的同时，为数组
        //    元素赋值。
        int[] numbers0 = {1,2,3,4,5}; // 自动类型转换

        // 2.动态初始化：在声明数组的同时，指定数组长度,
        //   然后通过循环或其他方法为每个数组元素赋值。
        int[] numbers1 = new int[5];
        for(int i=0;i<numbers1.length;i++) {
            numbers1[i] = i+1;
        }

        // 3.默认初始化：Java会为数组分配默认的初值，
        //   具体初值取决于数组的类型。例如，int类型
        //   的数组默认值为0，boolean类型的数组默认
        //   初值为false。
        int[] numbers2 = new int[5]; //默认初值为0
        boolean[] flags = new boolean[3]; //默认初值为false
        // 4. 匿名数组初始化：创建一个没有名字的数组
        //    对象，只是用来初始化另一个数组。
        int[] numbers3 = new int[]{1,2,3,4,5};


        // 总结 T[] T_name = {e0,e1,....} \ new T[size]  \ new T[]{e0,e1,...};
        // 注意
        /*
        * 一旦数组被初始化，它的长度就不能改变。
        * 如果需要改变数组的长度，必须创建一个
        * 新的数组，并将原始数组的元素赋值到新数组中。
        *
        * */
    }
}
