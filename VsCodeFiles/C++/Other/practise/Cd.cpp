#include <iostream>
#include <cstring>
using std::cout;
using std::endl;
class Cd{
//Cd类
private:
    char performers[50];    //表演者
    char label[20];         //风格
    int selections;         //歌曲数量
    double playtime;        //播放时长
public:
    Cd(char * s1, char * s2, int n, double x);
    Cd(const Cd & d);
    Cd();
    virtual ~Cd();
    virtual void Report() const;
    virtual Cd & operator= (const Cd & d);
};

class Classic : public Cd{
//古典音乐类
private:
    char mainworks[100];
public:
    Classic(Cd & cd, char * s);
    Classic();
    virtual void Report() const;
    virtual Classic & operator= (const Classic *clscd);
    virtual ~Classic();
};

Cd::Cd(){}

Cd::Cd(char * s1, char * s2, int n, double x){
    strcpy(performers, s1);
    strcpy(label, s2);
    selections = n;
    playtime = x;
}

Cd::Cd(const Cd & d){
    strcpy(this->performers, d.performers);
    strcpy(this->label, d.label);
    selections = d.selections;
    playtime = d.playtime;
}

void Cd::Report() const{
    cout << performers << endl;
    cout << label << endl;
    cout << selections << endl;
    cout << playtime << endl;
    cout << "\n" << endl;
}

Cd & Cd::operator=(const Cd & d){
    Cd newcd;
    strcpy(newcd.performers, d.performers);
    strcpy(newcd.label, d.label);
    newcd.selections = d.selections;
    newcd.playtime = d.playtime;
    return newcd;
}

Classic::Classic() {}

Classic::Classic(Cd & d, char * s) : Cd(d) {
    strcpy(mainworks, s);
}

void Classic::Report() const{
    cout << mainworks << endl;
    Cd::Report();
}

Classic & Classic::operator=(const Classic *clscd){
    Classic newcd;
}


