/**
 * 测试==与equal()方法的区别
 */
class Student{
    private String name;

    public Student(String name) {
        this.name = name;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }
}
public class EqualTest {
    public static void main(String[] args) {
        Student stu1 = new Student("Jack");
        Student stu2 = new Student("Jack");
        System.out.println(stu1 == stu2);
        System.out.println(stu1 == stu1);
    }
}
