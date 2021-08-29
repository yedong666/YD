package swingTest;

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class Swing_demo2 {
    public static void main(String[] args){
        myWindow w1 = new myWindow("计算器");
    }
}

class myWindow extends JFrame{
    JPanel jp1 = new JPanel(new GridLayout(3,4,3,3));
    JPanel jp2 = new JPanel(new GridLayout(3,4,3,3));
    JPanel jpx = new JPanel(new GridLayout(1,1,3,3));
    JLabel txtArea1 = new JLabel();
    JLabel label = new JLabel();
    static StringBuilder build = new StringBuilder();

    String[] str = {"AC", "(", ")", "=", "^", "sqrt:", "%", "!", "1", "2", "3", "+", "4", "5", "6", "-",
                    "7", "8", "9", "*", "Backspace", "0", ".", "/"};

    public myWindow(String s){
        super(s);
        super.setSize(500, 500);
        setLayout(new GridLayout(3,1 ,3,3));

        JButton btn[];
        btn  = new JButton[str.length];

        class Button1handler implements ActionListener
        {
            String txt;
            public Button1handler(String name){
                txt = name;
            }

            public void actionPerformed(ActionEvent e)
            {
                if (txt == "="){
                    label.setText("=");
                    return;
                }
                if (txt == "Backspace"){
                    build.deleteCharAt(build.length()-1);
                }
                else if(build.length()>58){
                    ;
                }
                else {
                    build.append(txt);
                }
                txtArea1.setText(build.toString());
            }
        }

        for(int i = 0; i<str.length; i++){
            btn[i] = new JButton(str[i]);
            btn[i].setName(str[i]);
            btn[i].addActionListener(new Button1handler(btn[i].getName()));
            if(i<12){
                jp1.add(btn[i]);
            }
            else{
                jp2.add(btn[i]);
            }
        }
        txtArea1.setFont(new Font(null, Font.PLAIN, 20));
        label.setFont(new Font(null, Font.PLAIN, 20));
        jpx.setLayout(new GridLayout(2,1,10, 10));
        jpx.setBackground(Color.WHITE);

//        JButton testButton1 = new JButton("Test1");
//        JButton testButton2 = new JButton("Test2");
//        jpx.add(testButton1, "80px");
//        jpx.add(testButton2, "80px");

        jpx.add(txtArea1);
        jpx.add(label);
        getContentPane().add(jpx);
        getContentPane().add(jp1);
        getContentPane().add(jp2);
        super.setVisible(true);
    }
}
