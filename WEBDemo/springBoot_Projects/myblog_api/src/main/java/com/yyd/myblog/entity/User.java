package com.yyd.myblog.entity;

import lombok.Data;

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

    public User() {
    }

    public int getId() {
        return id;
    }

    public void setId(int id) {
        this.id = id;
    }

    public String getAccount() {
        return account;
    }

    public void setAccount(String account) {
        this.account = account;
    }

    public String getPassword() {
        return password;
    }

    public void setPassword(String password) {
        this.password = password;
    }

    public String getUsername() {
        return username;
    }

    public void setUsername(String username) {
        this.username = username;
    }

    public String getUserdata() {
        return userdata;
    }

    public void setUserdata(String userdata) {
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
