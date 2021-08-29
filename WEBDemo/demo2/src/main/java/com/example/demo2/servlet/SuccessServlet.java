package com.example.demo2.servlet;

import com.example.demo2.dao.User;

import javax.servlet.*;
import javax.servlet.http.*;
import javax.servlet.annotation.*;
import java.io.IOException;

@WebServlet("/SuccessServlet")
public class SuccessServlet extends HttpServlet {
    @Override
    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        this.doPost(request, response);
    }

    @Override
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        User user = (User)request.getAttribute("user");
        response.setContentType("text/html;charset=utf-8");
        response.getWriter().write("登录成功！" + user.getUsername() + ", 欢迎您");
    }
}
