package org.wclg.wut.controller;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.http.ResponseEntity;
import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.*;
import org.springframework.web.servlet.ModelAndView;
import org.wclg.wut.dao.UserDao;
import org.wclg.wut.pojo.Book;
import org.wclg.wut.pojo.User;
import org.wclg.wut.service.impl.BookServiceImpl;
import org.wclg.wut.service.impl.UserServiceImpl;

import java.util.List;
import java.util.Objects;

/**
 * @version v1.0
 * @Date:2024-01-07
 * @Description: TODO
 * @Author: yuteng
 */
@Controller
public class UserController {
    @Autowired
    private UserServiceImpl userService;

    @RequestMapping(value = "/login")
    @ResponseBody
    public User Login(String username, String password){
        User user = userService.getUserByUsername(username);
        System.out.println("登录接口");
        return user;
    }
    @RequestMapping("/register")
    @ResponseBody
    public String Register(String username,String password){
        System.out.println("正在注册");
        if(Objects.isNull(userService.getUserByUsername(username))) {
            User user = new User(null,username,password);
            userService.addUser(user);
            System.out.println("注册成功");
            return "注册成功";
        }
        else {
            return "注册失败，用户名已存在";
        }
    }
}
