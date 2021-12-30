package com.yyd.myblog.service;

import com.yyd.myblog.entity.User;
import com.yyd.myblog.mapper.UserMapper;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import java.util.List;

@Service
public class UserService {
    @Autowired
    private UserMapper userMapper;

    public List<User> getAllUserInfo(){
        return userMapper.selectAllUsers();
    }
}
