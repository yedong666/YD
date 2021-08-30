//自定义类型的转换
#include <iostream>
using namespace std;

class Stonewt
{
    private:
    enum {Labs_per_stn = 14};
    int stone;
    double pds_left;
    double pounds;
    public:
    Stonewt(double lbs);
    Stonewt(int stn, double lbs);
    Stonewt();
    void show_lbs() const;
    void show_stn() const;
};

Stonewt::Stonewt(double lbs)
{
    stone = int (lbs)/Labs_per_stn;
    pds_left = int (lbs)%Labs_per_stn+lbs-int(lbs);
    pounds=lbs;
}

Stonewt::Stonewt(int stn, double lbs)
{
    stone = stn;
    pds_left = lbs;
    pounds = stn*Labs_per_stn+lbs;
}

Stonewt::Stonewt()
{
    stone = pounds = pds_left = 0;
}

void Stonewt::show_stn()const
{
    cout << stone << " stone, " << "pds_left" << " pounds\n";
}

void Stonewt::show_lbs()const
{
    cout << pounds << " pounds\n";
}

void display(const Stonewt & st, int n);
int main(void)
{
    Stonewt incognito = 275;
    Stonewt wolfe(285.7);
    Stonewt taft(21, 8);

    cout << "The celebrity weighted ";
    incognito.show_stn();
    cout << "The detective weighted ";
    wolfe.show_stn();
    cout << "The President weighted ";
    taft.show_lbs();
    incognito=276.8;
    taft=325;
    cout << "After dinner, the celebrity weighted ";
    incognito.show_stn();
    cout << "After dinner, the President weighted ";
    taft.show_lbs();
    display(taft, 2);
    cout << "The wrestler weighted even more.\n";
    display(422,2);
    cout << "No stone left unearned\n";
    
    return 0;
}

void display(const Stonewt & st, int n)
{
    for(int i=0;i<n;i++)
    {
        cout << "Wow! ";
        st.show_stn();
    }
}