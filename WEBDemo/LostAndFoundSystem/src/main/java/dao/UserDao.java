package dao;

import bean.User;
import utils.JDBCUtils;
import org.springframework.dao.DataAccessException;
import org.springframework.jdbc.core.BeanPropertyRowMapper;
import org.springframework.jdbc.core.JdbcTemplate;

public class UserDao {
    private final JdbcTemplate jdbcTemplate = new JdbcTemplate(JDBCUtils.getDataSource());

    public User login(User loginUser){
        System.out.println("开始登录");
        try{
            String sql = "select * from users where account = ? and password = ?";
            User user = jdbcTemplate.queryForObject(sql,
                    new BeanPropertyRowMapper<>(User.class), loginUser.getAccount(), loginUser.getPassword());
            return user;
        } catch (DataAccessException dataAccessException){
            System.out.println("查找失败");
            dataAccessException.printStackTrace();
            return null;
        }
    }

    public String register(String password, String usename, String userData){
        String getMaxId = "select * from users order by id desc limit 1";
        User user = jdbcTemplate.queryForObject(getMaxId, new BeanPropertyRowMapper<>(User.class));
        int id = user.getId() + 1;
        String str = null;
        if (id > 999){
            str = "";
        }else if (id > 99){
            str = "0";
        }else if (id > 9){
            str = "00";
        }else{
            str = "000";
        }
        String account = "2021" + str+ id;
        String createNewUser = "insert into users values(?, ?, ?, ?, ?)";
        jdbcTemplate.update(createNewUser,id, account, password, usename, userData);
        return account;
    }

    public boolean changeData(String password, String usename, String userData, String account){
        String sql = "update users set password = ?, username = ?, userData = ? where account = ?";
        try{
            jdbcTemplate.update(sql, password, usename, userData, account);
        }catch (Exception e){
            System.out.println("更新失败");
            return false;
        }
        return true;
    }

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
