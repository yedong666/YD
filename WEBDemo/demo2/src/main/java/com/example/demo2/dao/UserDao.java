package com.example.demo2.dao;

import com.example.demo2.utils.JDBCUtils;
import org.springframework.dao.DataAccessException;
import org.springframework.jdbc.core.BeanPropertyRowMapper;
import org.springframework.jdbc.core.JdbcTemplate;

public class UserDao {
    private JdbcTemplate jdbcTemplate = new JdbcTemplate(JDBCUtils.getDataSource());

    public User login(User loginUser){
        try{
            String sql = "select * from users where username = ? and password = ?";
            User user = jdbcTemplate.queryForObject(sql,
                    new BeanPropertyRowMapper<>(User.class), loginUser.getUsername(), loginUser.getPassword());
            return user;
        } catch (DataAccessException dataAccessException){
            dataAccessException.printStackTrace();
            return null;
        }
    }
}
