import javax.servlet.*;
import javax.servlet.annotation.WebServlet;
import java.io.IOException;
import java.io.Serializable;

/**
 * @version v1.0
 * @Date:2023-12-20
 * @Description: TODO
 * @Author: yuteng
 */
@WebServlet(urlPatterns = "/myServlet2",loadOnStartup =0)
public class MyServelt2 implements Servlet {

    @Override
    public void init(ServletConfig servletConfig) throws ServletException {
        System.out.println("init...正在初始化......");
    }

    @Override
    public ServletConfig getServletConfig() {
        return null;
    }

    @Override
    public void service(ServletRequest servletRequest, ServletResponse servletResponse) throws ServletException, IOException {
        System.out.println("servlet hello world~servelt上的服务被调用拉......");
    }

    @Override
    public String getServletInfo() {
        return null;
    }

    @Override
    public void destroy() {
        System.out.println("destroy... 正在被销毁..........");
    }
}
