import org.apache.ibatis.io.Resources;
import org.apache.ibatis.session.SqlSession;
import org.apache.ibatis.session.SqlSessionFactory;
import org.apache.ibatis.session.SqlSessionFactoryBuilder;
import org.example.User;
import org.example.mapper.UserMapper;
import org.junit.Test;
import org.junit.runner.RunWith;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.test.context.ContextConfiguration;
import org.springframework.test.context.junit4.SpringJUnit4ClassRunner;

import java.io.IOException;
import java.io.Reader;
import java.util.List;


public class UserTest {
    public void userFindByUsernameTest() {
        String resources = "mybatis-config.xml";
        Reader reader = null;
        try {
            reader = Resources.getResourceAsReader(resources);
        } catch (IOException e) {
            e.printStackTrace();
        }
        SqlSessionFactory sqlMapper = new SqlSessionFactoryBuilder().build(reader);
        SqlSession session = sqlMapper.openSession();
        User user = session.selectOne("findByUsername", "1538446320");
        System.out.println(user.getPassword());
        session.close();
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


