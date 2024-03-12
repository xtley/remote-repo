package com.itheima.service.impl;

import com.itheima.mapper.BrandMapper;
import com.itheima.pojo.Brand;
import com.itheima.service.BrandService;
import com.itheima.util.SqlSessionFactoryUtils;
import org.apache.ibatis.session.SqlSession;
import org.apache.ibatis.session.SqlSessionFactory;

import java.util.List;
import java.util.stream.BaseStream;

/**
 * @version v1.0
 * @Date:2024-01-18
 * @Description: TODO
 * @Author: yuteng
 */
public class BrandServiceImpl implements BrandService {

    // 1. 创建SqlSessionFactory 工厂对象
    SqlSessionFactory factory = SqlSessionFactoryUtils.getSqlSessionFactory();
    @Override
    public List<Brand> selectAll() {
        // 2.获取SqlSession对象
        SqlSession sqlSession = factory.openSession();
        // 3.获取BrandMapper
        BrandMapper mapper = sqlSession.getMapper(BrandMapper.class);
        // 4.调用方法
        List<Brand> brands = mapper.selectAll();
        // 5.释放资源
        sqlSession.close();
        return brands;
    }

    @Override
    public void add(Brand brand) {
        // 2.获取SqlSession对象
        SqlSession sqlSession = factory.openSession();
        // 3.获取BrandMapper
        BrandMapper mapper = sqlSession.getMapper(BrandMapper.class);
        // 4.调用方法
        mapper.add(brand);
        sqlSession.commit(); //提交事务
        // 注意：增删改操作一定要提交事务。
        // 5.释放资源
        sqlSession.close();
    }

    @Override
    public void deleteByIds(int[] ids) {
        SqlSession sqlSession =factory.openSession();
        BrandMapper mapper = sqlSession.getMapper(BrandMapper.class);
        mapper.deleteById(ids);
        sqlSession.commit();
        sqlSession.close();
    }
}
