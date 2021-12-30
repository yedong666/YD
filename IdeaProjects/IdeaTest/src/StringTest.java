/**
 * 测试String、StringBuffer、StringBuilder类
 */
public class StringTest {
    public static void main(String[] args) throws InterruptedException {
//        String s1 = "abcdefg";
//        StringBuilder stringBuilder = new StringBuilder(s1);
//        StringBuffer stringBuffer = new StringBuffer(s1);
        for(int i = 0; i < 2000; i++){
            new Thread(new TestThread(1)).start();
        }
        Thread.sleep(2000);
        System.out.println("------");
        System.out.println(TestThread.stringBuffer.length());
        System.out.println(TestThread.stringBuilder.length());
    }
}

class TestThread implements Runnable{
    static StringBuilder stringBuilder = new StringBuilder();
    static StringBuffer  stringBuffer = new StringBuffer();
    String string;
    int n;

    public TestThread(String string){
        this.string = string;
    }

    public TestThread(int n){
        this.n = n;
    }
    @Override
    public void run() {
//        stringBuffer.append(1);
        stringBuilder.append(4);
    }

}
