package dao;

import bean.User;
import utils.JDBCUtils;
import org.springframework.dao.DataAccessException;
import org.springframework.jdbc.core.BeanPropertyRowMapper;
import org.springframework.jdbc.core.JdbcTemplate;

public class UserDao {
    private final JdbcTemplate jdbcTemplate = new JdbcTemplate(JDBCUtils.getDataSource());

    public boolean insert(String account, String password, String username, String userData){
        try {
            int id = 0;
            String sql = "insert into users values(?, ?, ?, ?, ?)";
            jdbcTemplate.update(sql, id, account, password, username, userData);
        }catch (DataAccessException e){
            e.printStackTrace();
            return false;
        }
        return true;
    }

    public boolean delete(String account){
        try{
            String sql = "delete from users where account = ?";
            jdbcTemplate.update(sql);
        }catch (DataAccessException e){
            return false;
        }
        return true;
    }

    public boolean update(String account, String newPassword, String newUsername, String newUserData){
        try{
            String sql = "update users set password = ?, username = ?, userData = ? where account = ?";
            jdbcTemplate.update(sql, newPassword, newUsername, newUserData, account);
        }catch (DataAccessException e){
            return false;
        }
        return true;
    }

    public User select(String account, String password){
        User user;
        try{
            String sql = "select * from users where account = ? and password = ?";
            user = jdbcTemplate.queryForObject(sql,
                    new BeanPropertyRowMapper<>(User.class), account, password);
        }catch (DataAccessException e){
            return null;
        }
        return user;
    }

    public boolean select(String account){
        User user;
        try{
            String sql = "select * from users where account = ?";
            user = jdbcTemplate.queryForObject(sql,
                    new BeanPropertyRowMapper<>(User.class), account);
            if (user == null){
                return false;
            }
        }catch (DataAccessException e){
            return false;
        }
        return true;
    }
}
