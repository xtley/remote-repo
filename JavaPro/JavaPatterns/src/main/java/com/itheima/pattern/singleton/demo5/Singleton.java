package com.itheima.pattern.singleton.demo5;


/**
 * @version v1.0
 * @Date:2023-10-02
 * @Description:
 *  单例模式：静态内部类方式实现
 *   静态内部类单例模式中实例由内部类创建，由于在加载外部类的过程中，时不会加载静态内部类的，只有
 *   内部类的属性被调用时才会被加载，并初始化其静态属性，静态属性由于被static修饰，保证只被实例化一次，
 *   并且严格保证实例化顺序。
 *   恶汉式
 * @Author: x.t.
 */
public class Singleton {
    private Singleton(){}

    private static class SingletonHolder {
        // 在内部类中声明并初始化外部类的对象
        private static final Singleton instance = new Singleton();
    }
    // 提供公共的访问方式
    public static Singleton getInstance() {
        return SingletonHolder.instance;
    }
}
