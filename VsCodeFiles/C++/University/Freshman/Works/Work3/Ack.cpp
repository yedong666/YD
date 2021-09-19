#include <iostream>
using namespace std;

int Ack(int m, int n);

// int Hcf(int M, int N){
//     int H;
//     while(N!=0){
//         H = M % N;
//         M = N;
//         N = H;
//     }
//     return M;
// }

// void reduce(int M1, int N1, int *M2, int *N2){
//     int R, J;
//     R = Hcf(M1, N1);
//     *M2 = M1/R;
//     *N2 = N1/R;
//     cout << M1 << '/' << N1 <<'=' << *M2 << '/' << *N2; 
// }

void P(int W){
    if (W>0){
        P(W-1);
        P(W-1);
        cout << W;
    }
}

void PrintRV(int N){
    if (N>0){
        cout << N%10;
        PrintRV(N/10);
    }
}

void PC(int M, int N, int *K){
    if (N==0){
        *K = 1;
    }
    else{
        PC(M-1, N-1, K);
        *K = *K*M/N;
    }
}

int SS(int N){
    if (N==0) return 100;
    else return SS(N-1)+N*N;
}

int ACM(int M, int N){
    if (M==0) return N+1;
    else if (N==0) return ACM(M-1, 1);
    else return ACM(M-1, ACM(M, N-1));
}


int main(void){
    int M;
    cout << ACM(2, 3);
    return 0;
}

int Ack(int m, int n){
    if (m == 0){
        return n+1;
    }
    if (n == 0){
        return Ack(m-1, 1);
    }
    if (m>0 && n>0){
        return Ack(m-1, Ack(m, n-1));
    }
    return 0;
}