package com.sangeng.controller;

import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

/**
 * @version v1.0
 * @Date:2024-01-12
 * @Description: TODO
 * @Author: yuteng
 */
@RestController
public class Login {
    @GetMapping("/login")
    void test() {
        System.out.println("login");
    }
}
