package com.yyd.myblog;

import org.springframework.boot.SpringApplication;
import org.springframework.boot.autoconfigure.SpringBootApplication;
import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestParam;
import org.springframework.web.bind.annotation.RestController;

@SpringBootApplication
@Controller
public class Test {
    public static void main(String[] args) {
        SpringApplication.run(Test.class, args);
    }

    @RequestMapping("/yydBlog")
    public String hello() {
//        return String.format("Hello %s! 这就是springBoot", name);
        return "index";
    }
}
