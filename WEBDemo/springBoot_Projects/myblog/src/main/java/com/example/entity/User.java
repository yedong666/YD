package com.example.entity;

import lombok.Data;

/*
 * 实体类，加上 @Data 注解
 * 然后就 new 一个实体类，就可以调用属性的 get 和 set 方法。
 * @Data : 注解在类上, 为类提供读写属性, 此外还提供了 equals()、hashCode()、toString() 方法
 * @Getter/@Setter : 注解在类上, 为类提供读写属性
 * @ToString : 注解在类上, 为类提供 toString() 方法
 * @Slf4j : 注解在类上, 为类提供一个属性名为 log 的 log4j 的日志对象
 * @Log4j : 注解在类上, 为类提供一个属性名为 log 的 log4j 的日志对象
 */
@Data
public class User {
    private int id;
    private  String account;
    private  String password;
    private  String username;
    private  String userdata;


    public User(int id, String account, String password, String username, String userdata) {
        this.id = id;
        this.account = account;
        this.password = password;
        this.username = username;
        this.userdata = userdata;
    }

    @Override
    public String toString() {
        return "User{" +
                "id=" + id +
                ", account='" + account + '\'' +
                ", password='" + password + '\'' +
                ", username='" + username + '\'' +
                ", userdata='" + userdata + '\'' +
                '}';
    }
}
