#include <iostream>
using namespace std;

class Clock
{
    public:
    Clock(int a=0, int b=0, int c=0)
    {
        m_hour=a;
        m_min=b;
        m_sen=c;
    }

    private:
    int m_hour;
    int m_min;
    int m_sen;

    public:
    void Showtime(void)
    {
        cout << m_hour << ":" << m_min << ":" << m_sen << endl;
    }
};

int main(void)
{
    Clock time1(7,9,9);
    time1.Showtime();
    return 0;
}