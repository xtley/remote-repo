package org.example;

import javax.servlet.*;
import javax.servlet.annotation.WebServlet;
import java.io.IOException;

/**
 * @version v1.0
 * @Date:2024-01-12
 * @Description: TODO
 * @Author: yuteng
 */
@WebServlet("/demo1") //第一次被访问时，被tomcat创建该类对象，但是这样会造成第一个访问的人速度慢
// 负整数:第一次访问时创建Servlet对象 0或正整数:服务器启动时创建Servlet对象，默认为-1
//@WebServlet(urlPatterns = "/demo1",loadOnStartup = 1) // 设置=1让服务器启动的时候就创建类

public class ServletDemo1 implements Servlet {

    private ServletConfig servletConfig; //自己添加的config
    //请求处理：每次请求Servlet时，Servlet容器都会调用Servlet的service()方法对请求进行处理
    @Override
    public void service(ServletRequest servletRequest, ServletResponse servletResponse) throws ServletException, IOException {
        System.out.println("servlet hello world~");
    }
    //初始化：在Servlet实例化之后，容器将调用Servlet的init()方法初始化这个对象，完成一些如
    //加载配置文件、创建连接等初始化的工作。该方法只调用一次
    @Override
    public void init(ServletConfig servletConfig) throws ServletException {
        this.servletConfig=servletConfig;
        System.out.println("init");
    }



    // 回去servletConfig对象
    @Override
    public ServletConfig getServletConfig() {
        return null;
    }


    //该方法用来返回Servlet的相关信息，没有什么太大的用处，一般我们返回一个空字符串即可
    @Override
    public String getServletInfo() {
        return null;
    }
//    服务终止：当需要释放内存或者容器关闭时，容器就会调用Servlet实例的destroy()方法完成
//    资源的释放。在destroy()方法调用之后，容器会释放这个Servlet实例，该实例随后会被Java
//            的垃圾收集器所回收
    @Override
    public void destroy() {
        System.out.println("destroy");
    }
}
