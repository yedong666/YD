package com.example.mapper;

import com.example.entity.User;
import org.apache.ibatis.annotations.Mapper;
import org.apache.ibatis.annotations.Select;
import org.springframework.stereotype.Component;

import java.util.List;

@Component
public interface UserMapper {
//    @Select("select * from users")
    //List<User> getUsersInfo ();

    @Select("select * from users;")
    List<User> getUsers();
}
