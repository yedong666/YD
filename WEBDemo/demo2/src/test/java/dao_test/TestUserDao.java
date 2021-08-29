package dao_test;

import com.example.demo2.dao.User;
import com.example.demo2.dao.UserDao;
import org.junit.Test;

public class TestUserDao {

    @Test
    public void testLogin(){
        User user = new User();
        user.setUsername("1002");
        user.setPassword("234567");
        UserDao userDao = new UserDao();
        User user1 =  userDao.login(user);
        if (user1 == null){
            System.out.println("该用户不存在");
        }
        System.out.println(user1);
    }
}
