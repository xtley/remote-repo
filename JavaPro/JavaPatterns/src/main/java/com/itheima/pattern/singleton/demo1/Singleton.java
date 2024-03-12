package com.itheima.pattern.singleton.demo1;

/**
 * @version v1.0
 * @Date:2023-10-01
 * @Description:
 *      饿汉式：静态成员变量
 *      饿汉式：类加载的时候就会导致该单例被创建 会导致内存浪费
 * @Author: x.t.
 */
public class Singleton {
    // 1.私有构造方法
    private Singleton(){}

    // 2.在本类中创建本类对象
    private static Singleton instance = new Singleton();

    // 3.提供一个公共的访问方式，让外界获取该对象
    public static Singleton getInstance() {
        return instance;
    }
}
