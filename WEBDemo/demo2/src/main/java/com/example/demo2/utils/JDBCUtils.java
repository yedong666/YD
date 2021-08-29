package com.example.demo2.utils;

import com.alibaba.druid.pool.DruidDataSourceFactory;

import javax.sql.DataSource;
import java.sql.Connection;
import java.sql.SQLException;
import java.util.Properties;

/**
 * 数据库连接工具
 * 使用Druid
 */
public class JDBCUtils {
    private static DataSource ds;

    /**
     * 使用静态代码块从配置文件加载数据库连接池
     */
    static {
        //加载配置文件
        Properties pro = new Properties();
        try {
            pro.load(JDBCUtils.class.getClassLoader().getResourceAsStream("druid.properties"));
            //根据配置文件获取druid数据库连接池
            ds = DruidDataSourceFactory.createDataSource(pro);
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    /**
     * 获取数据库连接池对象
     * @return DataSource Object
     */
    public static DataSource getDataSource(){
        return  ds;
    }

    /**
     * 获取数据库连接对象
     * @return Connection Object
     * @throws SQLException
     */
    public static Connection getConnection() throws SQLException {
        return ds.getConnection();
    }
}
