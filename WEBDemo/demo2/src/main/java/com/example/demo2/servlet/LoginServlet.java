package com.example.demo2.servlet;

import com.example.demo2.dao.User;
import com.example.demo2.dao.UserDao;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;

@WebServlet("/LoginServlet")
public class LoginServlet extends HttpServlet {
    @Override
    protected void doGet(HttpServletRequest req, HttpServletResponse resp) throws IOException, ServletException {
        System.out.println("已接收请求");
        req.setCharacterEncoding("UTF-8");
        String username = req.getParameter("username");
        String password = req.getParameter("password");
        User loginUser = new User();
        loginUser.setUsername(username);
        loginUser.setPassword(password);
        UserDao userDao = new UserDao();
        User user = userDao.login(loginUser);
        System.out.println("数据已查找完毕!");
        if (user == null){
            System.out.println("查找失败");
            req.getRequestDispatcher("/FailServlet").forward(req, resp);
        }else{
            System.out.println("查找成功");
            req.setAttribute("user", user);
            req.getRequestDispatcher("/SuccessServlet").forward(req, resp);
        }
    }

    @Override
    protected void doPost(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        this.doGet(req, resp);
    }
}
