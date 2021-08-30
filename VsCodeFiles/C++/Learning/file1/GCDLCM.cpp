#include <iostream>
using namespace std;

int gcd(int x, int y);
int lcm(int x, int y);

int main(void)
{
    int a, b;

    cin >> a >> b;

    cout << lcm(a, b);

    return 0;
}

int gcd(int x, int y)
{
    int z, t;

    while(1){

    if(y%x==0)
    {
        return x;
    }

    else
    {
        z=x;
        t=y;
        y=z;
        x=t%z;
    }

    }
    
}

int lcm(int x, int y)
{
    return (x*y)/gcd(x, y);
}