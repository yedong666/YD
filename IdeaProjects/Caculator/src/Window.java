import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class Window extends JFrame {
    Caculator caculator = new Caculator();
    JPanel pIoBoard = new JPanel(new GridLayout(2, 1));
    JPanel pKeyBoard1 = new JPanel(new GridLayout(3, 4));
    JPanel pKeyBoard2 = new JPanel(new GridLayout(3, 4));
    StringBuilder build = new StringBuilder();
    String[] str = {"AC", "(", ")", "=", "^", "sqrt:", "%", "!", "1", "2", "3", "+", "4", "5", "6", "-",
                    "7", "8", "9", "*", "Backspace", "0", ".", "/"};
    JButton[] btn = new JButton[str.length];
    public JLabel input = new JLabel();
    public JLabel out = new JLabel();

    //事件监视器
    class Button1handler implements ActionListener {
        String txt;
        public Button1handler(String name){
            txt = name;
        }
        public void actionPerformed(ActionEvent e)
        {
            switch (txt) {
                case "=" -> {
                    caculator.Dispose_str(build.toString());
                    out.setText("=" + caculator.Calcuate());
                }
                case "Backspace" -> build.deleteCharAt(build.length() - 1);
                case "AC" -> {
                    build.delete(0, build.length());
                    out.setText(null);
                }
                default -> {
                    if (build.length() < 58) {
                        build.append(txt);
                    }
                }
            }
            input.setText(build.toString());
        }
    }
    //设置键盘面板
    public void SetKeyBoard(){
        for(int i = 0; i<str.length; i++){
            btn[i] = new JButton(str[i]);
            btn[i].setName(str[i]);
            btn[i].addActionListener(new Button1handler(btn[i].getName()));
            if (i<12) {
                pKeyBoard1.add(btn[i]);
            }
            else{
                pKeyBoard2.add(btn[i]);
            }
        }
    }
    //设置输入输出面板
    public void SetIoBoard(){
        input.setFont(new Font(null, Font.PLAIN, 20));
        out.setFont(new Font(null, Font.PLAIN, 20));
        pIoBoard.setLayout(new GridLayout(2,1,10, 10));
        pIoBoard.setBackground(Color.WHITE);
        pIoBoard.add(input);
        pIoBoard.add(out);
    }
    //设置主窗口
    public Window(String name){
        super(name);
        super.setSize(500, 500);
        setLayout(new GridLayout(3,1 ,3,3));
        SetKeyBoard();
        SetIoBoard();
        getContentPane().add(pIoBoard);
        getContentPane().add(pKeyBoard1);
        getContentPane().add(pKeyBoard2);
        super.setVisible(true);

    }

}
