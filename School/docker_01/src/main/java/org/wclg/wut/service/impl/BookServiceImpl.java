package org.wclg.wut.service.impl;

import com.alibaba.druid.pool.DruidDataSource;
import com.alibaba.fastjson.JSON;
import com.fasterxml.jackson.databind.ObjectMapper;
import org.apache.ibatis.io.Resources;
import org.apache.ibatis.session.SqlSession;
import org.apache.ibatis.session.SqlSessionFactory;
import org.apache.ibatis.session.SqlSessionFactoryBuilder;
import org.mybatis.spring.SqlSessionFactoryBean;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.context.ApplicationContext;
import org.springframework.context.support.ClassPathXmlApplicationContext;
import org.springframework.data.redis.core.RedisTemplate;
import org.springframework.stereotype.Service;
import org.wclg.wut.dao.UserDao;
import org.wclg.wut.pojo.Book;
import org.wclg.wut.pojo.User;
import org.wclg.wut.service.BookService;
import org.wclg.wut.dao.BookDao;
import redis.clients.jedis.Jedis;
import redis.clients.jedis.JedisPool;

import java.io.IOException;
import java.io.InputStream;
import java.util.List;
import java.util.Objects;

/**
 * @version v1.0
 * @Date:2024-01-06
 * @Description: TODO
 * @Author: yuteng
 */
@Service
public class BookServiceImpl implements BookService {

    private final SqlSession sqlSession;
    private BookDao bookDao;
    @Autowired()
    private JedisPool jedisPool;
    @Autowired
    public BookServiceImpl(SqlSessionFactory sqlSessionFactory) {
        this.sqlSession = sqlSessionFactory.openSession();
        this.bookDao = this.sqlSession.getMapper(BookDao.class);
    }
    @Override
    public String getNameById(Integer id) {
        return getBookById(id).getBookname();
    }
    @Override
    public Book getBookById(Integer id) {
        Jedis jedis=this.jedisPool.getResource();
        jedis.select(1);
        String key = "book:"+id;
        String value = jedis.get(key);
        if(!Objects.isNull(value)) {
            return JSON.parseObject(value, Book.class);
        }
        Book book= bookDao.getBookById(id);
        System.out.println(book);
        if(!Objects.isNull(book)) {
            jedis.set(key,JSON.toJSONString(book));
            jedis.expire(key, 3600);
        }
        else {
            System.out.println("查找Id不存在");
        }
        return book;
    }

    @Override
    public List<Book> getBookAll() {
        Jedis jedis=this.jedisPool.getResource();
        jedis.select(1);
        String key = "book:"+"All";
        String value = jedis.get(key);
        if(!Objects.isNull(value)) {
            return JSON.parseObject(value, List.class);
        }
        List<Book> bookList= bookDao.getBookAll();
        if(bookList!=null) {
            jedis.set(key,JSON.toJSONString(bookList));
            jedis.expire(key, 3600);
        }
        return bookList;
    }
}
