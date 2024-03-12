package org.wclg.wut.service.impl;

import com.alibaba.fastjson.JSON;
import org.apache.ibatis.session.SqlSession;
import org.apache.ibatis.session.SqlSessionFactory;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;
import org.wclg.wut.dao.BookDao;
import org.wclg.wut.dao.UserDao;
import org.wclg.wut.pojo.Book;
import org.wclg.wut.pojo.User;
import org.wclg.wut.service.BookService;
import org.wclg.wut.service.UserService;
import redis.clients.jedis.Jedis;
import redis.clients.jedis.JedisPool;

import java.util.List;
import java.util.Objects;

/**
 * @version v1.0
 * @Date:2024-01-07
 * @Description: TODO
 * @Author: yuteng
 */
@Service
public class UserServiceImpl implements UserService {

    private final SqlSession sqlSession;
    private final UserDao userDao;
    @Autowired()
    private JedisPool jedisPool;
    @Autowired
    public UserServiceImpl(SqlSessionFactory sqlSessionFactory) {
        this.sqlSession = sqlSessionFactory.openSession();
        this.userDao = this.sqlSession.getMapper(UserDao.class);
    }

    @Override
    public User getUserByUsername(String username) {
        Jedis jedis=this.jedisPool.getResource();
        jedis.select(1);
        String key = "book:"+username;
        String value = jedis.get(key);
        if(!Objects.isNull(value)) {
            return JSON.parseObject(value, User.class);
        }
        User user= userDao.getUserByUsername(username);
        if(!Objects.isNull(user)) {
            jedis.set(key,JSON.toJSONString(user));
            jedis.expire(key, 3600);
        }
        else {
            System.out.println("查询失败，用户名不存在");
        }
        return user;
    }

    @Override
    public User getUserById(Integer id) {
        Jedis jedis=this.jedisPool.getResource();
        jedis.select(1);
        String key = "book:"+id;
        String value = jedis.get(key);
        if(!Objects.isNull(value)) {
            return JSON.parseObject(value, User.class);
        }
        User user= userDao.getUserById(id);
        if(!Objects.isNull(user)) {
            jedis.set(key,JSON.toJSONString(user));
            jedis.expire(key, 3600);
        }
        else {
            System.out.println("查询失败，用户Id不存在");
        }
        return user;
    }

    @Override
    public List<User> getUserAll() {
        Jedis jedis=this.jedisPool.getResource();
        jedis.select(1);
        String key = "book:All";
        String value = jedis.get(key);
        if(!Objects.isNull(value)) {
            return JSON.parseObject(value, List.class);
        }
        List<User> userList= userDao.getUserAll();
        if(!Objects.isNull(userList)) {
            jedis.set(key,JSON.toJSONString(userList));
            jedis.expire(key, 3600);
        }
        else {
            System.out.println("无用户数据");
        }
        return userList;
    }

    @Override
    public boolean addUser(User user) {
        userDao.addUser(user);
        return true;
    }
}
