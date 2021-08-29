package ChatRoom;

import java.io.IOException;
import java.net.Socket;

public class Client {
    Socket socket;
    GetMessages getMessages;
    SendMessages sendMessages;

//    private void openClient(){
//        socket = new Socket("localhost", 8080);
//        GetMessages getMessages = new GetMessages(socket.getInputStream());
//        SendMessages sendMessages = new SendMessages(socket.getOutputStream());
//        sendMessages.setName(name);
//        getMessages.start();
//        sendMessages.start();
//    }

    public void sendMessages(String str){
        sendMessages.setOrderMessage(str);
    }

    public Client(String name) throws IOException {
        socket = new Socket("localhost", 8080);
        getMessages = new GetMessages(socket.getInputStream(), name);
        sendMessages = new SendMessages(socket.getOutputStream(), name);
        sendMessages.setName(name);
        getMessages.start();
        sendMessages.start();
    }
}
