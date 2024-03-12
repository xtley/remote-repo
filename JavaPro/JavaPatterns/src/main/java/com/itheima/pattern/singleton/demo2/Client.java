package com.itheima.pattern.singleton.demo2;

/**
 * @version v1.0
 * @Date:2023-10-01
 * @Description: TODO(一句话描述该类的功能)
 * @Author: x.t.
 */
public class Client {
    public static void main(String[] args) {
        Singleton instance = Singleton.getInstance();

        Singleton instance1 = Singleton.getInstance();

        // 判断两次获取的Singleton对象是否是同一个对象
        System.out.println(instance==instance1);
    }
}
