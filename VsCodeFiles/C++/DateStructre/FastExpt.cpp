#include <iostream>
using std::cout;
using std::endl;
int Square(int n){
    return n*n;
}

int FastExpt(int base, int expt){
    if ( expt == 0){
        return 1;
    }
    if (expt%2 == 0){
        return Square(FastExpt(base, expt/2));
    }
    else{
        return base*FastExpt(base, expt-1);
    }
}

int FastMult(int fator1, int fator2){
    if (fator2 == 0 || fator1 == 0){
        return 0;
    }
    if (fator2 == 1){
        return fator1;
    }
    if (fator2%2 == 0){
        return FastMult(fator1, fator2/2)*2;
    }
    else{
        return fator1+FastMult(fator1, fator2-1);
    }
}

int main(void){
    cout << FastExpt(2,20) << endl;
    cout << FastMult(10000, 10000);
    return 0;
}

