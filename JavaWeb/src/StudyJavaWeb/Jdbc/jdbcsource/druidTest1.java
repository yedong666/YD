package StudyJavaWeb.Jdbc.jdbcsource;

import com.alibaba.druid.pool.DruidDataSourceFactory;

import javax.sql.DataSource;
import java.io.IOException;
import java.io.InputStream;
import java.sql.Connection;
import java.util.Properties;

public class druidTest1 {
    public static void main(String[] args) throws Exception {
        Properties properties = new Properties();
        InputStream inputStream = druidTest1.class.getClassLoader().getResourceAsStream("druid.properties");
        properties.load(inputStream);
        DataSource dataSource = DruidDataSourceFactory.createDataSource(properties);
        Connection connection = dataSource.getConnection();
        System.out.println(connection);
    }
}
