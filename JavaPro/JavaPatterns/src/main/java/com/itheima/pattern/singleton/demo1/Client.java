package com.itheima.pattern.singleton.demo1;

/**
 * @version v1.0
 * @Date:2023-10-01
 * @Description: TODO(一句话描述该类的功能)
 * @Author: x.t.
 */

public class Client {
    public static void main(String[] args) {
        // 创建Singleton 类的对象
        Singleton instance = Singleton.getInstance();

        Singleton instance1 = Singleton.getInstance();

        // 判断获取到的是否是同一个对象

        System.out.println(instance==instance1);
    }
}
