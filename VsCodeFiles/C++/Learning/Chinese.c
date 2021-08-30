#include <stdio.h>
int main(void){
   char ch;
   for(ch = 'Z'; ch>='A'; ch--){
       printf("%c", ch);
   }
   return 0;
}