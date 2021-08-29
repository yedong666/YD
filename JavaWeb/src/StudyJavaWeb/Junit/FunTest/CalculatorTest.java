package StudyJavaWeb.Junit.FunTest;

import StudyJavaWeb.Junit.Fun.Caculator;
import org.junit.After;
import org.junit.Assert;
import org.junit.Before;
import org.junit.Test;

public class CalculatorTest {
    Caculator caculator = new Caculator();

    /**
     * 初始化资源方法：
     * 在所有测试程序开始执行前都会先执行此方法
     */
    @Before
    public void init(){
        System.out.println("init....");
    }

    /**
     * 测试sum方法
     */
    @Test
    public void testSum(){
        int a = 3, b = 5;

        //System.out.println(a + " + " + b + " = " + calculator.sub(a, b));
        //通常不使用输出语句来判定，而是使用断言Assert

        int sum = caculator.sum(a, b);
        Assert.assertEquals(8, sum);
    }

    /**
     * 测试sub方法
     */
    @Test
    public void testSub(){
        int a = 100, b = 8;

        int sub = caculator.sub(a, b);

        Assert.assertEquals(92, sub);
    }


    /**
     * 回收资源方法：
     * 在所有测试方法结束后都会执行此方法用以释放资源
     */
    @After
    public void close(){
        System.out.println("close....");
    }
}



/*
 * 对于测试成功与否不能单凭输出结果判定
 * 需根据终端提示颜色加以判定
 */
