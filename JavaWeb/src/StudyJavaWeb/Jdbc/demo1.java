package StudyJavaWeb.Jdbc;

import com.mysql.jdbc.Driver;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.Statement;

public class demo1 {
    public static void main(String[] args) throws Exception {
        //导入驱动jar包
        //注册驱动
        Class.forName("com.mysql.jdbc.Driver");
        //获取数据库连接对象
        Connection connection = DriverManager.getConnection("jdbc:mysql://localhost:3306/testdatabase", "root", "wodeweilai2024YYD*");
        //定义sql语句
        String sql1 = "update new_table set grade = 59 where id = 2";
        String sql2 = "update new_table set name = 'yang' where id = 3";
        //获取执行sql语句的对象Statement
        Statement statement = connection.createStatement();
        //执行sql语句
        int count1 = statement.executeUpdate(sql1);
        int count2 = statement.executeUpdate(sql2);
        System.out.println(count2);
        //处理结果
        System.out.println(count1);
        //释放资源
        statement.close();
        connection.close();
    }
}
