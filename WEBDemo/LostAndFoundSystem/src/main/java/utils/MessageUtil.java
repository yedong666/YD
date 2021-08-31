package utils;

import java.util.Calendar;
import java.util.Date;
import java.util.Random;

/**
 * 处理一些相关信息的工具类
 */
public class MessageUtil {
    public static String createNewAccount(){
        Calendar cal = Calendar.getInstance();
        Random random = new Random();
        int a = cal.get(Calendar.YEAR);
        int b = cal.get(Calendar.DAY_OF_MONTH);
        int c = random.nextInt(8999)+1000;
        return (a + "") + (b + "") + (c + "");
    }
}
