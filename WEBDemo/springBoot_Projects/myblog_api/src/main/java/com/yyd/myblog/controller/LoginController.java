package com.yyd.myblog.controller;

import org.apache.ibatis.annotations.Param;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

@RestController
public class LoginController {

    @RequestMapping("/login")
    public String login(@Param("account") String account, @Param("password") String password){
        System.out.println(account);
        System.out.println(password);
        return "backstage";
    }
}
