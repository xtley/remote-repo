package com.sangeng;

import org.apache.ibatis.annotations.Mapper;
import org.mybatis.spring.annotation.MapperScan;
import org.springframework.boot.SpringApplication;
import org.springframework.boot.autoconfigure.SpringBootApplication;

/**
 * @version v1.0
 * @Date:2024-01-01
 * @Description: TODO
 * @Author: yuteng
 */
@SpringBootApplication
@MapperScan("com.sangeng.mapper")
public class SangGengBlogApplication {
    public static void main(String[] args) {

        SpringApplication.run(SangGengBlogApplication.class,args);
    }
}
