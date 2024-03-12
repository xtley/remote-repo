package com.atguigu._thread.atguigu01.create;
/**
 * @version v1.0
 * @Date:2023-10-03
 * @Description:
 *      例题：创建一个分线程1，用于遍历100以内的偶数
 * @Author: x.t.
 */
public class EvenNumberTest {
    public static void main(String[] args) {
        // 方式1：
        PrintNumber t1 = new PrintNumber();

        t1.start();

        // 方式2： 匿名子类方式
        new Thread(){
            public void run() {
                for(int i=1;i<=100;i++) {
                    if(i%2==0) {
                        System.out.println(i+"**************");
                    }
                }
            }
        }.start();

        for(int i=1;i<=100;i++) {
            if(i%2==0) {
                System.out.println(i);
            }
        }
    }


}

class PrintNumber extends Thread {
    @Override
    public void run() {
        for(int i=1;i<=100;i++) {
            if(i%2==0) {
                System.out.println(i+"**************");
            }
        }
    }
}