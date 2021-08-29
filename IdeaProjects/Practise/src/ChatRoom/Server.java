package ChatRoom;

import java.io.IOException;
import java.net.Socket;

/*
子服务器
作用：对与其相连接的客户端提供服务
包含两个线程，一个用于不断接收消息，一个用于发送消息
 */
public class Server extends Thread{
    Socket socket;
    String clientName;
    GetMessages getMessages;
    SendMessages sendMessages;

    public Server(Socket socket, String name){
        this.socket = socket;
        this.clientName = name;
    }

    public void setMessages(String messages){
        System.out.println(messages);
        sendMessages.setOrderMessage(messages);
    }

    public void run(){
        try {
            getMessages = new GetMessages(socket.getInputStream(), clientName);
            sendMessages = new SendMessages(socket.getOutputStream(), "serverFor" + clientName);
            sendMessages.setName(clientName);
            //开始接收消息
            getMessages.start();
            //可发送消息
            sendMessages.start();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
