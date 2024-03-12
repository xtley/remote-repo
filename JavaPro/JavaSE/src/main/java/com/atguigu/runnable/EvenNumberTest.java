package com.atguigu.runnable;

/**
 * @version v1.0
 * @Date:2023-10-03
 * @Description:
 *      ① 创建一个实现Tunnable接口的类
 *      ② 实现接口中的run() --> 将此线程中要执行的操作，声明在此方法体中
 *      ③ 创建当前实现类的对象
 *      ④ 将此对象作为参数传递到Thread类的构造器中，创建Thread类的实例
 *      ⑤ Thread类的实例调用start():1.启动线程 2.调用当前线程的run()
 * @Author: x.t.
 */
// ① 创建一个实现Tunnable接口的类
class EvenNumberPrint implements Runnable{
    // ② 实现接口中的run() --> 将此线程中要执行的操作，声明在此方法体中
    @Override
    public void run() {

        for(int i=1;i<=100;i++) {
            System.out.println(Thread.currentThread().getName()+":"+i);
        }
    }
}
public class EvenNumberTest {
    public static void main(String[] args) {
        // ③ 创建当前实现类的对象
        EvenNumberPrint p =new EvenNumberPrint();
        // ④ 将此对象作为参数传递到Thread类的构造器中，创建Thread类的实例
        Thread t1 = new Thread(p);
        // ⑤ Thread类的实例调用start():1.启动线程 2.调用当前线程的run()
        t1.start();

        // 方式三： 使用实现Runnable接口的方式：（提供了Runnable接口的匿名实现对象）
        new Thread(new Runnable() {
            @Override
            public void run() {
                for(int i=1;i<=100;i++) {
                    System.out.println(Thread.currentThread().getName()+":"+i);
                }
            }
        }).start();
        for(int i=1;i<=100;i++) {
            System.out.println(Thread.currentThread().getName()+":"+i);
        }
    }
}
