package com.itheima.springbootmybatis.controller;

import com.itheima.springbootmybatis.pojo.User;
import com.itheima.springbootmybatis.service.UserService;
import com.itheima.springbootmybatis.service.impl.UserServiceImpl;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

/**
 * @version v1.0
 * @Date:2024-01-01
 * @Description: TODO
 * @Author: yuteng
 */
@RestController
public class UserController {
    @Autowired
    private UserService userService;

    @RequestMapping("/findById")
    public User findById(Integer id) {
        return userService.findById(id);
    }
}
