package Thread;

public class demo1 {
    public static void main(String[] args){
        BuyTicjetsSys b1 = new BuyTicjetsSys();
//        BuyTicjetsSys b2 = new BuyTicjetsSys();
//        BuyTicjetsSys b3 = new BuyTicjetsSys();

        Thread thread1 = new Thread(b1, "马云");
        Thread thread2 = new Thread(b1, "马化腾");
        Thread thread3 = new Thread(b1, "王健林");

        thread2.start();
        thread3.start();
        thread1.start();

    }
}

class BuyTicjetsSys implements Runnable{
    private int ticketNum = 1000;
    private boolean flag = true;
    @Override
    public void run(){
        while(flag){
            synchronized (this) {
                buy();
            }
        }
    }

    //synchornized可修饰代码块也可修饰方法
    //其为重型锁，消耗资源较多

    public void buy(){
        if (ticketNum < 0){
            flag = false;
            System.out.println(Thread.currentThread().getName() + ": 票已买完！");
            return;
        }

        try{
            Thread.sleep(0);
        }catch (InterruptedException e){
            e.printStackTrace();
        }

        System.out.println(Thread.currentThread().getName() + "买了第" + ticketNum + "张票");
        ticketNum--;
    }

}
