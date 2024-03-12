package com.itheima.pattern.singleton.demo4;

/**
 * @version v1.0
 * @Date:2023-10-01
 * @Description:
 *      懒汉式：双重检查锁方式
 *      存在空指针异常问题，
 *      在多线程的情况下，可能会出现空指针问题，
 *      出现问题的原因是jvm在实例化对象的时候会进行优化和指令重排序操作。
 *      要解决双重检查锁模式带来的空指针异常的问题，只需要使用volatile关键字。
 *      volatile关键字可以保证可见性和有序性
 * @Author: x.t.
 */
public class Singleton {
    private Singleton(){};

    // 加入 volatile关键字
    private static volatile Singleton instance;
    private static Singleton getInstance(){
        // 第一次判断
        if(instance == null) {
            synchronized (Singleton.class) {
                if(instance == null) {
                    instance = new Singleton();
                }
            }
        }
        return instance;
    }
}
