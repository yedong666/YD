package com.example;

import org.mybatis.spring.annotation.MapperScan;
import org.springframework.boot.SpringApplication;
import org.springframework.boot.autoconfigure.SpringBootApplication;
import org.springframework.context.annotation.ComponentScan;


@SpringBootApplication
@MapperScan(basePackages = {"com.example.mapper"})
/**
 * 关于springBoot整合mybits踩的坑
 * 2021-11-4 ,20:55
 * @MapperScan注解会与@SpringBootApplication(exclude = DataSourceAutoConfiguration.class)冲突
 * 采用@ComponentScan("com.example.demo.mapper")扫描mapper又会导致访问链接时找不到资源，404
 * 解决方法：1.采用@ComponentScan("com.example")
 *         2.采用@//@MapperScan("com.example.demo.mapper")
 *         对于方法1，需要在mapper接口中加入@Mapper注解
 *         对于方法2，需去除@SpringBootApplication(exclude = DataSourceAutoConfiguration.class)中的参数部分
 *
 *2021-12-11， 13:28
 *对之前使用解决方法的理解
 *  对于方法1采用@ComponentScan("com.example")，其实这并没有起到任何作用，因为@SpringBootApplication
 *  注解中已经包含该注解，并且路径相同，真正起到作用的是在mapper包下的接口中添加的@Mapper注解
 *  对于方法22.采用@//@MapperScan("com.example.demo.mapper"),将指定路径下的接口都识别为mapper
 */
public class BlogApplication {
    public static void main(String[] args) {
        SpringApplication.run(BlogApplication.class, args);
    }
}
