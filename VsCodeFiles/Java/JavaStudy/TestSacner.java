package JavaStudy;
import java.util.Scanner;
public class TestSacner {
    public static void main(String[] args){
        Scanner scan = new Scanner(System.in);
        int testnumber;
        String teststring;
        char testch;
        testnumber = scan.nextInt();
        teststring = scan.next();
        testch = scan.next().charAt(3);
        System.out.println(testnumber);
        System.out.println(teststring);
        System.out.println(testch);
        scan.close();
    }
}
