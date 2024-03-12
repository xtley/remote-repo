package com.atguigu04._throw;

/**
 * @version v1.0
 * @Date:2023-10-02
 * @Description: TODO(一句话描述该类的功能)
 * @Author: x.t.
 */
public class ThrowTest {
    public static void main(String[] args) {
        Student s1=new Student();
        System.out.println(s1);

        try{
            s1.regist(10);
            s1.regist(-10);
            //System.out.println(s1);
        }catch(Exception e) {
            //e.printStackTrace();
            System.out.println(e.getMessage());
        }
    }
}
class Student{
    int id;
    public void regist(int id) throws Exception{
        if(id >0) {
            this.id=id;
        }else {
            // 手动抛出异常类的对象
            // 抛出运行时异常
            //throw new RuntimeException("输入的id非法");


            // 抛出非运行时异常
            //throw new Exception("输入的id非法");


            // 抛出自定义异常
            throw new BelowZeroException("输入的id非法");
        }
    }

    @Override
    public String toString() {
        return "Student{" +
                "id=" + id +
                '}';
    }
}