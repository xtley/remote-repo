package com.itheima.pattern.singleton.demo6;

/**
 * @version v1.0
 * @Date:2023-10-02
 * @Description: TODO(一句话描述该类的功能)
 * @Author: x.t.
 */
public class Client {
    public static void main(String[] args) {
        Singleton instance = Singleton.INSTANCE;
        Singleton instance1 = Singleton.INSTANCE;
        System.out.println(instance == instance1);
    }
}
