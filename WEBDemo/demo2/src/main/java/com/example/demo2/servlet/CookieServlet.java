package com.example.demo2.servlet;

import javax.servlet.*;
import javax.servlet.http.*;
import javax.servlet.annotation.*;
import java.io.IOException;
import java.io.UnsupportedEncodingException;
import java.net.URLDecoder;
import java.net.URLEncoder;
import java.text.SimpleDateFormat;
import java.util.Date;

@WebServlet(name = "CookieServlet", value = "/CookieServlet")
public class CookieServlet extends HttpServlet {
    @Override
    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        this.doPost(request, response);
    }

    @Override
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        Cookie[] cookies = request.getCookies();
        response.setContentType("text/html;charset=utf-8");
        System.out.println("已成功访问此servlet");
        Cookie tempCookie = null;

        boolean flag = false;
        for(Cookie cookie : cookies){
            if(cookie.getName().equals("lastTime")){
                tempCookie = cookie;
                flag = true;
                break;
            }
        }
        if (flag){
            System.out.println("不是第一次访问");
            String lastTime = tempCookie.getValue();
            String decodeLastTime = URLDecoder.decode(lastTime, "utf-8");
            System.out.println(decodeLastTime);
            tempCookie.setValue(getNowTime());
            response.addCookie(tempCookie);
            response.getWriter().write("欢迎会来,您上次访问的时间是" + decodeLastTime);

        }else{
            System.out.println("第一次访问");
            response.addCookie(new Cookie("lastTime", getNowTime()));
            response.getWriter().write("欢迎访问此页面，这是您第一次来哦");
        }
    }


    /**
     * 获取当前时间，并将其URL编码格式化
     * @returng
     * @throws UnsupportedEncodingException
     */
    private String getNowTime() throws UnsupportedEncodingException {
        //获取当前时间
        String nowTime;
        Date date = new Date();
        //定义时间显示格式
        SimpleDateFormat simpleDateFormat = new SimpleDateFormat("yyyy年MM月dd日 hh:mm:ss");
        nowTime = simpleDateFormat.format(date);
        return URLEncoder.encode(nowTime, "utf-8");
    }
}
