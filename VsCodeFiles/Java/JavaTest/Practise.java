package JavaTest;

public class Practise{
    public static void main(String args[]){
        System.out.println("´ó¼ÒºÃ");
        System.out.println("Nice to meet you!");
        Students stu = new Students();
        stu.speak("We are students!");
    }
}
class Students{
    public void speak(String s){
        System.out.println(s);
    }
}