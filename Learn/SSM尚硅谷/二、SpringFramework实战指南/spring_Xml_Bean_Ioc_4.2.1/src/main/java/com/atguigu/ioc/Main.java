package com.atguigu.ioc;

import org.springframework.context.ApplicationContext;
import org.springframework.context.support.ClassPathXmlApplicationContext;

/**
 * @version v1.0
 * @Date:2024-01-03
 * @Description: TODO
 * @Author: yuteng
 */
public class Main {
    public static void main(String[] args) {
        ApplicationContext context =
                new ClassPathXmlApplicationContext("spring-bean-01.xml");
        HappyComponent happyComponent=(HappyComponent) context.getBean("happyComponent");
        happyComponent.doWork();


        ClassPathXmlApplicationContext context1 = new ClassPathXmlApplicationContext();
        context1.setConfigLocation("spring-bean-01.xml");
        context1.refresh();

        HappyComponent happyComponent1=context1.getBean(HappyComponent.class);
        happyComponent1.doWork();

        HappyComponent happyComponent3=context1.getBean("happyComponent",HappyComponent.class);
        happyComponent3.doWork();


    }
}
