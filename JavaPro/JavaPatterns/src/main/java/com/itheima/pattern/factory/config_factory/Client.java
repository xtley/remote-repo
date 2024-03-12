package com.itheima.pattern.factory.config_factory;

/**
 * @version v1.0
 * @Date:2023-10-04
 * @Description: TODO(一句话描述该类的功能)
 * @Author: x.t.
 */
public class Client {
    public static void main(String[] args) {
        Coffee coffee = CoffeeFactory.createCoffee("american");
        //System.out.println(coffee);
        System.out.println(coffee.getName());
        System.out.println("============");
        Coffee latte =CoffeeFactory.createCoffee("latte");
        System.out.println(latte.getName());
    }
}

