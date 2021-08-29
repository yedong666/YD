package Exercise;

public class SpainString {
    public static String spainString(String sentence){
        char[] str = sentence.toCharArray();
        int charNum = 0;

        int i = 0;
        while(i < str.length) {
            if (str[i] == ' '){
                if (charNum >= 5){
                    int head = i - charNum;
                    int trail = i - 1;

                    while(head <= trail){
                        char tempch = str[head];
                        str[head] = str[trail];
                        str[trail] = tempch;
                        head++;
                        trail--;
                    }
                }
                charNum = 0;
            }
            else{
                charNum++;
            }

            i++;
        }

        if (charNum > 4){
            int head = i - charNum;
            int trail = i - 1;

            while(head <= trail){
                char tempch = str[head];
                str[head] = str[trail];
                str[trail] = tempch;
                head++;
                trail--;
            }
        }

        String s = new String(str);

        return s;
    }

    public static void main(String[] args) {
        String testStr = "hajdk";
        System.out.println(SpainString.spainString(testStr));
    }
}
