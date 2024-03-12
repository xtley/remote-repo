/**
 * @version v1.0
 * @Date:2023-10-09
 * @Description: TODO(一句话描述该类的功能)
 * @Author: x.t.
 */
// 数组
// Java中数组是引用类型
public class ArrayTest {
    public static void main(String[] args) {
        // Array
        /*
        * 1. 数组的理解(Array)
        * 概念：是多个相同类型数据按一定顺序排列的集合，并使用一个名字命名，并通过编号
        * 的方式对这些数据进行统一管理。
        * 简称多个数据的组合
        * Java中的容器：数组，集合框架（第12张）：在内存中对多个数据的存储。
        *
        * 2. 几个相关的概念
        * > 数组名
        * > 数组的元素（即内部存储的多个元素）
        * > 数组的下标，角标，索引，index（即找到指定数组元素所使用的编号）
        * > 数组的长度（即数组容器中存储的元素的个数）
        * 3. 数组的特点
        * 数组本身是引用数据类型，而****数组中的元素可以是任何数据类型，包括
        * 基本数据类型和引用数据类型。*****
        * 插件数组对象会在内存中开辟出一整块连续的空间。占据的空间的大小，取决于
        * 数组的长度和数组中元素的类型。
        * 数组中的元素在内存中是依次紧密排列的，有序的。
        * 数组，一旦初始化完成，其长度就是确定的。数组的长度一旦确定，就不能修改。
        * 我们可以直接通过下标（或索引）的方式调用指定位置的元素，速度很快。
        * 数组名中引用的是这块连续
        * 数组中的元素是依次紧密排列的
        * 4. 复习，变量按照数据类型的分类
        * 4.1 基本数据类型：
        * byte \ short \ int \ long ;float
        *
        * 4.2 引用数据类型：类，数组，接口，枚举，注解，记录
        *
        * 5. 数组的分类
        * 5.1 按照元素的类型：基本数据类型元素的数组，引用数据类型元素的数组。
        * 5.2 按照数组的维数来分：一维数组；二维数组；.....
        *
        * 6. 一维数组的使用（6个基本点）
        * > 数组的声明和初始化
        * > 调用数组的指定元素
        * > 数组的属性：length,表示数组的长度
        * > 数组的遍历
        * > 数组元素的默认初始化值
        * > 一维数组的内存解析(难)
        * */

        // 1. 数组的声明和初始化
        // 复习：变量的定义格式：数据类型 变量名 = 变量值
        int num1 = 10;
        int num2; // 声明
        num2 = 20; // 初始化
        // 1.1 声明数组
        double[] prices;
        // 1.2 数组的初始化
        // 静态初始化：数组变量的赋值与数组元素的赋值操作同时进行
        prices = new double[]{20.32,43.21,43.22};

//        String[] foods;
//        foods = new String[]{"拌海蜇","龙须菜","炝冬笋","玉兰片"};

        // 数组的声明和初始化
        // 动态初始化：数组变量的赋值与数组元素的赋值操作分开进行。
        String[] foods  = new String[4];

        // 其他正确的方式
        int arr[] = new int[4];
        int[] arr1 = {1,2,3,4}; // 类型推断
        //错误的方式
        // int[] arr2 = new int[3]{1,2,3};
        // int[3] arr3 = new int[];


        // 2. 数组元素的调用
        // 通过角标的方式，获取数组的元素
        // 角标的范围从0开始，到数组的长度-1结束
        System.out.println(prices[0]);
        System.out.println(prices[2]);
        // System.out.println(prices[3]); // 数组越界异常

        foods[0] = "拌海蜇";
        foods[1] = "龙须菜";
        foods[2] = "炝冬笋";
        foods[3] = "玉兰片";
        // foods[4] = "酱茄子"; //数组越界


        // 3. 数组的长度：用来描述数组容器中容量的大小
        // 使用length属性表示
        System.out.println(foods.length); // 4
        System.out.println(prices.length); // 3

        // 4.如何遍历数组
        System.out.println(foods[0]);
        System.out.println(foods[1]);
        System.out.println(foods[2]);
        System.out.println(foods[3]);

        for(int i=0;i< foods.length;i++) {
            System.out.println(foods[i]);
        }

        for(int i=0; i< prices.length;i++) {
            System.out.println(prices[i]);
        }
    }
}
