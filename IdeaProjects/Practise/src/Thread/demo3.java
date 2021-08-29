package Thread;

import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;

public class demo3 {
    public static void main(String[] args) {
        //创建线程池
        ExecutorService threadPool = Executors.newFixedThreadPool(10);
        //在线程池中新建线程
        threadPool.execute(new MyThread());
    }
}

class MyThread implements Runnable{
    @Override
    public void run() {
        for(int i = 0; i < 100; i++){
            System.out.println(Thread.currentThread().getName());
        }
    }
}
