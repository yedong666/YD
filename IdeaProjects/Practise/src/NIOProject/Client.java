package NIOProject;

import java.io.IOException;
import java.net.InetSocketAddress;
import java.nio.channels.SelectionKey;
import java.nio.channels.Selector;
import java.nio.channels.SocketChannel;
import java.nio.charset.Charset;
import java.util.Scanner;

/**
 * NIO客户端
 */
public class Client {
    String name;
    public Client(String name){
        this.name = name;
    }
    /**
     * 启动
     */
    public void start() throws IOException {
        /**
         *连接服务器
         */
        SocketChannel socketChannel = SocketChannel.open(new InetSocketAddress("127.0.0.1", 8000));
//        System.out.println("已连接到服务器");

        /**
         * 接收服务器端响应
         * 新开线程，专门用来接收服务端响应
         */

        Selector selector = Selector.open();
        socketChannel.configureBlocking(false);
        socketChannel.register(selector, SelectionKey.OP_READ);
        new Thread(new AcceptResponseData(selector)).start();

        /**
         * 向服务器端发送数据
         */
        Scanner scanner = new Scanner(System.in);
        while(scanner.hasNextLine()){
            String request = scanner.nextLine();
            if (request != null && request.length() > 0){
                socketChannel.write(Charset.forName("UTF-8").encode(name + ":" + request));
            }
        }
    }
}
