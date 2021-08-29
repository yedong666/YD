package work1;

public class three {
    int sumFactorial(int num){
        int sum = 0;
        for(int i = 1; i < num+1; i++){
            int temp = 1;
            int j = i;
            do{
                temp = temp * j;
                j--;
            }while(j > 1);
            sum += temp;
        }
        return sum;
    }
}
