#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

bool isBeautiful(long x){
	double a = sqrt(x);
    long t = a;
    if (fabs(a-t) < 0.00000001){
    	return false;
    }
    for(long b = t; b < a; b++){
		double m = fabs(sqrt(b*b + x) - (long)(sqrt(b*b + x)));
        if (m < 0.00000001){
        	return true;
        }
    }
                      return false;
}

int main(void){
  long L, R;
  cin  >> L >> R;
  int sum = 0;
  for(long i = L; i < R+1; i++){
  	if (isBeautiful(i)){
    	sum ++;
    }
  }
  cout << sum;
	return 0;
}  
  