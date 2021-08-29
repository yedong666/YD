package StudyJavaWeb.Reflect.TestReflect;

import StudyJavaWeb.Reflect.TestClass.*;

public class ReflectDemo {
    public static void main(String[] args) throws ClassNotFoundException {
        Class cls1 = Class.forName("StudyJavaWeb.Reflect.TestClass.Person");
        Class cls2 = Person.class;
        Person p = new Person();
        Class cls3 = p.getClass();
        System.out.println(cls1);
        System.out.println(cls2);
        System.out.println(cls3);
    }
}
