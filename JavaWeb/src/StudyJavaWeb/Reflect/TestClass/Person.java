package StudyJavaWeb.Reflect.TestClass;

public class Person {
    String name;
    int age;

    public Person() {}

    public Person(String name, int age){
        this.name = name;
        this.age = age;
    }

    public int getAge() {
        return age;
    }

    public String getName(){
        return name;
    }
}
