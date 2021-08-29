package StudyJavaWeb.Jdbc.jdbcsource;

import com.mchange.v2.c3p0.ComboPooledDataSource;

import javax.sql.DataSource;
import java.sql.Connection;
import java.sql.SQLException;

/**
 * 数据库连接池技术———c3p0测试代码
 */
public class c3p0Test1 {
    public static void main(String[] args) throws SQLException {
        //不传参则使用默认配置，若传递参数则根据参数在配置文件中匹配相应名字的配置
        DataSource dataSource = new ComboPooledDataSource();
        Connection connection = dataSource.getConnection();
        System.out.println(connection);

        for(int i = 0; i < 9; i++){
            Connection connection1 = dataSource.getConnection();
            System.out.println(Integer.toString(i) + connection1);
            if (i == 5){
                connection1.close();
            }
        }
    }
}
