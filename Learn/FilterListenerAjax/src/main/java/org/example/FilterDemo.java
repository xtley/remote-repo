package org.example;


import javax.servlet.*;
import javax.servlet.annotation.WebFilter;
import javax.servlet.annotation.WebServlet;
import java.io.IOException;


/**
 * @version v1.0
 * @Date:2024-01-17
 * @Description: TODO
 * @Author: yuteng
 */
//@WebFilter("/*")
public class FilterDemo implements Filter {
    @Override
    public void init(FilterConfig filterConfig) throws ServletException {
        System.out.println("init");
    }

    @Override
    public void doFilter(ServletRequest servletRequest, ServletResponse servletResponse, FilterChain filterChain) throws IOException, ServletException {
        System.out.println("放行前，filter被执行了.....");
        filterChain.doFilter(servletRequest,servletResponse);
        System.out.println("放行后，filter被执行了.....");
    }

    @Override
    public void destroy() {

    }
}
