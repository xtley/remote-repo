package org.example.mapper;

import org.apache.ibatis.annotations.Mapper;
import org.apache.ibatis.annotations.Param;
import org.apache.ibatis.annotations.Select;
import org.example.User;

import java.util.List;

/**
 * @version v1.0
 * @Date:2023-12-21
 * @Description: TODO
 * @Author: yuteng
 */
@Mapper //在运行时，会自动生成该接口的实现类对象（代理对象），并且将该对象交给IOC容器管理
public interface UserMapper {
    //查询用户的全部信息
    @Select("select * from users")
    public List<User> list() ;
    User findByUsername(String username);
    void addUser(User user);
}
