package com.wut.mvc.controller;

import com.wut.mvc.pojo.User;
import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.PathVariable;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestParam;

import javax.servlet.http.HttpServletRequest;
import java.util.Date;

/**
 * @version v1.0
 * @Date:2024-03-05
 * @Description: TODO
 * @Author: yuteng
 */
@Controller
public class UserController {
    // 验证简单的数据绑定
    @RequestMapping("/getUserId")
    public void getUserId(HttpServletRequest request) {
        String userid = request.getParameter("userid");
        System.out.println("userid=" + userid);
    }
    @RequestMapping("/getUserNameAndId")
    public void getUserNameAndId(String username, Integer id) {
        System.out.println("username=" + username + ", id=" + id);
    }
    @RequestMapping("/getUserName")
    public void getUserName(@RequestParam(value = "name", required
            = false, defaultValue = "wut") String username) {
        System.out.println("username=" + username);
    }
    @RequestMapping("/user/{name}")
    public void getPathVariable(@PathVariable(value = "name") String username) {
        System.out.println("username=" + username);
    }
    @RequestMapping("/registerUser")// 接收表单用户信息
    public void registerUser(User user) {
        String username = user.getUsername();
        String password = user.getPassword();
        System.out.println("username=" + username + ",password=" +
                password);
//return "/register.jsp";
    }
    @RequestMapping("/getBirthday")
    public void getBirthday(Date birthday) {
        System.out.println("birthday="+birthday);
    }
}
