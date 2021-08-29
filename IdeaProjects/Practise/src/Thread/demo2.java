package Thread;

import java.util.concurrent.locks.ReentrantLock;

public class demo2 {
    public static void main(String[] args){
        TestLock testLock = new TestLock();
        Thread thread1 = new Thread(testLock, "A");
        Thread thread2 = new Thread(testLock, "B");
        Thread thread3 = new Thread(testLock, "C");

        thread1.start();
        thread2.start();
        thread3.start();
    }



}

class TestLock implements Runnable{
    private int testData = 100;
    private final ReentrantLock lock = new ReentrantLock();

    @Override
    public void run() {
       while (true){
          try{
              lock.lock();
              if (testData > 0) {
                  System.out.println(Thread.currentThread().getName() + ": " + testData--);
              } else{
                  return;
              }
          } finally {
              lock.unlock();
          }
       }
    }

}
