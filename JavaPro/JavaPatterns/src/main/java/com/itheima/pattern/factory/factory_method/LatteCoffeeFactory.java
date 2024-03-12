package com.itheima.pattern.factory.factory_method;

/**
 * @version v1.0
 * @Date:2023-10-04
 * @Description: TODO(一句话描述该类的功能)
 * @Author: x.t.
 */
public class LatteCoffeeFactory implements CoffeeFactory{
    public Coffee createCoffee() {
        return new LatteCoffee();
    }
}
