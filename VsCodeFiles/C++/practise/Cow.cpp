//运算符重载与函数多态练习
#include <iostream>
#include <cstring>
using namespace std;

class cow
{
private:
    char name[20];
    char hobby[20];
    double weight;
public:
    cow();
    cow(const char *nam, const char *hob, double weg);
    cow(const cow & c);
    cow & operator=(const cow & c);                
    void showcow()const;
};
cow::cow()
{
    weight=0;
}
cow::cow(const char *nam, const char *hob, double weg)
{
    strcpy(name, nam);
    strcpy(hobby, hob);
    weight=weg;
}
cow::cow(const cow & c)
{
    strcpy(name, c.name);
    strcpy(hobby, c.hobby);
    weight=c.weight;
}
cow & cow::operator=(const cow & c)
{
    static cow cowx;
    strcpy(cowx.name,c.name);
    strcpy(cowx.hobby,c.hobby);
    cowx.weight=c.weight;
    return cowx;
}
void cow::showcow()const
{
    cout << "The cow is " << name << endl;
    cout << "The cow's hobby is " << hobby << endl;
    cout << "The cow's weight is " << weight << endl;
}

int main(void)
{
    char name1[20]="Jack",name2[20]="Tom";
    char hobby1[20]="basketball",hobby2[20]="football";
    cow cow1(name1,hobby1,342);
    cow cow2(name2,hobby2,235);
    cow cow3(cow1);
    cow cow4=cow2;
    cow1.showcow();
    cow2.showcow();
    cow3.showcow();
    cow4.showcow();
    return 0;
}