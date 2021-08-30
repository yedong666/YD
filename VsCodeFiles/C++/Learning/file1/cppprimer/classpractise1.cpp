//此程序仍存在问题，不可运行，有待完善
#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

class Bank_account              //银行账户类
{
    private:
    string m_name;              //姓名
    string m_account;           //账号
    float m_deposit;            //余额
    int m_dealtimes;            //交易次数
    int m_dealclass[100];       //交易类型
    float m_dealmoney[100];     //交易金额
    string m_time[100];         //交易时间
    string m_password;          //密码

    public:
    Bank_account(string Name, string Account, string Time, string Psword)
    {
        m_name=Name;
        m_account=Account;
        m_deposit=0.f;
        m_dealtimes=0;
        m_time[0]=Time;
        m_dealclass[100]={0};
        m_dealmoney[100]={0.f};
        m_password=Psword;
    }
//构造函数：初始化对象名字，账号，交易次数等数据

    void Deposit(float deposit, string Time)
    {
        m_deposit+=deposit;
        m_dealtimes++;
        m_time[m_dealtimes]=Time;
        m_dealclass[m_dealtimes]=1;
        m_dealmoney[m_dealtimes]=deposit;
    }
//存款

    void Withdrawal(float withdrawal, string Time)
    {
        m_deposit-=withdrawal;
        m_dealtimes++;
        m_time[m_dealtimes]=Time;
        m_dealclass[m_dealtimes]=2;
        m_dealmoney[m_dealtimes]=withdrawal;
    }
//取款

    void Show_person_date(void)
    {
        cout << "Name:" << m_name << endl;
        cout << "Account:" << m_account << endl;
        cout << "Deposit:" << m_deposit << endl;
    }
//显示账户信息

    void Dealrecord(void)
    {
        int i=1, j=1;

        cout << "       Dearecord:" << endl;

        for(i;i<=m_dealtimes;i++)
        {
            cout << "Time:" << m_time[i];
            if(m_dealclass[i]==1)
            {
                cout << "   Take in:" << m_dealmoney[i] << endl;
            }
            else
            {
                cout << "   Take out:" << m_dealmoney[i] << endl;
            }         
        }

        cout << "Balance:" << m_deposit << endl;
    }
//显示交易记录

    int Log_in(string password)
    {
        if(password==m_password)
        {
            return 1;
        }
        return 0;
    }
//判断输入密码是否正确
};

void Menu(void);

int main(void)
{
    Bank_account person1={"YinghaoXu", "13142021", "2020.12.29", "54012"};
    int iflag=1;
    string psword;

    cout << "Please input your password:";
    cin >> psword;
    system("cls");

    do
    {
        if(person1.Log_in(psword)==1)
        {
            int selection;
            while(1)
          {
            Menu();
            cout << "           Please select function:";
            cin >> selection;

            switch(selection)
            {
                case 1: {
                            system("cls");
                            float a;
                            string b;
                            cout << "Please input despoit money and time:" << endl;
                            cin >> a >> b;
                            person1.Deposit(a,b);
                            cout << "Deposit successfully!" << endl;
                            system("pause");
                            system("cls");
                        };break;

                case 2:{
                            system("cls");
                            float a;
                            string b;
                            cout << "Please input withdrawal money and time:";
                            cin >> a;
                            cin >> b;
                            person1.Withdrawal(a,b);
                            cout << "Withdrawal successfully!" << endl;
                            system("pause");
                            system("cls");
                        };break;

                case 3:system("cls"),person1.Show_person_date(), system("pause"), system("cls");break;
                case 4:system("cls"),person1.Dealrecord(), system("pause"), system("cls");break;
                case 5:exit(-1);
            }

          }

        }

        else
        {
            string c_Flag;
            cout << "Password is error! Whether to continue typeing?(Y/N)" << endl;
            cin >> c_Flag;
            if(c_Flag=="Y")
            {
                cout << "Please input your password again:";
                cin  >> psword;
            }
            else
            {
                iflag=0;
            }
        }
        
        
    } while(iflag!=1);
    return 0;
}

void Menu(void)
{
    cout << "       Welcome into bank self-help system!" << endl;
    cout << endl;
    cout << "               1.Deposit" << endl;
    cout << endl;
    cout << "               2.Withdrawal" << endl;
    cout << endl;
    cout << "               3.Account management" << endl;
    cout <<endl;
    cout << "               4.Dealing slip" << endl;
    cout << endl;
    cout << "               5.Exit system" << endl;
    cout << endl;
}

//期望操作：建立银行类，其类方法具有初始化银行账户类的姓名，账号，开户时间，密码的权限
//