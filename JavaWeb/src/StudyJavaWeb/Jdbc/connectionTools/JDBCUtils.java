package StudyJavaWeb.Jdbc.connectionTools;

import java.io.FileReader;
import java.io.IOException;
import java.net.URL;
import java.sql.*;
import java.util.Properties;

//jdbc连接工具类
public class JDBCUtils {
    static private String url;
    static private String user;
    static private String password;
    static private String driver;



    //静态代码块，用于加载数据库链接、用户名等资源
    static {
        try{
            Properties pro = new Properties();
            ClassLoader classLoader = JDBCUtils.class.getClassLoader();
            URL url1 = classLoader.getResource("jdbc.properties");
            String path = url1.getPath();
            pro.load(new FileReader(path));
            url = pro.getProperty("url");
            user = pro.getProperty("user");
            password = pro.getProperty("password");
            driver = pro.getProperty("driver");
            Class.forName(driver);
        } catch (IOException e){
            System.out.println("读取配置文件信息失败！");
        } catch (ClassNotFoundException e){
            System.out.println("注册驱动失败！");
        }
    }

    //获取连接对象
    static public Connection getConnecton() throws SQLException {
        return DriverManager.getConnection(url, user, password);
    }

    //释放连接对象与sql执行语句
    static public void close(Statement statement, Connection connection) {
        if (statement != null){
            try {
                statement.close();
            } catch (SQLException sqlException){
                sqlException.printStackTrace();
            }
        }
        //注意：不可同时抓取两个SQLException,因为若前一个资源释放时发生异常，则其之后的资源不会被释放
        if (connection != null){
            try{
                connection.close();
            } catch (SQLException sqlException){
                sqlException.printStackTrace();
            }
        }
    }

    //释放返回结果
    static public void close(ResultSet resultSet){
        if (resultSet != null){
            try{
                resultSet.close();
            } catch (SQLException sqlException){
                sqlException.printStackTrace();
            }
        }
    }
}
