package com.itheima.pattern.factory.factory_method;

/**
 * @version v1.0
 * @Date:2023-10-04
 * @Description: TODO(一句话描述该类的功能)
 * @Author: x.t.
 */
public class Client {
    public static void main(String[] args) {
        // 创建咖啡点对象
        CoffeeStore store = new CoffeeStore();
        // 创建对象
        CoffeeFactory factory = new AmericanCoffeeFactory();
        store.setFactory(factory);

        // 点咖啡
        Coffee coffee = store.orderCoffee();

        System.out.println(coffee.getName());
    }
}
