#include <iostream>
#include <string>
#include <vector>
using namespace std;

/*
    (1) 字符串调整 
考虑两个字符串 X = x1x2 ... xm 和 Y = y1y2 ... yn，且字符属于集合{A, G,C, T}。现
在要在 X 和 Y 中插入空格，得到字符串 X*和 Y*，要求： 
a) X*和 Y*有同样的长度； 
b) 如果忽略空格，X*=X，Y*=Y。 
举个例子：X='GATCCGA',Y='GAAAGCAGA',插入空格后(空格用-表示)，可以得到的一种结果
是 
X*=G-A--TCCGA 
Y*=GAAAG-CAGA 
当然也可以是下面的结果： 
X*=GA---TCCGA 
Y*=GAAAG-CAGA. 
怎么评定它们的优劣呢？我们又下面的法则：如果 xi 和 yj 对齐, 得分是:
    xi = yi 得分为：2
    xi != yi 得分为 -1
如果一个 X*(或 Y*)的连续的子串和 Y*(或 X*)的一个长度为 k 的空格子串对齐，得分是 -(4 
+ k). 
所以，第一种结果的得分是 2 - (4 + 1) + 2 - (4 + 2) - (4 + 1) + 2 - 1 + 2 + 2 = -7；
第二种结果的得分是 2 + 2 - (4 + 3) - (4 + 1) + 2 - 1 + 2 + 2 = -3。 
现在你的问题是对于给定的 X 和 Y 的，找出得分最高的 X*和 Y*。对于上面的例子，最好的
结果是： 
X*=GA--TCCGA 
Y*=GAAAGCAGA. 
得分为 2+2-(4+2)-1+2-1+2+2=2。在这题中，m 和 n 最大为 500，并且 X*和 Y*中没有任何
两个空格是对齐的。 
输入格式：
第一行为一个整数，给出了测试的数目，接下来每两行给出一对 X 和 Y。 
输出格式：
对于每一组输入，输出得分的最大值。 
输入样例：
3 
ACGGCTTAGATCCGAGAGTTAGTAGTCCTAAGCTTGCA 
AGCTTAGAAAGCAGACACTTGATCCTGACGGCTTGAA 
TTGAGTAGTGTTTTAGTCCTACACGACACATCAAATTCGGACAAGGCCTAGCT 
TTCAAGTCCTACAATGTGTGTCAAATTCGCTTGGCCGAAAGCC 
TTTGGGAACGTGTGTAGACTTCCCCATGCGATGG 
AACACACACGGACTTCATGCTGG 
输出样例：
18 
20 
2

分析：
题目过长，翻译过来就是给出两个字符串，分别对两个字符串中添加空格字符，
         使得得分尽可能高；
积分规则是这样：
         当两字符串中有一个出现连续的（k >= 1）的空格子串，则加-(4 + k)分
         其余非空格字符，进行两两比较，相同加2分, 不同则加-2分
         且不能出现空格对齐的情况
在此规则下，应使得空格尽可能连续，同时控制插入位置使得对齐字符之间尽可能相等
*/

class Solution{
public:
    int maxScore(string sx, string sy){

    }

    //获取当前两字符串的分数
    int getScore(string sx, string sy){
        for(int i)
    }
};


int main(void){
    int N;
    cin >> N;
    vector<string> xStrings(N);
    vector<string> yStrings(N);
    for(int i = 0; i < N; i++){
        cin >> xStrings[i];
        cin >> yStrings[i];
    }
    Solution solution;
    for(int i = 0; i < N; i++){
        cout << solution.maxScore(xStrings[i], yStrings[i]) << endl;
    }
    return 0;
}