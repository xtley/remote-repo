package com.itheima.pattern.factory.sinple_factory;

/**
 * @version v1.0
 * @Date:2023-10-03
 * @Description: 简单咖啡工厂类，专门用来生产咖啡
 * @Author: x.t.
 */
public class SimpleCoffeeFactory {

    public Coffee createCoffee(String type) {
        Coffee coffee = null;
        if("american".equals(type)) {
            coffee = new AmericanCoffee();
        }else if("latte".equals(type)) {
            coffee = new LatteCoffee();
        }else {
            throw new RuntimeException("对不起，您所点的咖啡没有");
        }
        return coffee;
    }
}
