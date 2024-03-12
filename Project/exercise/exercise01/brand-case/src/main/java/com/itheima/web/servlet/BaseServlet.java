package com.itheima.web.servlet;

import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;
import java.lang.reflect.InvocationTargetException;
import java.lang.reflect.Method;

/**
 * @version v1.0
 * @Date:2024-01-20
 * @Description: TODO
 * @Author: yuteng
 */

public class BaseServlet extends HttpServlet {
    @Override
    protected void service(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        // 1.进行请求的分发
        String uri = req.getRequestURI();
        // 2.获取最后一段路径，方法名
        int index  = uri.lastIndexOf('/');
        String methodName =  uri.substring(index+1); // 获取到资源的二级路径

        // 3.执行方法
        // 3.1 获取BrandServlet 字节码对象 Class
        Class<? extends BaseServlet> cls=this.getClass();
        // 3.2 获取方法 Method对象
        try{
            Method method = cls.getMethod(methodName,HttpServletRequest.class,HttpServletResponse.class);
            // 4.调用该方法
            method.invoke(this,req,resp);
        }catch (NoSuchMethodException e) {
            e.printStackTrace();
        } catch (IllegalAccessException e) {
            e.printStackTrace();
        } catch (InvocationTargetException e) {
            e.printStackTrace();
        }

    }
}
