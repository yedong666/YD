package File;

import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;

public class TestFile {
    public static void main(String[] args) throws IOException {
        File testFile = new File("testFile.txt");
        FileWriter fileWriter = new FileWriter(testFile);
//        Scanner scanner = new Scanner(System.in);
//        int a;
//        a = scanner.nextInt();
//        if (a  == 1)
//        fileWriter.flush();
        fileWriter.write("whai");
        fileWriter.write("hello");
        fileWriter.close();
//        testFile.delete();
        System.out.println("文件已删除");
    }
}
