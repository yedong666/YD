#include <iostream>
#include <string>
using namespace std;

class Student
{
    public:
    int mn_number;
    string ms_name;

    private:
    float mf_score;

    protected:
    int mn_sortnumber;

    public:
    void Setscore()
    {
        cin >> mf_score;
        cout << mf_score << endl;
    }

    void Setsort()
    {
        cin >> mn_sortnumber;
        cout << mn_sortnumber << endl;
    }



};

int main(void)
{
    Student stu_a;

    stu_a.mn_number=1;
    stu_a.ms_name="jack";

    cout << stu_a.mn_number << endl;
    cout << stu_a.ms_name << endl;
    stu_a.Setscore();
    stu_a.Setsort();
    
    return 0;
}
