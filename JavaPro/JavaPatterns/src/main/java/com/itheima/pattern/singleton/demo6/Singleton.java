package com.itheima.pattern.singleton.demo6;

/**
 * @version v1.0
 * @Date:2023-10-02
 * @Description:
 *  单例模式： 枚举方式实现
 *  枚举类实现的单例模式时极力推荐的单例实现模式，因为枚举类型时线程安全的，并且只会装载一次，设计者充分的利用了
 *  枚举的这个特性来实现单例模式，枚举的写法非常简单，而且枚举类型时所用单例实现中唯一一种不会被破坏的单例实现模式。
 *  枚举方式属于恶汉式方式。
 * @Author: x.t.
 */
public enum Singleton {
    INSTANCE;
}
