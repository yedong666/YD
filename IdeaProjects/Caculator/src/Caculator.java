import java.util.EmptyStackException;
import java.util.Stack;

public class Caculator {
    final int MAXLEN = 60;
    //表达式最大长度
    Stack<String> char_stack = new Stack<>();
    //运算符栈
    Stack<String> num_stack = new Stack<>();
    //运算数栈
    String[] leagle_str = new String[MAXLEN];
    //这里用字符串数组来储存表达式是因为有些运算符是由多个字符组成，并且小数中含有'.',若用字符串来保存表达式，将很难处理
    int length;
    //表达式长度

    boolean Dispose_str(String str) {
        //解析输入表达式
        System.out.println(str);
        int j = 1, i = 0;

        leagle_str[0] = "#";        //加入分界符

        while (i < str.length() && j<58) {
            if (str.charAt(i) == 's'){
                leagle_str[j++] = "sqrt:";
                i += 3;
                continue;
            }
            if (str.charAt(i) <= '9' && str.charAt(i) >= '0'){
                int k = i;
                StringBuilder build = new StringBuilder();
                while( (str.charAt(k) <= '9' && str.charAt(k) >= '0') || str.charAt(k) == '.'){
                    build.append(str.charAt(k));
                    k++;
                    if (k >= str.length()){
                        break;
                    }
                }
                leagle_str[j++] = build.toString();
                i = k;
            }
            else {
                leagle_str[j++] = str.charAt(i) + "";
                i++;
            }
        }   //转化
        leagle_str[j] = "#";        //加入分界符

        length = j+1;               //获取字符串数组长度
        return true;
    }
    //从输入面板获取表达式，并将其转化

    String Calcuate(){
        String error = new String("输入表达式错误！");
        String out;
        int i = 1;
        char_stack.push(leagle_str[0]);     //将分界符'#'压入运算符栈

        try {
            while(i < length){
                if ((leagle_str[i].charAt(0) <= '9' && leagle_str[i].charAt(0) >= '0') || leagle_str[i].charAt(0) == '.'){
                    num_stack.push(leagle_str[i++]);
                }

                if (leagle_str[i].equals("(")){
                    System.out.println("(入栈");
                    char_stack.push(leagle_str[i++]);
                }
                else if (char_stack.peek().equals("(") && leagle_str[i].equals(")")){
                    char_stack.pop();
                    System.out.println("()出栈");
                    i++;
                }
                else if (char_stack.peek().equals("(")){
                    System.out.println(leagle_str[i] + "入栈");
                    char_stack.push(leagle_str[i++]);
                }
                else{
                    String tempstr = char_stack.peek();
                    CLchar temp1 = new CLchar(tempstr);
                    CLchar temp2 = new CLchar(leagle_str[i]);
                    System.out.println(temp1.number+" "+temp2.number+" " + char_stack.peek() + " " + leagle_str[i]);
                    if (temp1.number >= temp2.number ){
                        switch (char_stack.peek()) {
                            case "+" -> {
                                double a = Exptact_num(num_stack.pop());
                                double b = Exptact_num(num_stack.pop());
                                num_stack.push(Exptact_str(a+b));
                                System.out.println(a + "+" + b + "=" + a+b);
                                char_stack.pop();
                            }
                            case "-" -> {
                                double a = Exptact_num(num_stack.pop());
                                double b = Exptact_num(num_stack.pop());
                                num_stack.push(Exptact_str(b - a));
                                System.out.println(b + "-" + a + "=" + (b-a));
                                char_stack.pop();
                            }
                            case "*" -> {
                                double a = Exptact_num(num_stack.pop());
                                double b = Exptact_num(num_stack.pop());
                                num_stack.push(Exptact_str(a*b));
                                System.out.println(a + "*" + b + "=" + (a*b));
                                char_stack.pop();
                            }
                            case "/" -> {
                                double a = Exptact_num(num_stack.pop());
                                double b = Exptact_num(num_stack.pop());
                                num_stack.push(Exptact_str(b/a));
                                System.out.println(b + "/" + a + "=" + (b/a));
                                char_stack.pop();
                            }
                            case "#" -> {
                                if (leagle_str[i].equals("#")) {
                                    char_stack.pop();
                                    i++;
                                }
                                break;
                            }
                        }
                    }
                    else {
                        System.out.println(leagle_str[i] + "入栈");
                        char_stack.push(leagle_str[i++]);
                        System.out.println(leagle_str[i]);
                    }
                }
                if (i>length){
                    break;
                }
            }
        }catch (EmptyStackException e){
            return error;
        }
        //对经过转化后的表达式进行相关运算处理
        if (num_stack.isEmpty()){
            return "输入错误！";
        }
        else{
            return out = num_stack.pop();
        }

        }

        //将字符串转化为对应浮点数
        double Exptact_num(String str){
            int i = 0, j = str.length()-1;
            double INT = 0, DOU = 0;
            boolean flag = true;
            while(i < str.length()){
                if (str.charAt(i) == '.'){
                    flag = false;
                    break;
                }
                INT = INT * 10 +(double)(str.charAt(i)-'0');
                i++;
            }
            //得出字符串整数部分代表的浮点数
            while(j>i && !flag){
                DOU = (DOU + (double)(str.charAt(j)-'0'))/10.0;
                j--;
            }
            //得到字符串小数部分代表的数
            System.out.println(str+ "对应的浮点数为" + (INT+DOU));
            return INT+DOU;
        }

        //将浮点数转化为字符串
        String Exptact_str(double num){
            String str;
            str = Double.toString(num);
            System.out.println(num + "对应的字符串为" + str);
            return str;
        }

}
