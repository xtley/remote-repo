package org.wclg.wut.dao;

import org.apache.ibatis.annotations.Mapper;
import org.springframework.stereotype.Repository;
import org.wclg.wut.pojo.User;

import java.util.List;

/**
 * @version v1.0
 * @Date:2024-01-07
 * @Description: TODO
 * @Author: yuteng
 */
@Repository
@Mapper
public interface UserDao {
    User getUserByUsername(String username);
    User getUserById(Integer id);
    List<User> getUserAll();
    void addUser(User user);
}
