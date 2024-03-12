package org.example;

import javax.servlet.*;
import javax.servlet.annotation.WebFilter;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpSession;
import java.io.IOException;

/**
 * @version v1.0
 * @Date:2024-01-17
 * @Description: TODO
 * @Author: yuteng
 */
//@WebFilter("/*")
public class LoginFilter implements Filter {

    @Override
    public void init(FilterConfig filterConfig) throws ServletException {

    }

    @Override
    public void doFilter(ServletRequest servletRequest, ServletResponse servletResponse, FilterChain filterChain) throws IOException, ServletException {
        String[] urls =
                {"/login.jsp","/imgs/","/css/","/loginServlet","/register.jsp","/registerServlet","/checkCodeServlet"};
        HttpServletRequest req = (HttpServletRequest) servletRequest;
        String url = req.getRequestURL().toString();
        for (String u : urls) {
            if(url.contains(u)){
                filterChain.doFilter(req, servletResponse);
                return;
            }
        }
        HttpSession session = req.getSession();
        Object user = session.getAttribute("user");

        if(user!=null) {
            filterChain.doFilter(servletRequest,servletResponse);
        }
        else {
            req.setAttribute("login_msg","您尚未登录！");
            req.getRequestDispatcher("/login.jsp").forward(req,servletResponse);
        }
    }

    @Override
    public void destroy() {

    }
}
