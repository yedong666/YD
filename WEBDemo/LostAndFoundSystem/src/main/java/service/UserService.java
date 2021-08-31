package service;

import bean.User;
import dao.UserDao;
import org.springframework.ui.Model;
import utils.MessageUtil;

import javax.servlet.http.HttpSession;

public class UserService {
    private static final String errorAccount = "aabbccddee";
    /**
     * 数据库访问对象
     */
    static private UserDao userDao;

    static{
        userDao = new UserDao();
    }

    private static String createNewAccount(){
        int i = 0;
        while (i < 10){
            String account = MessageUtil.createNewAccount();
            if (!userDao.select(account)){
                return account;
            }
            i++;
        }
        System.out.println("警告！警告！账户数量已超标！");
       return errorAccount;
    }

    /**
     * 用户登录
     * @param  account 账号
     * @param password 密码
     */
    public static boolean login(String account, String password, HttpSession session){
        User user = userDao.select(account, password);
        if (user != null){
            session.setAttribute("user", user);
            return true;
        }
        return false;
    }

    /**
     * 用户注册
     * @param password 密码
     * @param sex 性别
     * @param age 年龄
     * @param birthday 生日
     * @param username 用户名
     * @return account/error
     */
    public static boolean register(String password, String sex, String age, String birthday, String username, HttpSession session){
        /**
         * 组合部分表单信息，用以填充user表中的userData字段
         */
        String userData = sex+", "+age+"岁，生于"+birthday;
        String account = createNewAccount();
        System.out.println(account);
        /**
         * 访问数据库，添加该注册用户信息
         */
        if (userDao.insert(account, password, username,userData)){
            session.setAttribute("registerMessage", "注册成功!你的账户为:"+account);
            return true;
        }
        session.setAttribute("registerMessage", "注册失败!");
        return false;
    }

    public static boolean updateUser(String newPassword, String newUsername, String newUserData, HttpSession session){
        User user = (User)session.getAttribute("user");
        if (userDao.update(user.getAccount(), newPassword, newUsername, newUserData)){
            user.setPassword(newPassword);
            user.setUserdata(newUserData);
            user.setUsername(newUsername);
            session.setAttribute("user", user);
            session.setAttribute("updateMessage", "信息已修改");
            return true;
        }
        session.setAttribute("updateMessage", "信息修改失败, 请稍后再试!");
        return false;
    }
}
