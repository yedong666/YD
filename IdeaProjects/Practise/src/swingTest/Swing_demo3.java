package swingTest;

import javax.swing.*;
import java.awt.*;

public class Swing_demo3 {
    public static void main(String[] args){
        testwin testWindow = new testwin("testWindow");
    }
}

class testwin extends JFrame{
    public testwin(String name){
        super(name);
        super.setSize(500, 500);
        setLayout(new BorderLayout());
        setLocationRelativeTo(null);
        setDefaultCloseOperation(WindowConstants.EXIT_ON_CLOSE);

        JPanel testPanel = new JPanel();
        JButton testButton1 = new JButton("test1");
        JButton testButton2 = new JButton("test2");
        JButton testButton3 = new JButton("test3");
        testPanel.add(testButton1, "100px");
        testPanel.add(testButton2, "200px");
        testPanel.add(testButton3, "1w");

        this.add(testPanel, BorderLayout.CENTER);
        super.setVisible(true);
    }
}
