//回文数（整型）的判断
class Solution {
public:
    bool isPalindrome(int x) {
        if (x<0){
            return false;
        }
        if(!x){
            return true;
        }
        if(!(x%10)){
            return false;
        }
        int newnuer = 0;
        int y;
        while(x){
            newnuer = newnuer*10 + x%10;
            y = x;
            x /= 10;
            if(newnuer==x||newnuer==y){
                return true;
            }
            if(newnuer>x){
                break;
            } 
        }
        return false;
    }
};
int main(void){
    return 0;
}