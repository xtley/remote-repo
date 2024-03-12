package com.itheima.pattern.singleton.demo3;

/**
 * @version v1.0
 * @Date:2023-10-01
 * @Description:
 *    懒汉式：存在线程安全问题
 *    直接加上同步的关键字 synchronized 解决线程安全问题
 * @Author: x.t.
 */
public class Singleton {
    // 声明构造方法
    private Singleton(){}

    // 声明Singleton类型的变量instance
    private static Singleton instance; // 只是声明一个该类型的变量，并没有进行赋值

    // 加上同步的关键字 synchronized
    public static synchronized Singleton getInstance(){
        // 判断instance是否为null,如果为null,说明没有创建Singleton类的对象
        // 如果没有，创建一个并返回 如果有直接返回即可
        if (instance == null) {
            // 线程1等待，线程2获取到cpu的执行权，也会进入到该判断里面
            instance = new Singleton();
        }
        return instance;
    }
}
