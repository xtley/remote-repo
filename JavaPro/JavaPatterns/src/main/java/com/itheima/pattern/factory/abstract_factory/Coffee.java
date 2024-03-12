package com.itheima.pattern.factory.abstract_factory;

/**
 * @version v1.0
 * @Date:2023-10-03
 * @Description: 咖啡类
 * @Author: x.t.
 */
public abstract class Coffee {

    public abstract String getName();
    // 加糖
    public void addsugar() {
        System.out.println("加糖");
    }
    // 加奶
    public void addMilk() {
        System.out.println("加奶");
    }

}
