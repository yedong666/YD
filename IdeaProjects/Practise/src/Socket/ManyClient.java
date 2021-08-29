package Socket;

import java.io.*;
import java.net.*;
import java.util.Scanner;
import java.util.Vector;
import java.lang.Thread;

public class ManyClient{
    public static void main(String[] args) throws IOException{
        Server1 server = new Server1();
    }
}

//服务客户端的Socket类
class MySocket extends Thread{
    Socket socket;
    private Scanner scanner;
    private BufferedReader in;
    private PrintStream out;
    MySocket(Socket socket){
        this.socket = socket;
        scanner = new Scanner(System.in);
        try{
            in = new BufferedReader(new InputStreamReader(socket.getInputStream()));
            out = new PrintStream(socket.getOutputStream());
        } catch (IOException e){
            System.out.println("服务端接收数据异常");
        }

        this.start();
    }

    public void run(){
        String getStr = null, returnStr = null;
        try{
            while(getStr != "END"){
                System.out.println("开始聊天！");
                getStr = in.readLine();
                System.out.println(getStr);
                returnStr = scanner.nextLine();
                out.println(returnStr);
                out.flush();
                //System.out.println("server: " + returnStr);
            }
        } catch (IOException e){
            System.out.println("服务端读取数据异常！");
        }
    }
}

//服务端
class Server1{
    final int maxNumClient = 10;
    Server1() throws IOException{
        ServerSocket server = new ServerSocket(8080);
        Vector<Socket> mySockets = new Vector<>();
        System.out.println("初始化成功！");
        while(mySockets.size() < maxNumClient){
            try{
                //每检测到一个客户端
                Socket socket = server.accept();
                //就对其新建一个服务对象
                MySocket mySocket = new MySocket(socket);
                System.out.println("连接成功！");

                mySockets.add(socket);
            } catch(IOException e){
                System.out.println("创建服务端失败！");
            }
        }
    }
}

//客户端
class Client1 extends Thread{
    private String name;
    private Socket clientSocket;
    private Scanner scanner;
    private BufferedReader in;
    private PrintStream out;

    Client1(String name) throws IOException{
        this.name = name;
        clientSocket = new Socket("127.0.0.1", 8080);
        scanner = new Scanner(System.in);
        in = new BufferedReader(new InputStreamReader(clientSocket.getInputStream()));
        out = new PrintStream(clientSocket.getOutputStream());
        this.start();
    }

    public void run(){
        String getStr = null;
        String returnStr = null;
        System.out.println("已连接到服务器，开始聊天：");
        try{
            while(getStr != "END"){
                //当接收到服务端的信息为END时结束
                //System.out.println("客户端开始发送信息：");
                returnStr = scanner.next();
                out.println(this.name + ": " + returnStr);
                out.flush();
                //System.out.println(this.name + ":" + returnStr);
                getStr = in.readLine();
                System.out.println("server: " + getStr);
            }
            clientSocket.close();
        } catch(IOException e){
            System.out.println("读取数据失败！");
        }
    }
}


