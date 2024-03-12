package com.itheima.springbootmybatis.service;

import com.itheima.springbootmybatis.pojo.User;

/**
 * @version v1.0
 * @Date:2024-01-01
 * @Description: TODO
 * @Author: yuteng
 */
public interface UserService {
    public User findById(Integer id);
}
