#include <iostream>
using namespace std;
int Monkey(int x);
int main(void)
{
    cout << Monkey(1);
    return 0;
}
int Monkey(int x)
{
    if(x==10)
    {
        return 1;
    }
    else
    {
        return 2*(Monkey(x+1)+1);
    }  
}