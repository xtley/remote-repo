package com.itheima.pattern.factory.abstract_factory;

/**
 * @version v1.0
 * @Date:2023-10-04
 * @Description: TODO(一句话描述该类的功能)
 * @Author: x.t.
 */
public class Client {
    public static void main(String[] args) {
        // 创建的是 意大利风味甜品工厂对象
        //ItalyDessertFactory factory = new ItalyDessertFactory();
        AmericanDessertFactory factory = new AmericanDessertFactory();
        // 获取对应拿铁咖啡和提拉米苏甜品
        Coffee coffee = factory.createCoffee();
        Dessert dessert = factory.createDessert();

        System.out.println(coffee.getName());
        dessert.show();
    }
}
