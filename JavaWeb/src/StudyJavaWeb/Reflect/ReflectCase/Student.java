package StudyJavaWeb.Reflect.ReflectCase;

public class Student {
    String name;
    String age;
    String grade;
    int x;

    Student(String name, String age, String grade){
        this.name = name;
        this.age = age;
        this.grade = grade;
    }

    Student(int x){
        this.x = x;
        System.out.println(x);
    }

    Student(){
        this.name = "Tom";
        this.age = "18";
        this.grade = "三";
    }

    public void printName(){
        System.out.println("我叫" + name);
    }

    public void printAge(){
        System.out.println("我" + age + "岁了");
    }

    public void printGrade(){
        System.out.println("我今年" + grade + "年级了");
    }

}
