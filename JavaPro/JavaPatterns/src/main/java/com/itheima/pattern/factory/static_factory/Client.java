package com.itheima.pattern.factory.static_factory;

/**
 * @version v1.0
 * @Date:2023-10-03
 * @Description: TODO(一句话描述该类的功能)
 * @Author: x.t.
 */
public class Client {
    public static void main(String[] args) {
        //1.创建咖啡店类
        CoffeeStore store = new CoffeeStore();
        //2.点咖啡
        Coffee coffee=store.orderCoffee("latte");
        //
        System.out.println(coffee.getName());
    }
}

