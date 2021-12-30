package com.yyd.myblog.mapper;

import com.yyd.myblog.entity.User;
import org.apache.ibatis.annotations.Mapper;

import java.util.List;

@Mapper
public interface UserMapper {
    List<User> selectAllUsers ();
}
