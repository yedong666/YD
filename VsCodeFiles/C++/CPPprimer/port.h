#include <iostream>
using namespace std;
//此类用于模拟一箱酒
class Port{
private:
    char * brand;   //品牌
    char style[20]; //风格
    int bottles;    //瓶数
public:
    Port(const char * br = "none", const char * st = "none", int b = 0);
    Port(const Port & p);
    virtual ~Port() {delete [] brand; }
    Port & operator=(const Port & p);
    Port & operator+=(int b);
    Port & operator-=(int b);
    int BottleCount() const { return bottles;}
    virtual void Show() const;
    friend ostream & operator<< (ostream & os, const Port & p);
};
class VintagePort : public Port{
private: 
    char * nickname;
    int year;
public:
    VintagePort() {};
    VintagePort(const char * br, int b, const char * nn, int y);
    VintagePort(const VintagePort & vp);
    ~VintagePort() {delete [] nickname;}
    VintagePort & operator=(const VintagePort & vp);
    void Show() const;
    friend ostream & operator<<(ostream & os, const VintagePort & vp);
};