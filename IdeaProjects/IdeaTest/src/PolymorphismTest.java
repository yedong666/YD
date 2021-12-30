/**
 * 测试多态
 */

interface Crying{
    String cry();
}

class Animal implements Crying{
    @Override
    public String cry() {
        return null;
    }
}

class Cat extends Animal{
    @Override
    public String cry() {
        return "喵喵喵";
    }
}

class Dog extends Animal{
    @Override
    public String cry() {
        return "汪汪汪";
    }
}

public class PolymorphismTest {
    public static void main(String[] args) {
        test(new Cat());
        test(new Dog());
    }

    /**
     * 多态带来的好处：
     *      父类类型作为方法形式参数，传递子类对象给方法，进行方法的调用，
     * @param animal
     */
    public static void test(Animal animal){
        System.out.println(animal.cry());
    }
}
