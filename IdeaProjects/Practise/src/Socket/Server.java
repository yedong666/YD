package Socket;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintStream;
import java.net.ServerSocket;
import java.net.Socket;

public class Server {
    public static void main(String[] args) throws IOException {
        String str = null;
        String s = null;
        ServerSocket serverSocket = new ServerSocket(7946);
        Socket socket = serverSocket.accept();
        //System.out.println("server:");
        BufferedReader socketIn = new BufferedReader(new InputStreamReader(socket.getInputStream()));
        //从键盘获取输入流
        BufferedReader systemIn = new BufferedReader(new InputStreamReader(System.in));
        //获取流向套接字的输出流
        PrintStream out = new PrintStream(socket.getOutputStream());
        //获取客服端发送过来的字符串
        str = socketIn.readLine();
        System.out.println("client:");
        //显示该字符啊串
        System.out.println(str);
        //在键盘输入一串字符
        s = systemIn.readLine();
        //并发送到客户端
        out.println(s);
        //刷新
        out.flush();
    }
}
