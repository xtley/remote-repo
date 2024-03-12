package com.itheima.pattern.factory.factory_method;



/**
 * @version v1.0
 * @Date:2023-10-03
 * @Description: 咖啡店
 * @Author: x.t.
 */
public class CoffeeStore {
    private CoffeeFactory factory;
    public void setFactory(CoffeeFactory factory) {
        this.factory = factory;
    }
    // 点咖啡功能
    public Coffee orderCoffee() {
        Coffee coffee = factory.createCoffee();
        // 加配料
        coffee.addMilk();
        coffee.addsugar();
        return coffee;
    }
}
