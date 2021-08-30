#include <stdio.h>
int Fibonacci(int n);
int main(void)
{
    int n=5, i;
    Fibonacci(n);
    return 0;
}
int Fibonacci(int n)
{
    int fib;
   if(n==1||n==2)
   {
       fib = 1;
       return fib;
   }
   else
   {
       fib = Fibonacci(n-2) + Fibonacci(n-1);
   }
   printf("Fib(%d)=%d\n", n, fib);
}