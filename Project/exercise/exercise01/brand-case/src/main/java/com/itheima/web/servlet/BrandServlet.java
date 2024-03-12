package com.itheima.web.servlet;

import com.alibaba.fastjson.JSON;
import com.itheima.pojo.Brand;
import com.itheima.service.BrandService;
import com.itheima.service.impl.BrandServiceImpl;

import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.BufferedReader;
import java.io.IOException;
import java.util.List;

/**
 * @version v1.0
 * @Date:2024-01-20
 * @Description: TODO
 * @Author: yuteng
 */
@WebServlet("/brand/*")
public class BrandServlet extends BaseServlet{
    private BrandService brandService = new BrandServiceImpl();
    // 用户实现分页查询
    public void selectAll(HttpServletRequest req, HttpServletResponse resp) throws IOException {
        // 1. 调用service查询
        List<Brand> brands =  brandService.selectAll();
        System.out.println(brands);
        // 2.转为JSON
        String jsonString = JSON.toJSONString(brands);
        // 3.写数据
        resp.setContentType("text/json;charset=utf-8");
        resp.getWriter().write(jsonString);
    }
    // 添加企业信息
    public void add(HttpServletRequest req, HttpServletResponse resp) throws IOException {
        // 1.从前端接收品牌数据
        BufferedReader br = req.getReader();
        String params=br.readLine();  //  json字符串
        // 转化为Brand对象
        Brand brand = JSON.parseObject(params,Brand.class);
        // 2.调用service添加
        brandService.add(brand);
        // 3.响应成功的标识
        resp.getWriter().write("success");
    }
    // 修改企业信息
    public void update(HttpServletRequest req, HttpServletResponse resp){

    }
    //删除企业信息
    public void deleteByIds(HttpServletRequest req, HttpServletResponse resp) throws IOException {
        //1. 接收数据 json [1,2,3]
        BufferedReader br = req.getReader();
        String params = br.readLine();//json字符串
        //转为 int[]
        int[] ids = JSON.parseObject(params, int[].class);
        //2. 调用service添加
        brandService.deleteByIds(ids);
        //3. 响应成功的标识
        resp.getWriter().write("success");

    }

}
