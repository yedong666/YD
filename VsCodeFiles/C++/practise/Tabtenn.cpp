#include <iostream>
#include <string>
using namespace std;

//乒乓求运动员类（基类）
class TabTennisPlayer
{
    private:
    string firstname;
    string lastname;
    bool hastable;      //是否有球桌

    public:
    TabTennisPlayer(const string & fn = "none", const string & ln ="none", bool ht=false);
    void Name()const;
    bool Hastable()const
    {
        return hastable;
    };
    void ResetTable(bool v)
    {
        hastable = v;
    };
};

//参加过比赛的远动员类（派生类）
class RatedPlayer : public TabTennisPlayer 
{
    private:
    unsigned int rating;    //在比赛中的得分

    public:
    RatedPlayer(unsigned int r=0, const string & fn="none", const string &ln="none", bool ht=false);
    RatedPlayer(unsigned int r, const TabTennisPlayer & tp);
    unsigned int Rating()const { return rating; };
    void ResetRating(unsigned int r) { rating=r; };
};

//采用成员初始化列表语法
TabTennisPlayer::TabTennisPlayer(const string & fn, const string & ln, bool ht):
firstname(fn), lastname(ln), hastable(ht) 
{}

void TabTennisPlayer::Name()const
{
    cout << lastname << ", " << firstname ;
}

RatedPlayer::RatedPlayer(unsigned int r, const string & fn, const string &ln, bool ht):
TabTennisPlayer(fn, ln, ht)
{
    rating=r;
}

RatedPlayer::RatedPlayer(unsigned int r, const TabTennisPlayer & tp):
TabTennisPlayer(tp), rating(r) {}   //采用编译器自动生成的拷贝构造函数初始化列表

//验证类功能
int main(void)
{
    TabTennisPlayer player1("Kobe", "Blanket", true);
    TabTennisPlayer player2("Lebron", "James", false);
    TabTennisPlayer player3("Yao", "Ming", true);
    RatedPlayer rtplayer1(100, "Stefen", "Curry", true);
    RatedPlayer rtplayer2(900, "Kedis", "Paual", false);
    RatedPlayer rtplayer3(1000, player3);


    player1.Name();
    if(player1.Hastable())  //判断是否有球桌，下同
    {
        cout << ": has a table.\n";
    }
    else
    {
       cout << ": hassn't a table.\n";
    }
    player2.Name();
    if(player2.Hastable())
    {
         cout << ": has a table.\n";
    }
     else
    {
       cout << ": hassn't aa table.\n";
    }

    rtplayer1.Name();
    if(rtplayer1.Hastable())
    {
         cout << ": has a table.\n";
    }
     else
    {
       cout << ": hassn't aa table.\n";
    }

    cout << "His rating is :" << rtplayer1.Rating() << endl;

    rtplayer2.Name();
    if(rtplayer2.Hastable())
    {
         cout << ": has a table.\n";
    }
     else
    {
       cout << ": hassn't aa table.\n";
    }
    cout << "His rating is :" << rtplayer2.Rating() << endl;

    
    return 0;
}