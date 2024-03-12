package com.itheima.service;

import com.itheima.pojo.Brand;

import java.util.List;

/**
 * @version v1.0
 * @Date:2024-01-18
 * @Description: TODO
 * @Author: yuteng
 */
public interface BrandService {
    List<Brand> selectAll();
    void add(Brand brand);
    void deleteByIds(int [] ids);
}
