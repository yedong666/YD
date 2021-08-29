package ChatRoom;

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.util.HashMap;

/*
客户端主窗口
主要包含三个部分：消息接收，好友列表展示，个人信息设置
 */
public class MainWindow extends JFrame {
    final int MESSAGES = 1;
    final int FRIENDS = 2;
    final int MINE = 3;
    MainWindow mainWindow;
    volatile Client client;
    int flag;
    User I;
    JButton messagesList;
    JButton friendsList;
    JButton mine;
    JPanel menuBar;
    BgPanelMessage messages;
    JPanel friends;
    JPanel myData;
    JLabel searchFriend;
    JTextField searchField;
    JButton searchButton;
    JPanel tempPanel;
    BgPanelFriend bgPanelFriend;
    HashMap<String, ChatWindow> freinedChatWindows;

    public MainWindow(Client c, User user){
        super();
        this.client = c;
        this.I = user;
        this.setLocation(550, 0);
        init();
        addListener();
        freinedChatWindows = new HashMap<String, ChatWindow>();
        showMessages();
        this.setVisible(true);
        this.setResizable(false);
        this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    }

    //从服务端获取用户信息
    public void getUserData(User user){

    }

    //接收消息并显示
    public void showMessages(){
        Thread getMessages = new Thread(new Runnable() {
            @Override
            public void run() {
                while(true){
                    if (client.getMessages.returnMessage != null){
                        String tempStr = client.getMessages.returnMessage;
                        int pos = tempStr.indexOf(":");
                        char kindMessage = tempStr.charAt(pos + 1);
                        if (kindMessage == '|'){
                            ChatWindow chatWindow = freinedChatWindows.get(tempStr.substring(pos+2, pos+6));
                            if (chatWindow != null){
                                chatWindow.getMessage(tempStr.substring(pos + 6));
                                client.getMessages.returnMessage = null;
                                System.out.println("returnStr:");
                            }
                        }
                    }
                }
            }
        });
        getMessages.start();
    }

    //初始化主窗口
    private void init(){
        this.setSize(400, 800);
        this.setTitle("testWindow");
        this.setLayout(new BorderLayout());
        flag = MESSAGES;

        messagesList = new JButton("消息列表");
        friendsList = new JButton("好友列表");
        mine = new JButton("个人信息");
        menuBar = new JPanel(new FlowLayout());

        menuBar.add(messagesList);
        menuBar.add(friendsList);
        menuBar.add(mine);

        messages = new BgPanelMessage();
        messages.setLayout(new FlowLayout());
        friends = new JPanel();
        friends.setLayout(new BorderLayout());
        myData = new JPanel();

        messages.add(new Message());
        messages.add(new Message());

        initFriendsWindow();
        friends.add(tempPanel, BorderLayout.NORTH);

        bgPanelFriend = new BgPanelFriend();
        friends.add(bgPanelFriend, BorderLayout.CENTER);

        JLabel testLabel = new JLabel(new ImageIcon("mypicture1.jpg"));
        this.add(testLabel, BorderLayout.CENTER);
        this.add(messages, BorderLayout.CENTER);
        this.add(menuBar, BorderLayout.NORTH);
    }

    //初始化好友列表
    private void initFriendsWindow(){
        tempPanel = new JPanel(new FlowLayout());
        searchFriend = new JLabel("搜索其它用户");
        searchField = new JTextField(20);
        searchButton = new JButton("点击搜素");

        tempPanel.add(searchFriend);
        tempPanel.add(searchField);
        tempPanel.add(searchButton);
    }

    //给所有按钮添加事件监听器
    private void addListener(){
        mainWindow = this;
        friendsList.addActionListener(new AbstractAction() {
            @Override
            public void actionPerformed(ActionEvent e) {
                if (flag != FRIENDS){
                    System.out.println("Friends");
                    JPanel panel;
                    panel = flag == MESSAGES ? messages : myData;
                    mainWindow.remove(panel);
                    mainWindow.add(friends, BorderLayout.CENTER);
                    mainWindow.getContentPane().validate();
                    mainWindow.repaint();
                    flag = FRIENDS;
                }
            }
        });

        messagesList.addActionListener(new AbstractAction() {
            @Override
            public void actionPerformed(ActionEvent e) {
                System.out.println("Messages");
                if (flag != MESSAGES){
                    JPanel panel;
                    panel = flag == FRIENDS ? friends : myData;
                    mainWindow.remove(panel);
                    mainWindow.add(messages, BorderLayout.CENTER);
                    mainWindow.repaint();
                    mainWindow.getContentPane().validate();
                    flag = MESSAGES;
                }
            }
        });

        searchButton.addActionListener(new AbstractAction() {
            @Override
            public void actionPerformed(ActionEvent e) {
                System.out.println("开始搜索该用户相关信息");
                client.getMessages.returnMessage = null;
                client.sendMessages("$" + searchField.getText());
                while(true) {
                    //System.out.println("循环中...");
                    if (client.getMessages.returnMessage != null){
                        String returnStr = client.getMessages.returnMessage;
                        String s = returnStr.substring(returnStr.indexOf(':') + 1);
                        System.out.println(s);
                        if (s.equals("查找用户不存在！")){
                            //弹窗进行提示
                            JOptionPane.showMessageDialog(mainWindow, s);
                        } else{
                            //打开用户信息展示界面
                            FriendDataWindow friendDataWindow = new FriendDataWindow(s);
                            friendDataWindow.setVisible(true);
                        }
                        System.out.println(returnStr);
                        break;
                    }
                }
            }
        });
    }

    private void addFriend(){

    }

    public static void main(String[] args) {
       // MainWindow mainWindow = new MainWindow();
    }

    //主窗口的内部类，用于展示用户信息
    class FriendDataWindow extends JDialog{
        String []str;
        JLabel returnLable;
        public FriendDataWindow(String FriendData){
            System.out.println(FriendData);
            str = FriendData.split("/");
            init(str);
            this.setResizable(false);
        }

        private void init(String []allData){
            this.setSize(400, 400);
            this.setLayout(null);
            Container component = this.getContentPane();
            JLabel name = new JLabel("姓名：" + allData[0]);
            JLabel sex = new JLabel("性别：" + allData[1]);
            JLabel age = new JLabel("年龄：" + allData[2]);
            JLabel account = new JLabel("账号：" + allData[3]);

            component.add(name);
            name.setBounds(100, 50, 180, 30);
            component.add(sex);
            sex.setBounds(100, 100, 180, 30);
            component.add(age);
            age.setBounds(100, 150, 180, 30);
            component.add(account);
            account.setBounds(100, 200, 180, 30);

            JButton addThis = new JButton("添加为好友");
            component.add(addThis);
            addThis.setBounds(120, 300, 150, 30);

            returnLable = new JLabel();
            component.add(returnLable);
            returnLable.setBounds(80, 350, 180, 30);

            addThis.addActionListener(new AbstractAction() {
                @Override
                public void actionPerformed(ActionEvent e) {
                    client.sendMessages("@" + str[3] + "/" + I.getAccount());
                    System.out.println("添加好友中");
                    client.getMessages.returnMessage = null;
                    while(true) {
                        if (client.getMessages.returnMessage != null){
                            String tempStr = client.getMessages.returnMessage;
                            System.out.println(tempStr);
                            if (tempStr.substring(tempStr.indexOf(':') + 1).equals("添加成功！")){
                                Friend newFriend = new Friend();
                                newFriend.setFriendData(str);
                                MainWindow.this.bgPanelFriend.setLayout(new FlowLayout());
                                MainWindow.this.bgPanelFriend.add(newFriend);
                                //添加好友聊天窗口
                                ChatWindow cw = new ChatWindow(client);
                                cw.setTitle(str[0]);
                                cw.setWindowNum(str[3], Integer.toString(I.getAccount()));
                                freinedChatWindows.put(str[3],cw);
                                mainWindow.repaint();
                                mainWindow.getContentPane().validate();
                                client.getMessages.returnMessage = null;
                                break;
                            }
                            returnLable.setText(tempStr);
                        }
                    }
                }
            });

            JLabel bgOfThis = new JLabel(new ImageIcon("sun.jpg"));
            this.add(bgOfThis);
            bgOfThis.setBounds(0, 0, 400, 380);
        }
    }

    //用于展示好友的相关信息
    class Friend extends JPanel{
        JLabel name;
        JButton sendMessages;
        JLabel account;
        JLabel otherData;
        public Friend(){
            this.setLayout(new BorderLayout());
        }

        public void setFriendData(String []datas){
            name = new JLabel(datas[0]);
            account = new JLabel(datas[3] + "                       ");
            otherData = new JLabel(datas[1] + "," + datas[2] + "                    ");
            sendMessages = new JButton("发消息");
            sendMessages.addActionListener(new AbstractAction() {
                @Override
                public void actionPerformed(ActionEvent e) {
                    ChatWindow chatWindow = freinedChatWindows.get(datas[3]);
                    if (chatWindow != null){
                        chatWindow.setVisible(true);
                    }
                }
            });

            this.add(name, BorderLayout.WEST);
            this.add(account, BorderLayout.NORTH);
            this.add(otherData, BorderLayout.CENTER);
            this.add(sendMessages, BorderLayout.EAST);
        }
    }
}

//用于展示所接收到消息的相关信息
class Message extends JPanel{
    JLabel numMessage;
    JLabel sender;
    JButton messageData;
    Message(){
        init();
    }

    private void init(){
        this.setLayout(new BorderLayout());
        numMessage = new JLabel("消息数");
        sender = new JLabel("消息来源");
        String space = "                                                            ";
        messageData = new JButton("消息内容" + space);

        this.add(numMessage, BorderLayout.EAST);
        this.add(sender, BorderLayout.NORTH);
        this.add(messageData, BorderLayout.CENTER);

        sender.setSize(240, 30);
        messageData.setSize(250, 50);
    }

    public void getAllMessageData(String mes){

    }
}

class BgPanelMessage extends JPanel{
    BgPanelMessage(){}
    protected void paintComponent(Graphics g){
        ImageIcon imageIcon = new ImageIcon("mypicture1.jpg");
        g.drawImage(imageIcon.getImage(), 0, 0, this.getWidth(), this.getHeight(), this);
    }
}

class BgPanelFriend extends JPanel{
    BgPanelFriend(){}
    protected void paintComponent(Graphics g){
        ImageIcon imageIcon = new ImageIcon("mypicture2.jpg");
        g.drawImage(imageIcon.getImage(), 0, 0, this.getWidth(), this.getHeight(), this);
    }
}

