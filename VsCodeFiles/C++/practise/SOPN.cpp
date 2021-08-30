//筛选法查找素数
#include <iostream>
#include <vector>
using namespace std;

int k=0;

void Primer_number(int *p, int n);
void Show_array(int *p, int n);

int main(void)
{ 
    int n=1000, p[1000];
    Primer_number(p, n);
    Show_array(p, k);
    return 0;
}

void Primer_number(int *p, int n)
{
    vector<int> vi(n+1);
    vi[0]=0;
    vi[1]=0;

    for(int i=2;i<n+1;i++)
    {
        vi[i]=1;
    }

    for(int i=2;i<n+1;i++)
    {
        for(int j=2;i*j<n+1;j++)
        {
            if(vi[i*j]==1)
            {
                vi[i*j]=0;
            }
        }

        if(vi[i]==1)
        {
            p[k]=i;
            k++;
        }
    }

}

void Show_array(int *p, int n)
{
    for(int i=0;i<n;i++)
    {
        cout << p[i] << " ";
    }
}