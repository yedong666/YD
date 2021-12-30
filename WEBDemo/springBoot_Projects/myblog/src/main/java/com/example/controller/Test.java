package com.example.controller;

//import com.example.demo.service.UserService;
import com.example.service.UserService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.CrossOrigin;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

import javax.servlet.http.HttpServletRequest;

@RestController
public class Test {
    @Autowired
    private UserService userService;
    
    @RequestMapping("/a")
    public String demp(HttpServletRequest request){
        System.out.println(request.getRequestURL());
        return "damkdmkawkmwamk";
    }

    @RequestMapping("/hello")
    public String test(){
        System.out.println("hello");
        System.out.println(userService.getAllUserInfo().toString());
        return userService.getAllUserInfo().toString();
    }

    @CrossOrigin
    @RequestMapping("/saveArticle")
    public String saveArticle(HttpServletRequest request, String article){
        System.out.println(request.getRequestURL());
        System.out.println(article);
        return "服务器已成功接收表单数据";
    }
}
