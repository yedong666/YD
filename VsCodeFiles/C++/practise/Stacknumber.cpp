//基于数组的顺序栈
#include <iostream>
#define MAX 20
using namespace std;

typedef int datetype;

class stack
{
private:
    datetype stackdate[MAX];
    int stacktop;
public:
    stack();
    bool pushstack(datetype datex);//进栈
    bool popstack(int &x);         //出栈
    bool emptystack();             
    bool fullstack();
};
stack::stack()
{
    stacktop=-1;
}
bool stack::pushstack(datetype datex)
{
    stackdate[stacktop+1]=datex;
    stacktop++;
    return true;
}
bool stack::popstack(int &x)
{
    x=stackdate[stacktop];
    stacktop--;
    return true;
}
bool stack::emptystack()
{
    if(stacktop==-1)
    {
        return true;
    }
    return false;
}
bool stack::fullstack()
{
    if(stacktop==MAX)
    {
        return true;
    }
    return false;
}

int main(void)
{
    stack stackx;
    int n, x1, x2;
    cin >> n;
    for(int i=0;i<n;i++)
    {
        cin >> x1;
        stackx.pushstack(x1);
    }
    for(int i=0;i<n;i++)
    {
        stackx.popstack(x2);
        cout << x2 << endl;
    }
    return 0;
}