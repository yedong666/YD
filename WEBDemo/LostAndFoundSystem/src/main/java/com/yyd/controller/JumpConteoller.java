package com.yyd.controller;

import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.RequestMapping;

/**
 * 页面跳转控制器
 * 用于跳转jsp页面
 */
@Controller
@RequestMapping("/jump")
public class JumpConteoller {
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

    @RequestMapping("/jumpToWritePage")
    public String jumpToWritePage(){
        return "writePage";
    }

    @RequestMapping("/jumpToLogin")
    public String jumpToLogin() {
        return "loginPage";
    }
}
