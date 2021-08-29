package NIOProject;

import java.io.IOException;
import java.nio.ByteBuffer;
import java.nio.channels.SelectionKey;
import java.nio.channels.Selector;
import java.nio.channels.SocketChannel;
import java.nio.charset.Charset;
import java.util.Iterator;
import java.util.Set;

public class AcceptResponseData implements Runnable{
    private Selector selector;

    public AcceptResponseData(Selector selector) {
        this.selector = selector;
    }

    @Override
    public void run() {
        try{
            while (true) {
                //获取处于就绪状态的Channels数量
                int readyChannels = selector.select();
                //若无就绪状态Channel通道则执行下一次循环
                if (readyChannels == 0) continue;
                //获取响应集合
                Set<SelectionKey> selectionKeys = selector.selectedKeys();
                //迭代selectionKeys
                Iterator iterator = selectionKeys.iterator();
                while (iterator.hasNext()) {
                    SelectionKey selectionKey = (SelectionKey) iterator.next();
                    iterator.remove();
                    /**
                     * 可读事件处理
                     */
                    if (selectionKey.isReadable()) {
                        readHandler(selectionKey, selector);
                    }
                }
            }
        }catch (IOException e){
            e.printStackTrace();
        }
    }

    private void readHandler(SelectionKey selectionKey, Selector selector) throws IOException{
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
        String response = "";
        while(socketChannel.read(byteBuffer) > 0){
            /**
             * 切换buffer为读模式
             */
            byteBuffer.flip();

            /**
             * 读取byteBuffer中的内容
             */
            response += Charset.forName("UTF-8").decode(byteBuffer);
        }

        /**
         * 将channel再次注册到sleector上,监听它的可读事件
         */
        socketChannel.register(selector, SelectionKey.OP_READ);

        /**
         * 处理服务端响应信息
         */
        if (response.length() > 0){
            System.out.println(response);
        }
    }
}
