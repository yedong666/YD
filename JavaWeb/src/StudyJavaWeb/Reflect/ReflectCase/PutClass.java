package StudyJavaWeb.Reflect.ReflectCase;

import org.hamcrest.Condition;

import java.io.InputStream;
import java.lang.reflect.Constructor;
import java.lang.reflect.Method;
import java.util.Properties;

//利用反射，创建任意类，并调用类的任意方法
public class PutClass {
   public static void main(String[] args) throws Exception {
       //创建Properties对象
       Properties pro = new Properties();

       //获取class目录下的配置文件
       ClassLoader classLoader = PutClass.class.getClassLoader();
       InputStream in = classLoader.getResourceAsStream("pro.properties");
       //加载配置文件
       pro.load(in);

       //获取配置文件中定义的数据
       String className = pro.getProperty("className");
       String methodName1 = pro.getProperty("methodName1");
       String methodName2 = pro.getProperty("methodName2");
       String methodName3 = pro.getProperty("methodName3");



       //加载类进内存
       Class cls= Class.forName(className);

       //创建对象
       //Object obj = cls.newInstance();    //已过时，其只能使用无参构造，若没有无参构造，则会抛出异常

       //获取构造器
       Constructor constructor = cls.getDeclaredConstructor(String.class, String.class, String.class);
       //通过构造器生成对象
       Object obj = constructor.newInstance("Jack", "16", "三");

       //创建方法对象
       Method method1= cls.getMethod(methodName1);
       Method method2= cls.getMethod(methodName2);
       Method method3= cls.getMethod(methodName3);

       //使用对象执行方法
       method1.invoke(obj);
       method2.invoke(obj);
       method3.invoke(obj);
   }

}
