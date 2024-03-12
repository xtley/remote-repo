package org.example;

import org.apache.ibatis.io.Resources;
import org.apache.ibatis.session.SqlSession;
import org.apache.ibatis.session.SqlSessionFactory;
import org.apache.ibatis.session.SqlSessionFactoryBuilder;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;
import java.io.PrintWriter;
import java.io.Reader;
import java.util.Map;
import java.util.Objects;

/**
 * @version v1.0
 * @Date:2023-12-21
 * @Description: TODO
 * @Author: yuteng
 */
@WebServlet("/RegisterServlet")
public class RegisterServlet extends HttpServlet {
    @Override
    protected void doGet(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        //super.doGet(req, resp);
        resp.setContentType("text/html;charset=utf-8");
        resp.setCharacterEncoding("utf-8");
        // System.out.println("servlet集成成功");
        System.out.println("post....");
        //1. 获取所有参数的Map集合
        Map<String, String[]> map = req.getParameterMap();
        for (String key : map.keySet()) {
            // username:zhangsan lisi
            System.out.print(key+":");

            //获取值
            String[] values = map.get(key);
            for (String value : values) {
                System.out.print(value + " ");
            }

            System.out.println();
        }

        System.out.println("------------");

        //2. 根据key获取参数值，数组
//        String[] hobbies = req.getParameterValues("hobby");
//        for (String hobby : hobbies) {
//
//            System.out.println(hobby);
//        }

        String username = req.getParameter("username");
        String password = req.getParameter("password");
        String phone = req.getParameter("phone");

        System.out.println(username);
        System.out.println(password);
        System.out.println(phone);
        boolean ok=userFindByUsernameTest(username,password);
        if(!ok) {
            PrintWriter writer = resp.getWriter();
            //writer.write("登录成功");
            //req.getRequestDispatcher("LoginSucceed.html").forward(req,resp); //转发指定页面会有编码问题还没有解决
            addUserTest(username,password,phone);
            resp.getWriter().print("<h1>注册成功</h1>");
            resp.setStatus(302);
            resp.setHeader("location","Login.html");
            resp.sendRedirect("Login.html");
        }
        else {
            PrintWriter writer = resp.getWriter();
            resp.getWriter().print("<h1>注册失败，用户名已经存在！</h1>");
            resp.setStatus(302);
            resp.setHeader("location","Register.html");
            resp.sendRedirect("Register.html");
        }
    }

    @Override
    protected void doPost(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        //super.doPost(req, resp);
        resp.setContentType("text/html;charset=utf-8");
        resp.setCharacterEncoding("utf-8");
        //POST请求逻辑
        //this.doGet(req,resp);

        System.out.println("post....");
        //1. 获取所有参数的Map集合
        Map<String, String[]> map = req.getParameterMap();
        for (String key : map.keySet()) {
            // username:zhangsan lisi
            System.out.print(key+":");

            //获取值
            String[] values = map.get(key);
            for (String value : values) {
                System.out.print(value + " ");
            }

            System.out.println();
        }

        System.out.println("------------");

        //2. 根据key获取参数值，数组
//        String[] hobbies = req.getParameterValues("hobby");
//        for (String hobby : hobbies) {
//
//         System.out.println(hobby);
//        }

        //3. 根据key 获取单个参数值
        String username = req.getParameter("username");
        String password = req.getParameter("password");
        String phone = req.getParameter("phone");

        System.out.println(username);
        System.out.println(password);
        System.out.println(phone);
        boolean ok=userFindByUsernameTest(username,password);
        if(!ok) {
            addUserTest(username,password,phone);
            resp.getWriter().print("<h1>注册成功</h1>");
//            resp.setStatus(302);
//            resp.setHeader("location","Login.html");
//            resp.sendRedirect("Login.html");
        }
        else {
            PrintWriter writer = resp.getWriter();
            resp.getWriter().print("<h1>注册失败，用户名已经存在！</h1>");
            resp.setStatus(302);
            //resp.setHeader("location","Register.html");
            //resp.sendRedirect("Register.html");
        }
    }
    public boolean userFindByUsernameTest(String username,String password) {
        String resources = "mybatis-config.xml";
        Reader reader = null;
        try {
            reader = Resources.getResourceAsReader(resources);
        } catch (IOException e) {
            e.printStackTrace();
        }
        SqlSessionFactory sqlMapper = new SqlSessionFactoryBuilder().build(reader);
        SqlSession session = sqlMapper.openSession();
        User user = session.selectOne("findByUsername", username);

        if(user==null) {
            return false;
        }
        else if(Objects.equals(user.getPassword(), password)) {
            return true;
        }
        else {
            return false;
        }
    }
    public void addUserTest(String username,String password,String phone) {
        String resources = "mybatis-config.xml";
        Reader reader = null;
        try {
            reader = Resources.getResourceAsReader(resources);
        } catch (IOException e) {
            e.printStackTrace();
        }
        SqlSessionFactory sqlMapper = new SqlSessionFactoryBuilder().build(reader);
        SqlSession session = sqlMapper.openSession();
        User user=new User();
        user.setUsername(username);
        user.setPassword(password);
        user.setPhone(phone);
        int result =session.insert("org.example.mapper.UserMapper.addUser",user);
        session.commit();
        if(result>0) {
            System.out.println("注册成功");
        }
        else {
            System.out.println("失败");
        }

    }
}
