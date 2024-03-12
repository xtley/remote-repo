package com.atguigu03._throws;

import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.IOException;

/**
 * @version v1.0
 * @Date:2023-10-01
 * @Description: TODO(一句话描述该类的功能)
 * @Author: x.t.
 */
public class ThrowsTest {
    public static void main(String[] args) {
        method3();
    }
    public static void method3() {
        try{
            method2();
        }catch (FileNotFoundException e) {
            e.printStackTrace();
        }catch(IOException e) {
            e.printStackTrace();
        }
    }

    public static void method2() throws FileNotFoundException, IOException {
        method1(); // method1的异常被抛出给他的使用者 编译时异常 还可以继续向上抛出
    }
    public static void method1() throws FileNotFoundException, IOException {
        File file = new File("hello.txt");
        FileInputStream fis = new FileInputStream(file); //可能报FileNotFoundException

        int data = fis.read(); //可能报IOException

        while(data!=-1) {
            System.out.print((char)data);
            data = fis.read();  //可能报IOException
        }
        fis.close(); //可能报IOException
    }
}
