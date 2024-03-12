import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.BufferedReader;
import java.io.IOException;

/**
 * @version v1.0
 * @Date:2023-12-20
 * @Description: TODO
 * @Author: yuteng
 */
@WebServlet("/req1")
public class RequestDemo01 extends HttpServlet {
    @Override
    protected void doGet(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        // 获取请求行数据
        //------------
        // String getMethod():获取请求方式：GET
        String method = req.getMethod();
        System.out.println("请求方法："+method); // GET
        // String getContextPath():获取虚拟目录(项目访问路径)：/request-demo
        String contextPath = req.getContextPath();
        System.out.println("获取到的虚拟路径："+contextPath);
        // StringBuffer getRequestURL(): 获取URL(统一资源定位符)：http://localhost:8080/request-demo/req1
        StringBuffer url = req.getRequestURL();
        System.out.println("获取到的URL："+url.toString());
        // String getRequestURL():获取URI(统一资源定位符)：/request-demo/req1
        String uri = req.getRequestURI();
        System.out.println("获取到的URI："+uri);
        // String getQueryString():获取请求参数（GET方式）：username=zhangsan
        String queryString = req.getQueryString();
        System.out.println("获取到的请求参数："+queryString);


        //--------------
        // 获取请求头：user-agent:浏览器的版本信息
        String agent = req.getHeader("user-agent");
        System.out.println("获取到的User-agent"+agent);

        //--------------
        // 获取请求体：Get请求的请求体（请求参数）在请求行的url中包含

    }

    @Override
    protected void doPost(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        // super.doPost(req, resp);
        // 获取post 请求体：请求参数

        // 1. 获取字符输入流
        BufferedReader br = req.getReader();
        // 2. 读取数据
        String line = br.readLine();
        System.out.println(line);
    }
}
