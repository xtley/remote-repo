package com.itheima.pattern.factory.factory_method;

/**
 * @version v1.0
 * @Date:2023-10-04
 * @Description:
 *      美式咖啡工厂对象，专门用来生产美式咖啡
 * @Author: x.t.
 */
public class AmericanCoffeeFactory implements CoffeeFactory{

    public Coffee createCoffee() {
        return new AmericanCoffee();
    }
}
