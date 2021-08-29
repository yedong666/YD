package PractiseDemo;

import java.util.concurrent.Callable;
import java.util.concurrent.FutureTask;

public class ThreadDemo {
    public static void main(String[] args){

        MyThread1 myThread = new MyThread1();
        MyRunAble myRunAble = new MyRunAble();
        MyCallAble myCallAble = new MyCallAble();
        FutureTask<Integer> futureTask = new FutureTask<>(myCallAble);

        myThread.start();
        new Thread(futureTask, "ThreadC").start();
        new Thread(myRunAble, "ThreadA").start();;
        new Thread(myRunAble, "ThreadB").start();;

        for(int i = 0; i < 100; i++){
            System.out.println(Thread.currentThread().getName());
        }

        System.out.println("futureTask is: " + futureTask);
    }
    
}

//通过继承Thread类，创建线程
class MyThread1 extends Thread{
    public void run(){
        for(int i = 0; i < 100; i++){
            System.out.println(this.getName());
        }
    }
}

//通过实现Runable接口创建线程, 以Runable的实例对象作为Thread的target
class MyRunAble implements Runnable{
    @Override
    public void run(){
        for(int i = 0; i < 100; i++){
            System.out.println(Thread.currentThread().getName());
        }
    }
}

//通过实现Callable接口创建线程,用FutureTask类包装Callable的实例对象，FutureTask的实例对象作为Thread的target
class MyCallAble implements Callable<Integer>{
    @Override
    public Integer call(){
        for(int i = 0; i < 100; i++){
            System.out.println(Thread.currentThread().getName());
        }
        Integer integer = 1;
        return integer;
    }
}

/*
    
 */