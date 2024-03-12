import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;

/**
 * @version v1.0
 * @Date:2023-12-20
 * @Description: TODO
 * @Author: yuteng
 */
// @WebServlet(urlPatterns = {"/myServlet4","/myServlet5"}) //多个地址都可以访问
// @WebServlet(urlPatterns = "/mytest"/myServlet4") // 精确匹配
// @WebServlet(urlPatterns = "/mytest/*") //多个地址都可以访问
// @WebServlet(urlPatterns = "*.do") //扩展名匹配 http://localhost:8080/任意.do
// @WebServlet(urlPatterns = "/") //任意匹配 http://localhost:8080/任意
 @WebServlet(urlPatterns = "/*") //任意匹配 http://localhost:8080/任意
public class MyServlet4 extends HttpServlet {
    @Override
    protected void doGet(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        super.doGet(req, resp);
        System.out.println("Get请求被调用了");
    }

    @Override
    protected void doPost(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        super.doPost(req, resp);
    }

    @Override
    protected void doPut(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        super.doPut(req, resp);
    }

    @Override
    protected void doDelete(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        super.doDelete(req, resp);
    }
}
