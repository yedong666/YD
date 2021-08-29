package work2;

import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
import java.awt.geom.Ellipse2D;
import java.awt.geom.Rectangle2D;
import java.util.Date;
import java.util.Timer;
import java.util.TimerTask;

public class Paint{
    public static void main(String[] args){
        TestWindow testWindow = new TestWindow();
        testWindow.addMouseListener(new Draw());
        testWindow.addWindowListener(new WindowAdapter() {
            //添加窗口事件，关闭窗口则结束程序
            @Override
            public void windowClosing(WindowEvent e) {
                super.windowClosing(e);
                System.exit(-1);
            }
        });
        testWindow.setName("testWindow");
        testWindow.setSize(400, 200);
        testWindow.setVisible(true);
    }
}

class TestWindow extends JFrame{
    int x, y;
    int flag;

    public void paint(Graphics g){
        //创建画笔
        Graphics2D graphics2D = (Graphics2D) g;
        if (flag == 1){
            //左键画一个绿色的圆
            Ellipse2D ellipse2D = new Ellipse2D.Double(x, y, 30, 30);
            graphics2D.setColor(Color.green);
            graphics2D.fill(ellipse2D);
        } else if (flag == 2){
            //右键画一个红色边框的矩形
            Rectangle2D rectangle2D = new Rectangle2D.Double(x, y, 30, 30);
            graphics2D.setColor(Color.red);
            graphics2D.draw(rectangle2D);
        } else {
            //双击左键清空屏幕
            graphics2D.setColor(Color.WHITE);
            graphics2D.clearRect(0, 0, this.getWidth(), this.getHeight());
        }
    }
}


//重写鼠标事件监听器
class Draw extends MouseAdapter {
    //是否执行双击事件的标志
    boolean runFlag = false;
    static TestWindow t;
    @Override
    public void mouseClicked(MouseEvent e) {
        super.mouseClicked(e);
        //获取事件来源窗口
        t = (TestWindow)e.getSource();
        t.x = e.getX();
        t.y = e.getY();

        if (e.getButton() == MouseEvent.BUTTON3){
            //点击右键
            t.flag = 2;
            t.repaint();
        } else{
            //点击左键
            if(e.getClickCount() == 2){
                //若在150ms内检测到有两次鼠标左键点击
                t.flag = 3;
                t.repaint();
                runFlag = true;
            }
            else{
                /*
                //第一次点击左键，设置计时器
                Timer timer = new Timer();
                timer.schedule(new TimerTask() {
                    int num = 0;
                    @Override
                    public void run() {
                        if (runFlag){
                            //若runFlag为true，则说明已监听到第二次鼠标左击，结束此次监听
                            runFlag = false;
                            this.cancel();
                            return;
                        }
                        if (num == 1){
                            //num等于1说明此函数已执行2次,且仍未监听到第二次鼠标左击
                            //则视为单击一次鼠标
                            //执行绘图窗口的左击事件
                            t.flag = num;
                            t.repaint();
                            //重置num
                            num = 0;
                            //结束此次监听
                            this.cancel();
                            return;
                        }
                        num++;
                    }
                }, new Date(), 150); */
                t.flag = 1;
                t.repaint();

            }
        }

    }


}

