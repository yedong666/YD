package swingTest;

import javax.swing.*;
import javax.swing.plaf.basic.BasicArrowButton;
import java.awt.*;

public class Swing_demo1 {
    public static void main(String[] args){
        JFrame testWindow = new JFrame("测试窗口");
        testWindow.setSize(250, 250);
        testWindow.setLocationRelativeTo(null);
        testWindow.setDefaultCloseOperation(WindowConstants.EXIT_ON_CLOSE);

        FlowLayout fl = new FlowLayout();
        testWindow.setLayout(fl);

        GridLayout gl =  new GridLayout(5, 4);
        testWindow.setLayout(gl);

        JPanel testPanel = new JPanel();
        JPanel testPanel1 = new JPanel();
        testPanel.setLayout(fl);
        testPanel1.setLayout(gl);

        for(int i = 0; i < 20; i++){
            JButton jb = new JButton();
            testPanel1.add(jb);
        }

        for(int i = 0; i < 4; i++){
            JButton jb = new JButton();
            testPanel.add(jb);
        }

        testWindow.add(testPanel);
        testWindow.add(testPanel1);

        testWindow.setVisible(true);


    }
}
