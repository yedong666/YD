package work1;

public class work1 {
    final double PI = 3.1415926;

    double turnDegreeType(double CDegree){
        return (9.f / 5.f) * CDegree + 32.f;
    }

    double GetVSphere(double r){
        return (4.f / 3.f) * PI * r * r *r;
    }

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

    public static void main(String[] args){
        work1 test =  new work1();
        int sum = test.sumFactorial(4);
        System.out.println(sum);
    }

}
