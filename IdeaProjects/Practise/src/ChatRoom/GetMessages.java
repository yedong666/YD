package ChatRoom;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;

//接收信息类
//用作客户端与服务端的信息传播媒介
public class GetMessages extends Thread{
    BufferedReader bufferedReader;
    String messages;
    volatile String returnMessage;

    //传入套接字输入流
    GetMessages(InputStream in, String nmae){
        bufferedReader = new BufferedReader(new InputStreamReader(in));
    }

    @Override
    public void run(){
        if (bufferedReader == null){
            System.out.println("未连接流！");
        }

        while(true){
            try {
                messages = bufferedReader.readLine();
                if (messages.equals("END")){
                    System.out.println("结束聊天！");
                    bufferedReader.close();
                    break;
                }
                returnMessage = messages;
                System.out.println(messages);
            } catch (Exception e){
                System.out.println("获取信息异常！");
                break;
            }
        }
    }
}
