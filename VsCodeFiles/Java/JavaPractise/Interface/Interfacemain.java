//接口的练习
package JavaPractise.Interface;

public class Interfacemain {
    public static void main(String[] args){
        China zhang;
        Japan sanbeng;
        zhang = new China();
        sanbeng = new Japan();
        zhang.number = 32 + Computable.MAX;
        sanbeng.number = 14 + Computable.MAX;
        System.out.println("zhang 的学号" + zhang.number + "zhang的求和结果" + zhang.f(100));
        System.out.println("sanbeng的学号" + sanbeng.number + "sanbeng的求和结果" + sanbeng.f(100));
    }
}
