package com.wclg.controller;

import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.RequestMapping;

import javax.servlet.http.HttpServletRequest;

@Controller
public class UserController {
    @RequestMapping("/getUserId")
    public void getUserId(HttpServletRequest request){
        String userid= request.getParameter("userid");
        System.out.println("userid="+userid);
    }
    // 接收表单用户信息
    @RequestMapping("/registerUser")
    public void registerUser(User user) {
        String username = user.getUsername();
        String password = user.getPassword();
        System.out.println("username="+username+",password="+password);
    }

}
