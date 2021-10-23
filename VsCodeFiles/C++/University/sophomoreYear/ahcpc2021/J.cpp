#include <iostream>
using namespace std;

/*

需求：给定两字符串s1, s2;
      对于字符串s1仅可以交换相邻两个字符位置，使得s1 > s2,
      求最小交换次数，如若无法实现，则返回-1

分析：解决此问题有几个难点，如何确定需要交换的字符位置，在实现交换位置逻辑时，是通过状态转换来模拟交换
      还是直接在字符串上交换字符位置，如果是通过状态转换，那又该设计怎样的状态转换量。
      对于实现交换逻：我们不难发现真正需要用到的就是第一个小于target对应位置的字符与第一个大于或者等于
                     target对应位置的字符targetChar，先比较s1的第一个字符与targetChar,
                     大于，则说明不需要交换
                     等于，则将之删除，再递归地进行该过程，获得之后所需的交换次数
                     小于，则依次遍历s1，若发现某位置字符大于或者等于targetChar,
                     则计算其与s1中第一个字符的距离.
      对于确定交换字符位置可以这样进行：
      1.依次比较s1与s2的每个字符，若发现s1在对应位置上的字符小于s2的，便向后搜索
      2.向后搜索的过程中会出现三种情况：
        a.先找到一个与s2对应位置相等的字符
        b.先找到一个大于s2对应位置的字符
        c.找不到大于或等于s2对应位置的字符
      3.针对2的情况进行分析：
        对于情况a, 我们是无法确定对其执行交换是否为最优解，因为若后面一定范围内出现了大于s2对应位置的字符bigger
        那么bigger可能才是最优交换位置，以一个例子说明：
        s1 = "cfgba", s2 = "bccfg"
        若要使s1大于s2有两种做法：第一种：a向左连续交换4次；第二种：b先向左交换3次，a再向左交换2次
        显然此时第一种方法更优。
        针对这种情况目前没有更好的方法，只有将之比较，取更优解。因此在发现等于s2对应位置的字符时，需要递归地再次进行
        该过程，直到得出结果，然后进行比较。

        对于情况b:可直接得出结果，返回即可

        对于情况c：返回-1即可
*/

class Solution{
public:
    //目标字符
    string targetS;
    int minSwap(string &s, int pos){
      int b = -1; 
      int c = 0;
      if (s[0] < targetS[pos]){
        //若s的第一个字母就小于targetS的对应字母，说明不需要交换
        return 0;
      } else if (s[0] == targetS[pos]){
        //若s的第一个字母就等于targetS的对应字母，则继续比较接下来的字符，返回比较次数
        s.erase(0, 1);
        return minSwap(s, pos + 1);
      } else{
        //用此变量表示--是先获得相等字母还是小于字母
        bool flag;
        for(int i = 1; i < s.size(); i++){
          //若首先发现大于targetS的pos位置的字符，则直接返回交换次数
           if (s[i] < targetS[pos] && !flag){
            return i;
          }

          //若发现大于targetS的pos位置的字符之前已发现等于targetS的pos位置的字符，
          //则返回交换次数较少的情况下的次数
          if (s[i] < targetS[pos] && flag){
              c = i;
              return b < c ? b : c;
          }

          //若先发现targetS的pos位置的字符，则修改flag标记
          //然后递归地计算需要交换的次数并将之保存
          if (s[i] == targetS[pos] && !flag){
            string tempS = s;
            tempS.erase(i, 1);
            //计算此后还需交换的次数
            b = minSwap(tempS, pos + 1);
            if (b == -1){
              //若无法达到大于targetS的要求
              //则按原路一直返回-1
              return -1;
            } else{
              //否则就加上当前需要交换的次数
              b += i;
            }
            flag = true;
            continue;
          }
        }
      }
      /*
        b的初始值为-1，若未搜索到任何大于等于target的pos位置的字符
        则说明无法达到要求
      */
      return b;
    }
};


int main(void){
    Solution solution;
    string s1, s2;
    cin >> s1;
    cin >> s2;
    solution.targetS = s2;
    cout << solution.minSwap(s1, 0);
    return 0;
}