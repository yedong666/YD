package JavaPractise.Studnets;

public class students {
    int number;
    String name;
    students(){}
    students(int number, String name){
        this.number = number;
        this.name = name;
        System.out.println("我的名字是："+name+"    我的学号是：" + number);
    }
}
