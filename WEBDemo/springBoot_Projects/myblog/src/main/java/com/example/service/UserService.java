package com.example.service;

import com.example.entity.User;
import com.example.mapper.UserMapper;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import java.util.List;

@Service
public class UserService {

    @Autowired
    private UserMapper userMapper;

    /**
     * 对@Autowired注解的理解：
     *    自动注入对象值，使其不为空，避免了new对象
     *    注入对象必须为spring管理的bean, 可以简单理解为被@Service、@Mapper、@Component、@Bean等注标识的对象或方法
     * 发现的一个奇怪的现象:
     *     在整合mybits时，在Application类上添加@MapperSacn注解时，对于mapper包下的类可以不用添加@mapper注解
     *     但若不添加@Mapper注解，则此时在Service中使用@Autowired注入Mapper对象会报错，但项目可以正常启动
     *     推测原因是当项目启动时@MapperScan注解的作用才会生效，即扫描对应包下的类将其视为Mapper,并将之交由spring管理
     *     而在项目启动前spring中是没有该mapper的Bean的
     */

//    public List<User> getAllUserInfo(){
//        return userMapper.getUsersInfo();
//    }

    public List<User> getAllUserInfo(){
        return userMapper.getUsers();
    }

}
