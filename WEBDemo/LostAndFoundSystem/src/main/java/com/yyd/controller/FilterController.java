package com.yyd.controller;

import dao.Page;
import dao.PageDao;
import dao.User;

import javax.servlet.*;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpSession;
import java.io.IOException;
import java.util.List;

/**
 * 资源控制器
 */
public class FilterController implements Filter {

    @Override
    public void init(FilterConfig filterConfig) throws ServletException {

    }

    @Override
    public void doFilter(ServletRequest servletRequest, ServletResponse servletResponse,
                         FilterChain filterChain) throws IOException, ServletException {
        HttpServletRequest httpServletRequest = (HttpServletRequest) servletRequest;
        String url = httpServletRequest.getRequestURI();
        if (url.contains("loginPage.jsp") || url.contains("/allLoginReq") || url.contains("/static") ||
            url.contains("index.jsp") || url.contains("failed.jsp") || url.contains("registerPage.jsp") ||
            url.contains("succPage.jsp")||url.contains("mainPage.jsp")) {
            //加载主页面的动态资源
            filterChain.doFilter(servletRequest, servletResponse);
        } else {
            User user = (User)httpServletRequest.getSession().getAttribute("user");
            if (user != null){
                //若该用户已登录，则放行
                filterChain.doFilter(servletRequest, servletResponse);
            }else{
                httpServletRequest.getRequestDispatcher("loginPage.jsp");
            }
        }
    }

    @Override
    public void destroy() {

    }
}

