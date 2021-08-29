package ChatRoom;

import java.io.IOException;
import java.net.ServerSocket;
import java.util.ArrayDeque;
import java.util.HashMap;
import java.util.Queue;

/*
主服务端
包含所有子服务器
包含所有用户信息
包含请求处理器
包含三个重要线程：
线程1：检测是否有客户端请求连接
线程2：检测客户端是否有新的请求
线程3：处理客户端的请求
 */
public class MainServer {
    int initAccount = 1000;
    ServerSocket serverSocket;
    DisposeOrder disposeOrder;
    volatile HashMap<Integer,Server> servers;
    volatile  HashMap<Integer, User> users;
    int port;

    MainServer() throws IOException {
        //初始化
        init();
        while(true){
            // 启动服务器搜索客户端
            System.out.println("搜索客户端中...");
            Server server = new Server(serverSocket.accept(), Integer.toString(initAccount));
            System.out.println("已发现客户端！");
            //启动服务子线程
            server.start();
            System.out.println("已开始服务该客户端。");
            //将其添加到servers集合
            servers.put(initAccount++, server);
        }
    }

    //初始化服务器
    private void init() throws IOException {
        port = 8080;
        serverSocket = new ServerSocket(port);
        servers = new HashMap<>();
        users = new HashMap<>();
        disposeOrder = new DisposeOrder();
        disposeOrder.start();

        //搜索线程，不断遍历每个子服务器，检测是否有客户端发送新的请求
        Thread searchOreder = new Thread(new Runnable() {
            @Override
            public void run() {
                while(true){
                    //查看是否有新的请求
                    for(Integer acount : servers.keySet()){
                        if (servers.get(acount).getMessages.returnMessage != null){
                            String s = acount.toString() + servers.get(acount).getMessages.returnMessage;
                            disposeOrder.addOrder(s);
                            servers.get(acount).getMessages.returnMessage = null;
                        }
                    }
                    //每查看一次就休息0.2s
                    try {
                        Thread.sleep(200);
                    } catch (InterruptedException e) {
                        e.printStackTrace();
                    }
                }
            }
        });

        searchOreder.start();
    }

    /*
        处理器类
        作用：对所有子服务器收到的信息进行解析，并处理解析结果
     */
    class DisposeOrder extends Thread {
        //请求队列
        volatile Queue<String> orderQueue;

        public DisposeOrder() {
            orderQueue = new ArrayDeque<>();
        }

        //获取请求来源的子服务器
        private Server getUser(String account) {
            return servers.get(Integer.parseInt(account));
        }

        //向命令队列中添加请求
        public void addOrder(String order){
            orderQueue.add(order);
        }

        //处理线程
        public void run() {
            while (true) {
                //不断处理命令队列中的相关命令
                String order = orderQueue.poll();
                if (order == null || order.equals("")) {
                    try {
                        Thread.sleep(200);
                    } catch (InterruptedException e) {
                        e.printStackTrace();
                    }
                    continue;
                } else{
                    int pos = order.indexOf(":") + 1;
                    //根据命令种类标志字符判断请求类型
                    char kindOrder = order.charAt(pos);
                    switch (kindOrder) {
                        case '*':
                            //向其他用户发送信息
                            sendMessagesToOther(order);
                            break;
                        case '#':
                            //请求注册账号
                            reginsterOreder(order);
                            break;
                        case '&':
                            //登录请求
                            logInOrder(order);
                            break;
                        case '$':
                            //查找用户信息
                            searchUserData(order);
                            break;
                        case '@':
                            //添加好友请求
                            addFriends(order);
                            break;
                    }
                }
            }
        }

        //向其他用户发送信息
        private void sendMessagesToOther(String order) {
            int pos = order.indexOf(":");
            String account = order.substring(pos+2, pos+6);
            String messages = order.substring(pos+6);
            System.out.println(account + " "+ messages);
            Server tempUser = getUser(account);
            System.out.println(tempUser.clientName);
            tempUser.setMessages(messages);
        }

        //向服务器请求注册账号
        private void reginsterOreder(String order){
            String returnData = null;
            int pos = order.indexOf("#");
            String userData = order.substring(pos + 1, order.length());
            System.out.println(userData);
            String[] allData;
            allData = userData.split("/");
            System.out.println("密码：" + allData[3]);
            if (allData[3].length() < 6){
                returnData = "密码不符合要求！请重新设置";

            } else{
                User newUser = new User();
                newUser.setName(allData[0]);
                newUser.setAge(allData[1]);
                newUser.setSex(allData[2]);
                newUser.setPassword(allData[3]);
                int newAccount = initAccount;
                newUser.setAccount(newAccount);
                users.put(newAccount, newUser);
                returnData = "注册成功！你的账号为" + newAccount;
            }
            Server tempServer = getUser(order.substring(0, 4));
            tempServer.setMessages(returnData);
        }

        //向服务器请求登录客户端
        private void logInOrder(String order){
            String returnData = null;
            boolean flag = true;
            int pos = order.indexOf("&");
            String userData = order.substring(pos + 1, order.length());
            String[] allData;
            allData = userData.split("/");

            for(Integer integer : users.keySet()){
                //在服务器存储的用户信息中找到对应账号且密码匹配
                if (Integer.parseInt(allData[0]) == integer && users.get(integer).getPassword().equals(allData[1])){
                    returnData = "登录成功!";
                    flag = false;
                    break;
                }
            }

            if (flag){
                returnData = "登录失败！账号或密码错误。";
            }

            Server tempServer = getUser(order.substring(0, 4));
            tempServer.setMessages(returnData);
        }

        //查找相关用户信息
        private void searchUserData(String order){
            int pos = order.indexOf("$");
            String account = order.substring(pos + 1);
            System.out.println(account);
            Server tempServer = getUser(order.substring(0, 4));
            String returnData;
            for(Integer integer : users.keySet()){
                if (integer.equals(Integer.parseInt(account))){
                    User u = users.get(integer);
                    returnData = u.getName() + "/" + u.getSex() + "/" + u.getAge() + "/" + u.getAccount();
                    tempServer.setMessages(returnData);
                    System.out.println(returnData);
                    return;
                }
            }
            tempServer.setMessages("查找用户不存在！");
        }

        private void addFriends(String order){
            int pos = order.indexOf("@");
            System.out.println(order);
            String accountFriend = order.substring(pos+1);
            String accountSource = order.substring(order.length()-4);
            //User user = users.get(Integer.parseInt(accountFriend));
            User source = users.get(Integer.parseInt(accountSource));
            System.out.println(source.getName());
            System.out.println(accountSource);
            Server tempServer = getUser(order.substring(0, 4));
            //String returnData;
            if (source.friends == null || source.friends.get(accountFriend) == null){
                tempServer.setMessages("添加成功！");
            } else{
                 tempServer.setMessages("该用户已在你的好友列表中");
            }

        }
    }

}
