//运算符重载练习(复数的简单计算)
#include <iostream>
using namespace std;

class Imaginary_number
{
    private:
    double real;
    double imagin;
    public:
    Imaginary_number()
    {
        real=0;
        imagin=1.0;
    }
    Imaginary_number(double realpart, double imaginpart)
    {
        real=realpart;
        imagin=imaginpart;
    }
    friend ostream & operator << (ostream & cut, const Imaginary_number i);
    friend Imaginary_number operator * (const Imaginary_number i1, double x);
    friend Imaginary_number operator * ( double x, const Imaginary_number i1);
    friend Imaginary_number operator / (const Imaginary_number i1, double x);
    friend Imaginary_number operator / ( double x, const Imaginary_number i1);
    Imaginary_number operator + (const Imaginary_number i);
    Imaginary_number operator - (const Imaginary_number i);
    Imaginary_number operator * (const Imaginary_number i);
    Imaginary_number operator / (const Imaginary_number i);
};

ostream & operator << (ostream &cut, const Imaginary_number i) 
{
    if(i.imagin==0)
    {
        cut << i.real;
        return cut;
    }
    else
    {
        cut << "("<< i.real << "," << i.imagin << "i" << ")";
        return cut;
    }
    
}

Imaginary_number operator *(const Imaginary_number i1, double x)
{
    Imaginary_number i;
    i.real=x*i1.real;
    i.imagin=x*i1.imagin;
    return i;
}

Imaginary_number operator * (double x, const Imaginary_number i1)
{
    Imaginary_number i;
    i.real=x*i1.real;
    i.imagin=x*i1.imagin;
    return i;
}

Imaginary_number Imaginary_number::operator + (const Imaginary_number i)
{
    Imaginary_number x;
    x.real=real+i.real;
    x.imagin=imagin+i.imagin;
    return x;
}

Imaginary_number Imaginary_number::operator - (const Imaginary_number i)
{
    Imaginary_number x;
    x.real=real-i.real;
    x.imagin=imagin-i.imagin;
    return x;
}

Imaginary_number Imaginary_number::operator * (const Imaginary_number i)
{
    Imaginary_number x;
    x.real=(real*i.real)+(imagin*i.imagin*(-1.0));
    x.imagin=(real*i.imagin)+(imagin*i.real);
    return x;
}

Imaginary_number Imaginary_number::operator / (const Imaginary_number i)
{
    Imaginary_number x;
    x.real=(real*i.real+imagin*i.imagin)/(i.real*i.real+i.imagin*i.imagin);
    x.imagin=(imagin*i.real-real*i.imagin)/(i.real*i.real+i.imagin*i.imagin);
    return x;
}


int main(void)
{
    Imaginary_number i1(1,1);
    Imaginary_number i2(1,-1);
    
    cout << i1+i2 << endl;
    cout << i1*i2 << endl;
    cout << i1/i2 << endl;
    cout << i1-i2 << endl;
    cout << i1*5 << endl;
    cout << 5*i1 << endl; 
    
    return 0;
}
