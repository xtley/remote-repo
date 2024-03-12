package com.itheima.mapper;

import com.itheima.pojo.Brand;
import org.apache.ibatis.annotations.Param;
import org.apache.ibatis.annotations.ResultMap;

import java.util.List;

public interface BrandMapper {
    @ResultMap("brandResultMap")
    List<Brand> selectAll();
    void add(Brand brand);
    void deleteById(@Param("ids") int [] ids);
}
