package StudyJavaWeb.Jdbc.DruidUtils;

import com.alibaba.druid.pool.DruidDataSourceFactory;

import javax.sql.DataSource;
import java.io.IOException;
import java.sql.Connection;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;
import java.util.Properties;

public class DruidUtils {
    private  static DataSource ds;

    static {
        //加载配置文件
        Properties pro = new Properties();
        try {
            pro.load(DruidUtils.class.getClassLoader().getResourceAsStream("druid.properties"));
            //根据配置文件获取druid数据库连接池
            ds = DruidDataSourceFactory.createDataSource(pro);
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    public static Connection getConnection() throws SQLException {
        return ds.getConnection();
    }

    public static void close(ResultSet rs, Statement stmt, Connection con){
        if (rs != null){
            try {
                rs.close();
            } catch (SQLException e){
                e.printStackTrace();
            }
        }

        if (stmt != null){
            try {
                stmt.close();
            } catch (SQLException e){
                e.printStackTrace();
            }
        }

        if (con != null){
            try{
                con.close();
            } catch (SQLException e){
                e.printStackTrace();
            }
        }
    }

    //返回连接池对象
    public static DataSource getDataSource(){
        return ds;
    }

}
