package com.itheima.pattern.factory.static_factory;


/**
 * @version v1.0
 * @Date:2023-10-03
 * @Description: 咖啡店
 * @Author: x.t.
 */
public class CoffeeStore {
    public Coffee orderCoffee(String type) {
//        // 声明Coffee类型的变量，根据不同类型创建不同的coffee子类对象
//        SimpleCoffeeFactory factory = new SimpleCoffeeFactory();
//        // 调用生成咖啡的方法
//        Coffee coffee = factory.createCoffee(type);
        Coffee coffee = SimpleCoffeeFactory.createCoffee(type);
        // 加配料
        coffee.addMilk();
        coffee.addsugar();
        return coffee;
    }
}
