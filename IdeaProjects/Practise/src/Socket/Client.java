package Socket;

import java.io.*;
import java.net.Socket;

public class Client {
    public static void main(String[] args) throws IOException {
        String str = null;
        String s = null;
        Socket client = new Socket("127.0.0.1", 7946);
        //System.out.println("client:");
        //从套接字获取的输入流
        BufferedReader severIn = new BufferedReader(new InputStreamReader(client.getInputStream()));
        //从键盘获取输入流
        BufferedReader systemIn = new BufferedReader(new InputStreamReader(System.in));
        //获取流向套接字的输出流
        PrintStream out = new PrintStream(client.getOutputStream());
        //从键盘读取一串字符
        str = systemIn.readLine();
        //将这串字符发送到服务端，并显示
        out.println(str);
        //刷新out
        out.flush();
        //从服务端获取一串字符
        s = severIn.readLine();
        System.out.println("server:");
        //在客户端打印出来
        System.out.println(s);
    }
}
