package com.example.demo1;

import java.io.*;
import javax.servlet.http.*;
import javax.servlet.annotation.*;

@WebServlet(name = "helloServlet", value = "/hello-servlet")
public class HelloServlet extends HttpServlet {
    private String message;

    public void init() {
        message = "<!DOCTYPE html>\n" +
                "<html lang=\"en\">\n" +
                "<head>\n" +
                "    <meta charset=\"GBK\">\n" +
                "    <title>HTML文件</title>\n" +
                "</head>\n" +
                "<body bgcolor=\"aqua\">\n" +
                "    Hello\n" +
                "    <img src=\"/demo1/src/main/webapp/IMAGE/img1.jpg\">\n" +
                "    <p style=\"border: aqua solid\"> 你好</p>\n" +
                "</body>\n" +
                "</html>";
    }

    public void doGet(HttpServletRequest request, HttpServletResponse response) throws IOException {
        response.setContentType("text/html");

        // Hello
        PrintWriter out = response.getWriter();
//        out.println("<html><body>");
        out.println("<h1>" + message + "</h1>");
//        out.println("</body></html>");
    }

    public void destroy() {
    }
}