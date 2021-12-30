package com.yyd.myblog.controller;

import org.apache.ibatis.annotations.Param;
import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

import javax.servlet.http.HttpServletRequest;

@RestController
public class SaveArticleController {
    @RequestMapping("/saveArticle")
    public String saveArticle(HttpServletRequest request, @Param("article") String article){
        System.out.println(request.getRequestURL());
        return article;
    }
}
