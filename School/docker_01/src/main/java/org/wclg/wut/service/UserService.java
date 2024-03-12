package org.wclg.wut.service;

import org.wclg.wut.pojo.Book;
import org.wclg.wut.pojo.User;

import java.util.List;

/**
 * @version v1.0
 * @Date:2024-01-07
 * @Description: TODO
 * @Author: yuteng
 */
public interface UserService {
    User getUserByUsername(String username);
    User getUserById(Integer id);
    List<User> getUserAll();
    boolean addUser(User user);
}
