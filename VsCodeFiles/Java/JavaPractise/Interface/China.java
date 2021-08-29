package JavaPractise.Interface;

public class China implements Computable{
   int number;
   public int f(int x){
       int sum = 0;
       for(int i=1; i<=x; i++){
           sum += i;
       }
       return sum;
   }
}
