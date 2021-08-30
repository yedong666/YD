
#include <iostream>
#include <cmath>
using namespace std;

class Time
{
    private:
    int hour;
    int min;
    int sec;

    public:
    Time();
    Time(int h, int m, int s);
    Time operator - (const Time time);
    Time operator + (const Time time);
    friend ostream & operator << (ostream & os,const Time time);
};
Time::Time()
{
    hour=0;
    min=0;
    sec=0;
}

Time::Time(int h, int m, int s)
{
    hour=h;
    min=m;
    sec=s;
}

Time Time::operator+(const Time time)
{
    Time xtime;
    int ssum, msum;
    ssum=sec+time.sec;
    msum=min+time.min+ssum/60;
    xtime.sec=ssum%60;
    xtime.min=msum%60;
    xtime.hour=hour+time.hour+msum/60;
    return xtime;
}

Time Time::operator-(const Time time)
{
    Time xtime;
    int sums1, sums2, sums3;
    sums1=hour*3600+min*60+sec;
    sums2=time.hour*3600+time.min*60+time.sec;
    sums3=fabs(sums1-sums2);
    xtime.hour=sums3/3600;
    xtime.min=(sums3%3600)/60;
    xtime,sec=sums3%60;
    return xtime;
}

ostream & operator<<(ostream & os, const Time time)
{
    os << time.hour << "h" << time.min << "m" << time.sec << "s" << endl;
    return os;
}

int main(void)
{
    Time time1(22,45,31);
    Time time2(21,58,34);
    Time time3;
    time3=time1+time2;
    cout << time3;
    cin.get();
    return 0;
}