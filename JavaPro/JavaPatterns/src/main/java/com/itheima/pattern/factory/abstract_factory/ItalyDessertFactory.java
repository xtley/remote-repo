package com.itheima.pattern.factory.abstract_factory;

/**
 * @version v1.0
 * @Date:2023-10-04
 * @Description:
 *  意大利风味的甜品工厂
 *   生产拿铁咖啡和提拉米苏甜品
 * @Author: x.t.
 */
public class ItalyDessertFactory implements DessertFactory{

    public Coffee createCoffee() {
        return new LatteCoffee();
    }


    public Dessert createDessert() {
        return new Trimisu();
    }
}
