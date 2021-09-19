#include <iostream>
#include <string>
using namespace std;

class Person
{
    public:
    Person()
    {
        cout << "默认构造函数调用" << endl;
    }

    Person(int age ,string name)
    {
        Age=age;
        Name=name;
        cout << "带参函数调用" << endl;
    }

    Person(const Person &person)
    {
        cout << "拷贝构造函数调用" << endl;
    }

    ~Person()
    {
        cout << "析构函数调用"  << endl;
    }

    private:
    int Age;
    string Name;
};
void test1()
{
    Person Jack;
}

void test2()
{
    Person Tom=Person(20,"Tom");
    Person Alis=Person(Tom);
}

int main(void)
{
    test1();

    test2();

    return 0;
}