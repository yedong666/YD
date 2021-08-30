#include <iostream>
#include <string>
#define MAXLEN 100
using namespace std;

class seqlist
{
private:
    char date[MAXLEN];
    int ListLen;
public:
    seqlist();
    void addnode(char ch);
    void getlistlen();
};
seqlist::seqlist()
{
    ListLen=0;
}
void seqlist::addnode(char ch)
{
    date[ListLen]=ch;
    ListLen++;
}
void seqlist::getlistlen()
{
    cout << "The length of list is " << ListLen << endl;
}

int main(void)
{
    seqlist A, B, C;
    return 0;
}
