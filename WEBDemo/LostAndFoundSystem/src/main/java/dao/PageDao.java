package dao;

import org.springframework.dao.DataAccessException;
import org.springframework.jdbc.core.BeanPropertyRowMapper;
import org.springframework.jdbc.core.JdbcTemplate;
import utils.JDBCUtils;
import java.util.List;

public class PageDao {
    private final JdbcTemplate jdbcTemplate = new JdbcTemplate(JDBCUtils.getDataSource());
    public List<Page> loadPages(){
        try{
            String sql = "select * from foundpage";
            return jdbcTemplate.query(sql, new BeanPropertyRowMapper<>(Page.class));
        }catch (DataAccessException e){
            e.printStackTrace();
        }
        return null;
    }
}
