package com.itheima.springbootmybatis.mapper;

import com.itheima.springbootmybatis.pojo.User;
import org.apache.ibatis.annotations.Mapper;
import org.apache.ibatis.annotations.Select;

/**
 * @version v1.0
 * @Date:2024-01-01
 * @Description: TODO
 * @Author: yuteng
 */
@Mapper
public interface UserMapper {
    @Select("select * from user where id= #{id}")
    public User findById(Integer id);
}
