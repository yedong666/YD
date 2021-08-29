package work1;

interface Water{
    void water();
}

interface  Land{
    void land();
}

abstract class animal {
    //名字
    String name;
    //情绪状态
    boolean status;
    //种类
    String kind;
    //是否食肉
    boolean isEatingMeat;
    //生活环境
    String livingEnvironment;
    //叫声
    abstract void cry();
}

class Dog extends animal implements Land{

    String name;

    @Override
    public void land() {
        System.out.println("我能在地上跑！");
    }

    @Override
    void cry() {
        //情绪好时
        if (super.status){
            System.out.println("汪汪汪");
        }
        else{
            System.out.println("呜呜呜");
        }
    }

    //被抚摸
    public void isTouch(){
        System.out.println("这只狗被你摸得很舒服");
        super.status = true;
    }

    //被惊吓
    public void isFrighten(){
        System.out.println("你吓到这只狗了");
        super.status = false;
    }

    //和人打招呼
    public void greetSb(){
        System.out.println("摇摇尾巴");
    }

    public void setName(String name){
        this.name = name;
        System.out.println(this.name + super.name);
    }

    public Dog(){
        super.name = "dog";
        //默认状态良好
        super.status = true;
        //肉食性
        super.isEatingMeat = true;
        //哺乳类
        super.kind = "mammal";
        //陆生
        super.livingEnvironment = "land";
    }
}

class Cat extends animal implements Land{

    @Override
    public void land() {
        System.out.println("我能在地上跑！");
    }

    @Override
    void cry() {
        //情绪好时
        if (super.status){
            System.out.println("咕噜咕噜");
        }
        else{
            System.out.println("嘶嘶嘶");
        }
    }

    //被抚摸
    public void isTouch(){
        System.out.println("这只猫被你摸得很舒服");
        super.status = true;
    }

    //被惊吓
    public void isFrighten(){
        System.out.println("你吓到这只猫了");
        super.status = false;
    }

    //和人打招呼
    public void greetSb(){
        System.out.println("喵~");
    }

    public void setName(String name){
        this.name = name;
    }

    public Cat(){
        super.name = "cat";
        //默认状态良好
        super.status = true;
        //肉食性
        super.isEatingMeat = true;
        //哺乳类
        super.kind = "mammal";
        //陆生
        super.livingEnvironment = "land";
    }
}

class Frog extends animal implements Land, Water{

    @Override
    public void water() {
        System.out.println("我能在水里游");
    }

    @Override
    public void land() {
        System.out.println("我能在地上跳");
    }

    @Override
    void cry() {
        if (super.status){
            System.out.println("呱呱呱");
        }
        else{
            System.out.println("扑通一声跳入水中");
        }
    }

    //被惊吓
    public void isFrighten(){
        super.status = false;
    }

    public Frog(){
        super.name = "frog";
        //默认状态良好
        super.status = true;
        //非肉食性
        super.isEatingMeat = false;
        //两栖类
        super.kind = "amphibian";
        //陆生
        super.livingEnvironment = "land";
    }
}

public class work3 {
    public static void main(String[] args){
        Dog dog = new Dog();
        Cat cat = new Cat();
        dog.greetSb();
        dog.cry();
        dog.isFrighten();
        dog.cry();
    }
}