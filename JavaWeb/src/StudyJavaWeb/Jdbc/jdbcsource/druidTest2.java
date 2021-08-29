package StudyJavaWeb.Jdbc.jdbcsource;

import StudyJavaWeb.Jdbc.DruidUtils.DruidUtils;

import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;

//使用工具类连接给数据库连接池连接数据库
public class druidTest2 {
    public static void main(String[] args) throws SQLException {
        Connection con = DruidUtils.getConnection();
        String sql = "insert into table1 values(?, ?, ?, ?)";
        PreparedStatement prest = con.prepareStatement(sql);
        prest.setString(1, "7946");
        prest.setString(2, "YeDong");
        prest.setInt(3, 19);
        prest.setInt(4, 100);
        int count =  prest.executeUpdate();
        System.out.println(count);
        DruidUtils.close(null, prest, con);
    }
}
