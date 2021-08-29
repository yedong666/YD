package dao;

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
}
