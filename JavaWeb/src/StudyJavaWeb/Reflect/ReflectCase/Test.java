package StudyJavaWeb.Reflect.ReflectCase;

import java.lang.reflect.Constructor;
import java.lang.reflect.Method;

public class Test {
    public static void main(String[] args) throws Exception {
        Class cls = Class.forName("StudyJavaWeb.Reflect.ReflectCase.Student");
        Constructor constructor = cls.getDeclaredConstructor(String.class, String.class, String.class);
        Object obj = constructor.newInstance("jack", "s", "ad");
        Method method = cls.getDeclaredMethod("printName");
        method.invoke(obj);
    }
}
