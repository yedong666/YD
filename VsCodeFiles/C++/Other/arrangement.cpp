#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
	//求解全排列
	vector<vector<int> > arranges;
    bool flag[6];
	void getAllArrange(int baseData[6], int k, vector<int> &tempData){
		if (k == 6){
			arranges.push_back(tempData);
			for(int j = 0; j < 6; j++){
				cout << tempData[j] << " ";
			}
			cout << endl;
			return;
		}
		for(int i = 0; i < 6; i++){
			if (!flag[i]){
				tempData.push_back(baseData[i]);
				flag[i] = true;
				getAllArrange(baseData, k+1, tempData);
				//回溯 
				tempData.pop_back();
				flag[i] = false;
			}
		}
	} 
	
	void printfArranges(void){
		for(int i = 0; i < arranges.size(); i++){
			for(int j = 0; j < 6; j++){
				cout << arranges[i][j] << " ";
			}
			cout << endl;
		}
		return;
	}
	
	Solution(){
		for(int i = 0; i < 6; i++){
			flag[i] = false;
		}
	}
};

int main(void){
	int baseData[6] = {1, 2, 3, 4, 5, 6};
	Solution solution;
	int num = 6*5*4*3*2*1;
	//初始化数组存储全排列 
	vector<vector<int> > arranges(num);
	vector<int> tempData;
	solution.arranges = arranges;
	solution.getAllArrange(baseData, 0, tempData);
	solution.printfArranges();
	return 0;
}
