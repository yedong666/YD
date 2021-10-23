#include<iostream>
#include<vector>

using namespace std;

typedef struct cross{
	int num;
	int c_times;
	int c_timee;
}cross;

typedef struct worker{
	int numf;
	int numb;
	int w_times;
	int w_timee;
}worker;

vector<cross> cro;
vector<worker> wor;

bool jud(worker &w, vector<cross> cro){
	vector<int> t;
	vector<int>::iterator it; 
	cross c; 
	
	for(int i=w.w_times; i <= w.w_timee; i++){
		t.push_back(i);
	}
	
	for(int i=0; i<cro.size(); i++){
		c = cro[i];
		
		if(c.num>=w.numf && c.num<=w.numb){
			
			for(int j=c.c_times; j <= c.c_timee; j++){
				
				for(it = t.begin(); it != t.end(); it++){
					if(*it == j){
						t.erase(it);
						break;
					}
				}
			}
		}
	}
	
	return t.empty();
}

int main(){
	int N, Q;
	cross c;
	worker w;
	
	cin>>N;
	for(int i=0; i<N; i++){
		cin>>c.num>>c.c_times>>c.c_timee;
		cin.clear();
		cro.push_back(c);
	}
	
	cin>>Q;
	for(int i=0; i<Q; i++){
		cin>>w.numf>>w.numb>>w.w_times>>w.w_timee;
		cin.clear(); 
		wor.push_back(w);
	}
	
	for(int i=0; i<Q; i++){
		if(jud(wor[i], cro) == true){
			cout<<"Yes"<<endl;
		}else{
			cout<<"No"<<endl;
		}
	}
	
	return 0;
} 
