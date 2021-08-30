#include <iostream>
#include <ctime>
#include <string>
#include <cstdlib>

using namespace std;

class Player//ѡ���࣬�д�����
{
    private:
    string ms_name;
    int mn_number;
    float mf_score[10];
    float mf_sumscore;
    float mf_avescore;

    public:
    Player(string n, int m)
    {
        ms_name=n;
        mn_number=m;
        mf_score[10]={0.f};
    }
    
    float Calculate_sumscore(float *p);//�����ܷ�
    float Calculate_avescore(float sum);//����ƽ����
    void Show_player_date(void);//��ʾѡ���������
};

float Player::Calculate_sumscore(float *p)
{
    float sumscore=0.f;
    for(int i=0;i<10;i++)
    {
        sumscore+=p[i];
    }
    return sumscore;
}

float Player::Calculate_avescore(float sum)
{
    return sum/10;
}

void Player::Show_player_date(void)
{
    cout << "Name:" << ms_name << endl;
    cout << "Number:" << mn_number << endl;
    cout << "Sumscore:" << mf_sumscore << endl;
    cout << "Avescore:" << mf_avescore << endl;

    for(int i;i<10;i++)
    {
        cout << "Jude" << i << "gave score:" << mf_score[i] << endl;
    }
}

class Judge//��ί�࣬�д�����
{
    private:
    int mn_number;

    public:
    Judge(int n);
    void Mark(float *a,float *b);
};

Judge::Judge(int n)
{
    mn_number=n;
}

void Judge::Mark(float *a, float *b)
{

}

class Songs
{
    private:
    string ms_song_name;

    public:
    void Play_song(void);
    void End_play_song(void);
};

int main(void)
{
    Player player1("Jack", 1);

    player1.Show_player_date(); 

    return 0;
}