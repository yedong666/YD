package Exercise;

class IntConsumer{
    public void accept(int x){
        System.out.print(x);
    }
}

class ZeroEvenOdd {
    private int n;
    volatile int i;
    volatile int status = 0;

    public ZeroEvenOdd(int n) {
        this.n = n;
        this.i = 1;
    }

    // printNumber.accept(x) outputs "x", where x is an integer.
    public void zero(IntConsumer printNumber) throws InterruptedException {
        while(this.i <= n) {
            if (status == 0) {
                printNumber.accept(0);
                if (i % 2 == 0) {
                    status = 1;
                } else {
                    status = 2;
                }
            }
        }
    }

    public void even(IntConsumer printNumber) throws InterruptedException {
        while(this.i <= n){
            if (status == 1) {
                printNumber.accept(i);
                i++;
                status = 0;
            }
        }
    }

    public void odd(IntConsumer printNumber) throws InterruptedException {
        while(this.i <= n){
            if (status == 2) {
                printNumber.accept(i);
                i++;
                status = 0;
            }
        }
    }
}

public class ZEO{
    public static void main(String[] args) {
        ZeroEvenOdd zeroEvenOdd = new ZeroEvenOdd(2);
        IntConsumer intConsumer = new IntConsumer();
        Thread thread1 = new Thread(new Runnable() {
            @Override
            public void run() {
                try {
                    zeroEvenOdd.zero(intConsumer);
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
            }
        });

        Thread thread2 = new Thread(new Runnable() {
            @Override
            public void run() {
                try {
                    zeroEvenOdd.even(intConsumer);
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
            }
        });

        Thread thread3 = new Thread(new Runnable() {
            @Override
            public void run() {
                try {
                    zeroEvenOdd.odd(intConsumer);
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
            }
        });

        thread1.start();
        thread2.start();
        thread3.start();
    }
}