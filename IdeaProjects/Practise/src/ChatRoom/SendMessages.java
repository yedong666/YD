package ChatRoom;

import java.io.OutputStream;
import java.io.PrintStream;
import java.util.Scanner;

/*
此类用于发送信息
信息来源主要有两个，终端输入和程序内部消息传递
程序内部消息主要有两种，一个是客户端发送的各种请求，一个是服务器对各种请求的处理结果
 */
public class SendMessages extends Thread{
    Scanner scanner;
    String name;
    PrintStream printStream;
    volatile String orderMessage = null;
    volatile String message;

    SendMessages(OutputStream out, String name){
        scanner = new Scanner(System.in);
        printStream = new PrintStream(out);
        this.name = name;
        setMessage();
    }

    //接收程序内部的请求消息
    public void setOrderMessage(String orderMessage){
        this.orderMessage = orderMessage;
    }

    //通过两个线程获取信息
    public void setMessage(){
        Thread thread1 = new Thread(new Runnable() {
            //此线程用于从终端读取信息
            @Override
            public void run() {
                while(true){
                    message = scanner.nextLine();
                    try {
                        Thread.sleep(200);
                    } catch (InterruptedException e) {
                        e.printStackTrace();
                    }
                }
            }
        });

        Thread thread2 = new Thread(new Runnable() {
            //此线程用于从外部获取信息
            @Override
            public void run() {
                while(true){
                    try {
                        Thread.sleep(200);
                    } catch (InterruptedException e) {
                        e.printStackTrace();
                    }

                    if (orderMessage != null){
                        message = orderMessage;
                    } else{
                        continue;
                    }
                }
            }
        });

        thread1.start();
        thread2.start();
    }

    //结束发送
    public void overSend(){
        printStream.close();
        scanner.close();
    }

    @Override
    public void run(){
        while(true){
            if (message == null){
                try {
                    Thread.sleep(200);
                    continue;
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
            }

            if (message.equals("End")){
                break;
            }

            printStream.println(name + ":" +message);
            printStream.flush();
            orderMessage = null;
            message = null;
        }
        overSend();
    }

}
