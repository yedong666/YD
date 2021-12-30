#include <iostream>
#include <string>
#include <map>
using namespace std;

string getName(string s){
	string name;
    for(int i = 0; s[i] != ':' && i < s.size(); i++){
    	name += s[i];
    }
  return name;
}

int main(void){
	int n;
    map<string, int> dragans;
    cin >> n;
    string name;
    string s;
    string dragan = "";
    int max = 0;
    for(int i = 0; i < n; i++){
      getline(cin,s);
      name = getName(s);
      if (dragans.find(name) == dragans.end()){
        dragans[name] = 1;
      } else{
        dragans[name] += 1;
      }
      if (dragans[name] > max){
      	dragan = name;
        max = dragans[name];
      }
    }
  cout << dragan;
  return 0;
}