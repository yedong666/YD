package ChatRoom;

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.net.Socket;
import java.util.Stack;

//聊天窗口
public class ChatWindow extends JFrame{
    //窗口最多显示100条历史消息
    final int MAX_MESSAGE_NUM = 100;
    final boolean ON = true;
    final boolean OFF = false;
    //窗口是否显示标志
    boolean isOpen;
    //本机socket
    Client myself;
    //此窗口的聊天对象的账号
    String num;
    //自身账号
    String myNum;
    //消息栈，包括接收的信息与发送的信息
    Stack<Note> notes;
    ChatWindow chatWindow = this;
    //界面布局控件
    BgPanelNotes notesPanel;
    JPanel input;
    JTextField inputField;
    JButton snedMessage;
    
    ChatWindow(Client socket){
        super();
        this.myself = socket;
        init();
        notes = new Stack<Note>();
        this.setVisible(false);
        addListener();
        this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        Thread thread = new Thread(new Runnable() {
            @Override
            public void run() {
                while(true){
                    if (!notes.isEmpty()){
                        notesPanel.add(notes.pop());
                        notesPanel.repaint();
                        chatWindow.getContentPane().validate();
                    }
                }
            }
        });
        thread.start();
    }

    ChatWindow(){
        super();
        init();
        addListener();
        this.setVisible(true);
        this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    }

    public void setWindowNum(String num, String myNum){
        this.num = num;
        this.myNum = myNum;
    }

    public void getMessage(String s){
        Note note = new Note(s+"                                                                      ");
        note.setForeground(Color.red);
        //note.setBorder(BorderFactory.createLineBorder(Color.red));
        //note.setOpaque(true);
        //note.setBackground(Color.red);
        notes.push(note);
    }
    
    private void init(){
        this.setSize(400, 600);
        this.setLayout(new BorderLayout());

        notesPanel = new BgPanelNotes();
        notesPanel.setLayout(new FlowLayout());
        inputField = new JTextField(30);
        input = new JPanel(new FlowLayout());
        snedMessage = new JButton("发送");

        input.add(inputField);
        input.add(snedMessage);

        this.add(notesPanel, BorderLayout.CENTER);
        this.add(input, BorderLayout.SOUTH);
    }

    private void addListener(){
        snedMessage.addActionListener(new AbstractAction() {
            @Override
            public void actionPerformed(ActionEvent e) {
                String str = inputField.getText();
                inputField.setText("");
                myself.sendMessages("*" + num + "|" + myNum + str);
                Note note = new Note("                                                                "+str);
                note.setForeground(Color.blue);
                //note.setBorder(BorderFactory.createLineBorder(Color.blue));
                //note.setOpaque(true);
                //note.setBackground(Color.blue);
                notesPanel.add(note);
                notesPanel.repaint();
                chatWindow.getContentPane().validate();
            }
        });
    }
}

//封装一条信息
class Note extends JLabel{
    final int TEXT = 1;
    final int PICTURE = 2;
    final int VOICE = 3;
    //种类
    int kind;
    //来源
    String source;
    //内容
    String content;
    
    Note(String message){
        this.setText(message);
    }
}

class BgPanelNotes extends JPanel{
    BgPanelNotes(){
    }

    protected void paintComponent(Graphics g){
        ImageIcon imageIcon = new ImageIcon("mypicture2.jpg");
        g.drawImage(imageIcon.getImage(), 0, 0, this.getWidth(), this.getHeight(), this);
    }
}
