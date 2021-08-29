package NIOProject;

import java.io.IOException;
import java.net.InetSocketAddress;
import java.nio.ByteBuffer;
import java.nio.channels.*;
import java.nio.charset.Charset;
import java.util.Iterator;
import java.util.Set;

/**
 * NIO服务器端
 */
public class Server {
    public void start() throws IOException {
        /**
         * 1。创建Selector
         */
        Selector  selector = Selector.open();

        /**
         * 2.通过ServerSocketChannel创建Channel通道
         */
        ServerSocketChannel serverSocketChannel = ServerSocketChannel.open();

        /**
         * 3.为channel通道绑定监听窗口
         */
        serverSocketChannel.bind(new InetSocketAddress(8000));

        /**
         * 4.设置channel通道为非阻塞模式
         */
        serverSocketChannel.configureBlocking(false);

        /**
         * 5.将channel注册到Selector上，监听连接事件
         */
        serverSocketChannel.register(selector, SelectionKey.OP_ACCEPT);
        System.out.println("服务器启动成功！");

        /**
         * 6.循环等待新接入的连接
         */
        while(true){
            //获取处于就绪状态的Channels数量
            int readyChannels = selector.select();
            if (readyChannels == 0) continue;
            Set<SelectionKey> selectionKeys = selector.selectedKeys();
            Iterator iterator = selectionKeys.iterator();
            while(iterator.hasNext()){
                SelectionKey selectionKey = (SelectionKey)iterator.next();
                iterator.remove();
                /**
                 * 接入事件处理
                 */
                if (selectionKey.isAcceptable()){
                    acceptHandler(serverSocketChannel, selector);
                }

                /**
                 * 可读事件处理
                 */
                if (selectionKey.isReadable()){
                    readHandler(selectionKey,selector);
                }
            }
        }
    }

    /**
     * 接入事件处理器
     */
    private void acceptHandler(ServerSocketChannel serverSocketChannel, Selector selector) throws IOException {
        /**
         * 创建socketChannel与客户端建立连接
         */
        SocketChannel socketChannel = serverSocketChannel.accept();

        /**
         * 将socketChannel设置为非阻塞模式
         */
        socketChannel.configureBlocking(false);

        /**
         * 将socketChannel注册到Selector上监听可读事件
         */
        socketChannel.register(selector, SelectionKey.OP_READ);

        /**
         * 向客户端返回请求响应
         */
        socketChannel.write(Charset.forName("UTF-8").encode("欢迎进入聊天室！"));
    }

    private void readHandler(SelectionKey selectionKey, Selector selector) throws IOException {
        /**
         * 获取已就绪的channel
         */
        SocketChannel socketChannel = (SocketChannel)selectionKey.channel();

        /**
         *创建buffer
         */
        ByteBuffer byteBuffer = ByteBuffer.allocate(1024);

        /**
         * 循环读取客户端请求信息
         */
        String request = "";
        while(socketChannel.read(byteBuffer) > 0){
            /**
             * 切换buffer为读模式
             */
            byteBuffer.flip();

            /**
             * 读取byteBuffer中的内容
             */
            request += Charset.forName("UTF-8").decode(byteBuffer);
        }

        /**
         * 将channel再次注册到sleector上,监听它的可读事件
         */
        socketChannel.register(selector, SelectionKey.OP_READ);

        /**
         * 将客户端发送的信息广播到其他客户端
         */
        if (request.length() > 0){
            broadCast(selector, socketChannel, request);
        }
    }

    private void broadCast(Selector selector, SocketChannel sourceChannel, String request) {
        /**
         * 获取所有已接入的客户端channel
         */
        Set<SelectionKey> selectionKeys = selector.keys();
        selectionKeys.forEach(selectionKey -> {
            Channel targetChannel =selectionKey.channel();
            //剔除消息来源客户端
            if (targetChannel instanceof SocketChannel && targetChannel != sourceChannel){
                try {
                    ((SocketChannel) targetChannel).write(Charset.forName("UTF-8").encode(request));
                } catch (IOException e){
                    e.printStackTrace();
                }
            }
        });
    }

    /**
     * 主方法
     * @param args
     */
    public static void main(String[] args) throws IOException {
        Server server = new Server();
        server.start();
    }
}
