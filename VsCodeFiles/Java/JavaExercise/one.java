/*Write a function that takes in a string of one or more words, 
and returns the same string, 
but with all five or more letter words reversed (like the name of this kata).

Strings passed in will consist of only letters and spaces.
Spaces will be included only when more than one word is present.
Examples:

spinWords("Hey fellow warriors") => "Hey wollef sroirraw" 
spinWords("This is a test") => "This is a test" 
spinWords("This is another test") => "This is rehtona test"*/
package JavaExercise;
public class one{
    public one() {};
    public static String Fun(String scentence){
        int k = 0;
        char[] str = scentence.toCharArray();
        char tempch = '0';
        for(int i = 0; i < scentence.length(); i++){
            if (str[i] == ' '){
                if (k > 4){
                    for(int j = 0; j< k/2 ; j++){
                        tempch = str[i-k+j];
                        str[i-k+j] = str[i-1-j];
                        str[i-1-j] = tempch;
                    }
                }
                k = 0;
            }
            else{
                k++;
            }
        }
        String newstr = new String(str);
        System.out.println("?");
        return newstr;
    }
}
