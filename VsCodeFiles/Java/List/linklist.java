package List;

import java.util.Scanner;

public class linklist {
    public class Node{
        int date;
        Node pnext;
        Node() {};
    };
    Node Head;
public boolean Createlist(){
        Scanner scan = new Scanner(System.in);
        Node p1 = new Node();
        p1.pnext = null;
        Head = p1;
        while(true){
            System.out.println("请输入数据：");
            int nodedate = scan.nextInt();
            if (nodedate == -1){
                break;
            }
            Node p2 = new Node();
            p2.date = nodedate;
            p2.pnext = null;
            p1.pnext = p2;
            p1 = p2;
        }
        scan.close();
        System.out.println("创建链表成功！");
        return true;
    }

public void Travellist(){
        Node p;
        p = Head.pnext;
        while(p!=null){
            System.out.println(p.date);
            p = p.pnext;
        }
        return;
    }
}
