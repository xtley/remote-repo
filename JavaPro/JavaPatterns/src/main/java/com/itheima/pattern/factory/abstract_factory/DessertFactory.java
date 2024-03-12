package com.itheima.pattern.factory.abstract_factory;

/**
 * @version v1.0
 * @Date:2023-10-04
 * @Description: TODO(一句话描述该类的功能)
 * @Author: x.t.
 */
public interface DessertFactory {
    // 生成咖啡
    Coffee createCoffee();

    //生成甜品的功能
    Dessert createDessert();
}
