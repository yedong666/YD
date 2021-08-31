package com.yyd.controller;

import bean.User;
import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.RequestMapping;
import service.PageService;
import service.UserService;

import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpSession;
import java.io.UnsupportedEncodingException;

@Controller
@RequestMapping("/allLoginReq")
public class DoController {
    @RequestMapping("/doLogin")
    public String doLogin(String account, String password, HttpServletRequest req){
        HttpSession session = req.getSession();
        if (UserService.login(account, password, session)){
            PageService.showAllPages(session);
            return "mainPage";
        }
        return "failedPage";
    }

    @RequestMapping("/doUpdateUser")
    public String doUpdateUser(String password, String sex, String age, String birthday, String username, HttpServletRequest req){
        HttpSession session = req.getSession();
        String userData = sex+", "+age+"岁，生于"+birthday;
        UserService.updateUser(password, username, userData, session);
        return "changeData";
    }

    @RequestMapping("/doRegister")
    public String register(String password, String sex, String age, String birthday, String username, HttpServletRequest req){
        HttpSession session = req.getSession();
        UserService.register(password, sex, age, birthday, username, session);
        return "loginPage";
    }

    @RequestMapping("/doUpLoadPage")
    public String upLoadPage(String title, String page, HttpServletRequest req) throws UnsupportedEncodingException {
        HttpSession httpSession = req.getSession();
        User user = (User)httpSession.getAttribute("user");
        PageService.placePage(user.getUsername(), title, page, -1, httpSession);
        return "writePage";
    }
}
