package ChatRoom;

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.io.IOException;

/*
登录/注册界面
用于登录或注册账号
登入成功后此此窗口会被删除，进入主窗口
 */
public class LogInWindow extends JFrame{
    MainWindow mainWindow;
    JLabel background;
    JLabel account;
    JLabel password;
    JLabel returnlabel;
    JLabel tip;
    JTextField accountField;
    JPasswordField passwordFiled;
    JButton logIn;
    JButton reginster;
    User user;

    //初始化登录界面
    private void initWindow(){
        this.setLayout(null);
        this.setSize(400, 800);
        ImageIcon imageIcon = new ImageIcon("mypicture7.jpg");
        returnlabel = new JLabel();
        background = new JLabel(imageIcon);
        account = new JLabel("账号 :");
        password = new JLabel("密码 :");
        tip = new JLabel("还没有账号？ 赶快注册一个吧!");
        accountField = new JTextField(20);
        passwordFiled = new JPasswordField(20);
        logIn = new JButton("登录");
        reginster = new JButton("点击注册");

        this.add(account);
        account.setBounds(50, 100, 60, 30);

        this.add(password);
        password.setBounds(50, 150, 60, 30);

        this.add(accountField);
        accountField.setBounds(130, 100, 180, 30);

        this.add(passwordFiled);
        passwordFiled.setBounds(130, 150, 180, 30);

        this.add(logIn);
        logIn.setBounds(180, 230, 60, 30);

        tip.setForeground(Color.CYAN);
        this.add(tip);
        tip.setBounds(40, 600, 210, 30);

        this.add(reginster);
        reginster.setBounds(230, 600,120, 30);

        this.add(returnlabel);
        returnlabel.setForeground(Color.red);
        returnlabel.setBounds(40, 400, 180, 30);

        this.add(background);
        background.setBounds(0, 0, 400, 800);
    }

    //给所有按钮添加事件监听器
    private void addListener(){
        LogInWindow logInWindow = this;
        reginster.addActionListener(new AbstractAction() {
            @Override
            public void actionPerformed(ActionEvent e) {
                logInWindow.setVisible(false);
                ReginsterWindow reginsterWindow = new ReginsterWindow();
            }
        });

        logIn.addActionListener(new AbstractAction() {
            @Override
            public void actionPerformed(ActionEvent e) {
                String s;
                System.out.println("开始登录！");
                try {
                    Client tempClient = new Client("Client");
                    tempClient.sendMessages("&" + accountField.getText() + "/" + passwordFiled.getText());

                    while(true){
                        if (tempClient.getMessages.returnMessage != null){
                            s = tempClient.getMessages.returnMessage;
                            System.out.println(s);
                            String tempS = s.substring(s.indexOf(":") + 1);
                            System.out.println(tempS);
                            if (tempS.equals("登录成功!")){
                                mainWindow = new MainWindow(tempClient, user);
                            }else{
                                System.out.println("error");
                                returnlabel.setText(tempS);
                            }
                            tempClient.getMessages.returnMessage = null;
                            logInWindow.setVisible(false);
                            break;
                        }
                    }

                } catch (IOException ioException) {
                    ioException.printStackTrace();
                }

            }
        });
    }

    public LogInWindow(){
        super();
        this.setLocation(550, 0);
        this.setTitle("YY聊天");
        initWindow();
        addListener();
        this.setVisible(true);
        this.setResizable(false);
    }

    //注册界面
    class ReginsterWindow extends JFrame{
        JLabel name;
        JLabel sex;
        JLabel age;
        JLabel newPassWord;
        JLabel affirmPassWord;
        JLabel returnLabel;
        JLabel bg;
        JTextField nameField;
        JTextField sexField;
        JTextField ageField;
        JPasswordField newPassWordField;
        JPasswordField affirmPassWordField;
        JButton reginster;
        JButton returnButton;

        //初始化注册界面
        private void init(){
            this.setSize(400, 800);
            this.setLayout(null);
            name = new JLabel("昵称");
            sex = new JLabel("性别");
            age = new JLabel("年龄");
            returnLabel = new JLabel();
            newPassWord = new JLabel("密码");
            affirmPassWord = new JLabel("确认密码");
            bg = new JLabel(new ImageIcon("mypicture9.jpg"));
            nameField = new JTextField(20);
            sexField = new JTextField(20);
            ageField = new JTextField(20);
            newPassWordField = new JPasswordField(20);
            affirmPassWordField = new JPasswordField(20);
            reginster = new JButton("注册");
            returnButton = new JButton("返回登录界面");

            this.add(name);
            name.setBounds(50, 100, 60, 30);

            this.add(sex);
            sex.setBounds(50, 150, 60, 30);

            this.add(age);
            age.setBounds(50, 200, 60, 30);

            this.add(newPassWord);
            newPassWord.setBounds(50, 250, 60, 30);

            this.add(affirmPassWord);
            affirmPassWord.setBounds(50, 300, 120, 30);

            this.add(nameField);
            nameField.setBounds(130, 100, 180, 30);

            this.add(sexField);
            sexField.setBounds(130, 150, 180, 30);

            this.add(ageField);
            ageField.setBounds(130, 200, 180, 30);

            this.add(newPassWordField);
            newPassWordField.setBounds(130, 250, 180, 30);

            this.add(affirmPassWordField);
            affirmPassWordField.setBounds(130, 300, 180, 30);

            this.add(reginster);
            reginster.setBounds(180, 350, 60, 30);

            this.add(returnButton);
            returnButton.setBounds(150, 400, 120, 30);

            this.add(returnLabel);
            returnLabel.setBounds(120, 700, 180, 30);

            this.add(bg);
            bg.setBounds(0, 0, 400, 800);
        }

        //通过一个临时客户端连接服务器，发送注册请求
        private void addRginsterThing() throws IOException {
            System.out.println("Hello");
            Client tempClient = new Client("client");
            String nameData = nameField.getText();
            String ageData = ageField.getText();
            String sexData = sexField.getText();
            String passwordData = newPassWordField.getText();
            System.out.println(passwordData);
            tempClient.sendMessages("#" + nameData + "/" + ageData + "/" +sexData + "/" + passwordData);
            user = new User();
            user.setSex(sexData);
            user.setAge(ageData);
            user.setName(nameData);
            user.setPassword(passwordData);
            //返回注册结果
            returnLabel.setForeground(Color.CYAN);
            returnLabel.setText("注册中.....");
            while(true) {
               if (tempClient.getMessages.returnMessage != null){
                   String returnStr = tempClient.getMessages.returnMessage;
                   returnLabel.setText(returnStr.substring(returnStr.indexOf(":")+1));
                   user.setAccount(Integer.parseInt(returnStr.substring(returnStr.length()-4)));
                   System.out.println(returnStr);
                   break;
               }
            }
        }

        private void addListenerR(){
            ReginsterWindow reginsterWindow = this;
            LogInWindow l = LogInWindow.this;
            returnButton.addActionListener(new AbstractAction() {
                @Override
                public void actionPerformed(ActionEvent e) {
                    reginsterWindow.dispose();
                    l.setVisible(true);

                }
            });

            reginster.addActionListener(new AbstractAction() {
                @Override
                public void actionPerformed(ActionEvent e) {
                    try {
                        addRginsterThing();
                    } catch (IOException ioException) {
                        System.out.println("异常");
                        ioException.printStackTrace();
                    }
                }
            });
        }

        ReginsterWindow(){
            super();
            this.setLocation(550, 0);
            init();
            addListenerR();
            this.setVisible(true);
            this.setResizable(false);
        }
    }
}

