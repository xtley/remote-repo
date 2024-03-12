package com.itheima.pattern.factory.abstract_factory;

/**
 * @version v1.0
 * @Date:2023-10-04
 * @Description:
 *  美式风味的甜品工厂
 *   生产美式咖啡和抹茶慕斯
 * @Author: x.t.
 */
public class AmericanDessertFactory implements DessertFactory{
    @Override
    public Coffee createCoffee() {
        return new AmericanCoffee();
    }

    @Override
    public Dessert createDessert() {
        return new MatchaMousse();
    }
}
