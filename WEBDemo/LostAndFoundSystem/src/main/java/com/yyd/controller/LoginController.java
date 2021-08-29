package com.yyd.controller;

import dao.Page;
import dao.PageDao;
import dao.User;
import dao.UserDao;
import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.web.bind.annotation.RequestMapping;

import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpSession;
import java.util.List;

@Controller
@RequestMapping("/allLoginReq")
public class LoginController {
    @RequestMapping("/login")
    public String test(String account, String password, Model model, HttpServletRequest req){
        System.out.println(account);
        System.out.println(password);
        User loginUser = new User();
        loginUser.setAccount(account);
        loginUser.setPassword(password);
        UserDao userDao = new UserDao();
        User user = userDao.login(loginUser);
        if (user != null){
            System.out.println(user);
            HttpSession session = req.getSession();
            session.setAttribute("HTML", "<h1>加粗字体</h1>");
            session.setAttribute("user", user);
            PageDao pageDao = new PageDao();
            List<Page> pages = pageDao.loadPages();
            System.out.println("开始导入page");
            if (pages == null || pages.size() == 0){
                System.out.println("没有pages");
            }
            for(Page p : pages){
                System.out.println(p.getMainData());
            }
            session.setAttribute("pages", pages);
            return "mainPage";
        }
        return "failedPage";
    }

    @RequestMapping("/returnLogin")
    public String returnIndex(){
        return "loginPage";
    }

    @RequestMapping("/jumpToRegister")
    public String jumpToRegister(){
        return "registerPage";
    }

    @RequestMapping("/jumpToPerson")
    public String jumpToPerson(){
        return "personPage";
    }

    @RequestMapping("/jumpToChangeData")
    public String jumpToChangeData(){
        return "changeData";
    }

    @RequestMapping("/changeData")
    public String changeData(String password, String sex, String age, String birthday,
                                              String username, Model model, HttpServletRequest req){
        HttpSession session = req.getSession();
        String userData = sex+", "+age+"岁，生于"+birthday;
        UserDao userDao = new UserDao();
        User user = (User)session.getAttribute("user");
        String account = user.getAccount();
        boolean flag = userDao.changeData(password, username, userData, account);
        user.setUsername(username);
        user.setPassword(password);
        user.setUserdata(userData);
        session.setAttribute("user", user);
        session.setAttribute("changeDataFlag", flag);
        return "changeData";
    }

    @RequestMapping("/register")
    public String register(String password, String sex, String age, String birthday, String username, Model model){
        String userData = sex+", "+age+"岁，生于"+birthday;
        UserDao userDao = new UserDao();
        String account = userDao.register(password, username, userData);
        if(account == null){
            account = "注册失败!";
        }
        model.addAttribute("account", account);
        return "registerPage";
    }
}
