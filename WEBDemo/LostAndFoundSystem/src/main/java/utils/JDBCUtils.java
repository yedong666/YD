package utils;

import java.sql.Connection;
import java.sql.DatabaseMetaData;
import java.util.Properties;
import javax.sql.DataSource;
import org.apache.commons.dbcp.BasicDataSourceFactory;

public class JDBCUtils {
    private static final String configFile = "db.properties";

    private static DataSource dataSource;

    static {
        Properties dbProperties = new Properties();
        try {
            //加载配置文件
            dbProperties.load(JDBCUtils.class.getClassLoader().getResourceAsStream(configFile));
            System.out.println("已成功加载配置文件");
            //获取数据库连接池
            dataSource = BasicDataSourceFactory.createDataSource(dbProperties);
            System.out.println("已成功获取数据库连接池");
            //获取从数据库连接池获取数据库连接对象
            Connection conn = getConnection();
            //获取连接数据库相关信息
            DatabaseMetaData mdm = conn.getMetaData();
            System.out.println("Connected to " + mdm.getDatabaseProductName() + " " + mdm.getDatabaseProductVersion());
            if (conn != null) {
                conn.close();
            }
        } catch (Exception e) {
            System.out.println("初始化连接池失败:" + e);
        }
    }

    private JDBCUtils() {}

    public static final Connection getConnection() {
        Connection conn = null;
        try {
            conn = dataSource.getConnection();
        } catch (Exception e) {
            System.out.println("获取数据库连接失败:" + e);
        }
        return conn;
    }

    //关闭数据库连接，将连接返还给数据库连接池
    public static void closeConn(Connection conn) {
        try {
            if (conn != null && !conn.isClosed()) {
                conn.setAutoCommit(true);
                conn.close();
            }
        } catch (Exception e) {
            System.out.println("关闭数据库连接失败：" + e);
        }
    }

    public static DataSource getDataSource(){
        return dataSource;
    }

}