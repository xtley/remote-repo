package com.example.demo;

import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

/**
 * @version v1.0
 * @Date:2024-02-29
 * @Description: TODO
 * @Author: yuteng
 */
@RestController
public class HelloController {
    @RequestMapping
    public String hello() {
        return "hello Spring Boot 222!";
    }
}
