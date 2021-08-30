#include <iostream>
using namespace std;

int main(void)
{
    int *pn;
    pn = new int [10];//new使用格式
    cout << "Please enter 10 number:" << endl;
    for(int i=0;i<10;i++)
    {
        cin >> pn[i];
    }
    for(int i=0;i<10;i++)
    {
        cout << pn[i] <<" " << endl;
    }
    delete [] pn;
    return 0;
}