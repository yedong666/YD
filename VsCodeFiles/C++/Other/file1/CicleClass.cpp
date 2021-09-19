#include <iostream>

using namespace std;

const double PI=3.14159;

class Cicle
{
    public:

    int m_r;

    double C_of_cicle()
    {
        return 2.0*PI*m_r;
    }

    double S_of_cicle()
    {
        return m_r*m_r*PI;
    }
};

int main(void)
{
    Cicle c1;

    c1.m_r=3;

    cout << "The area of c1 is " << c1.S_of_cicle() << endl;

    cout << "The perimeter of c1 is " << c1.C_of_cicle() << endl;

    return 0;
}