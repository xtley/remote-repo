import javax.servlet.ServletException;
import javax.servlet.ServletOutputStream;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;
import java.io.PrintWriter;

/**
 * @version v1.0
 * @Date:2024-01-10
 * @Description: TODO
 * @Author: yuteng
 */
@WebServlet("/MyServlet")
public class MyServlet extends HttpServlet {
    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        response.setContentType("text/html;charset=UTF-8"); // 设置响应内容类型及字符编码
        PrintWriter writer = response.getWriter();
        writer.write("软工班真棒"); // 响应字符串数据
    }
}
