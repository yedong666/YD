#include <iostream>
#include <string>
#include <cmath>
#include <climits>
#include <vector>
#include <array>

using namespace std;

float Fahrenheit(float Celsius);

int main(void)
{
    /*double lf_number;

    lf_number=9.0;

    lf_number=sqrt(lf_number);

    cout << lf_number << endl;*/

    /*float f_cdegree, f_fdegree;

    cout << "please input a Celsius value:"<< endl;

    cin >> f_cdegree;

    f_fdegree = Fahrenheit(f_cdegree);

    cout << f_cdegree << " degrees Celsius is " << f_fdegree <<"degrees Fahreheit."<<endl;*/

    /*int n_int = INT_MAX;
    short n_short = SHRT_MAX;
    long n_long = LONG_MAX;
    long long n_llong = LLONG_MAX;

    cout << n_int << endl;
    cout << n_short << endl;
    cout << n_long << endl;
    cout << n_llong << endl;*/
    
   /* int a;
    int &elsea = a;

    a=10;

    cout << a <<endl;
    cout << elsea <<endl;*/

    int n;

    cout << "Please input the number of numbers that you want to enter " << endl;

    cin >> n;

    vector<int> vi(n);

    cout << "Please enter "<< n << " number:";

    for(int i=0;i<n;i++)
    {
        cin >> vi[i];
    }

    for(int i=0;i<n;i++)
    {
        cout << vi[i] << endl;
    }

    return 0;
}

/*float Fahrenheit(float Celsius)
{
    return 1.8*Celsius+32.0;
}*/