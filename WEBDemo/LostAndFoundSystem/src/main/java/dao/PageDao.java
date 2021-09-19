package dao;

import bean.Page;
import org.springframework.dao.DataAccessException;
import org.springframework.jdbc.core.BeanPropertyRowMapper;
import org.springframework.jdbc.core.JdbcTemplate;
import utils.JDBCUtils;
import java.util.List;

public class PageDao {
    private final JdbcTemplate jdbcTemplate = new JdbcTemplate(JDBCUtils.getDataSource());

    public List<Page> select(){
        try{
            String sql = "select * from foundpage";
            return jdbcTemplate.query(sql, new BeanPropertyRowMapper<>(Page.class));
        }catch (DataAccessException e){
            e.printStackTrace();
        }
        return null;
    }

    public boolean insert(String author, String title, String mainData, int status, String date){
        try{
            int id = 0;
            String sql =  "insert into foundpage values(?, ?, ?, ?, ?, ?)";
            jdbcTemplate.update(sql, id, author, title, mainData, status, date);
        }catch (Exception e){
            e.printStackTrace();
            return false;
        }
        return true;
    }
}
