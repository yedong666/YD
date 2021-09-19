//以下为图的方法实现以及各辅助函数的实现
#include "Graph.h"

//赋予图对象名字，便于寻找相应的数据文件
Graph::Graph(string & name)
{
   GraphName = name;
}

Graph::~Graph(void) {}

string & Delete_str_space(string & str)
{
   string newstr;
   int j = 0;
   for(int i=0; i<str.size(); i++)
   {
       if (str[i] == ' ')
       {
           continue;
       }
       else
       {
           newstr[j] = str[i];
           j++;
       }
   }
   return newstr;
}
//由于字符串规模不大,所以采用将传入字符串参数的非空格字符
//复制到新串中

bool Recognize_file(FILE * pfile)
{
    if (!pfile)
    {
        cout << "此文件无效！" << endl;
        return false;
    }
    
}