#include "TeachSrc.h"
#include <queue>

static int degree;
void PreorderTraversal(csNode *node);     //先根遍历
void PostorderTraversal(csNode *node);    //后根遍历
void LevelTraversal(csNode *node);        //层序遍历
int GetForestHeight(csNode *node);        //求森林的高度
int GetForestNodeNum(csNode *node);       //求森林的结点个数
int GetLeavesNodeNum(csNode *node);       //求森林的叶子结点个数
void GetForestDegree(csNode *node);       //求森林的度
void InputForestDateAndLevel(csNode *node , int level = 0);   //输出森林的结点数据与层次
void InputGeneralizedListTree(csNode *node);                  //输出广义表表示的树

void Menu(void){
    cout << "1.先根遍历" << endl;
    cout << "2.后根遍历" << endl;
    cout << "3.层序遍历" << endl;
    cout << "4.求森林高度" << endl;
    cout << "5.求森林的结点个数" << endl;
    cout << "6.求森林的叶子结点个数" << endl;
    cout << "7.求森林的度" << endl;
    cout << "8.输出森林的结点数据与层次" << endl;
    cout << "9.输出广义表表示的树" << endl;
    cout << "输入负一退出" << endl;
}

int main(void){
    pTree testTree;
    csNode *csT;
    CreateTreeFromFile("ForestData.txt",testTree);
    createCsTree(csT, testTree);
    while(1){
        Menu();
        int testNum;
        cout << "请输入题号：" << endl;
        cin >> testNum;
        switch(testNum){
            case 1: PreorderTraversal(csT);
                    system("pause");
                    break;
            case 2: PostorderTraversal(csT);
                    system("pause");
                    break;
            case 3: LevelTraversal(csT);
                    system("pause");
                    break;
            case 4: cout << "森林的高度是：" << GetForestHeight(csT) << endl;
                    system("pause");
                    break;
            case 5: cout << "森林的结点个数是：" << GetForestNodeNum(csT) << endl;
                    system("pause");
                    break;
            case 6: cout << "森林的叶子结点个数为：" << GetLeavesNodeNum(csT) << endl;
                    system("pause");
                    break;
            case 7: GetForestDegree(csT);
                    cout << "森林的度为：" << degree <<endl;
                    system("pause");
                    break;
            case 8: InputForestDateAndLevel(csT);
                    system("pause");
                    break;
            case 9: InputGeneralizedListTree(csT);
                    system("pause");
                    break;
            case -1: return 0;
        }
        system("cls");
    }
    return 0;
}

void PreorderTraversal(csNode *node){
    if (node != NULL){
        cout << node->data << endl;
        PreorderTraversal(node->firstChild);
        PreorderTraversal(node->nextSibling);
    }
}

void PostorderTraversal(csNode *node){
   if (node != NULL){
    PostorderTraversal(node->firstChild);
    cout << node->data << endl;
    PostorderTraversal(node->nextSibling);
   }
}

void LevelTraversal(csNode *node){
    if (node != NULL){
        csNode *ptemp = node;
        queue<csNode*> nodeQueue;
        while(ptemp != NULL || !nodeQueue.empty()){
            while(ptemp){
                cout << ptemp->data << endl;
                nodeQueue.push(ptemp->firstChild);
                ptemp = ptemp->nextSibling;
            }
            ptemp = nodeQueue.front();
            nodeQueue.pop();
        }
    }
}

int GetForestHeight(csNode *node){
    if (node != NULL){
        int height, Bheight;
        height = GetForestHeight(node->firstChild) + 1;
        Bheight = GetForestHeight(node->nextSibling);
        return height > Bheight ? height : Bheight;
    }
    else{
        return 0;
    }
}

int GetForestNodeNum(csNode *node){
    if (node != NULL){
        return 1 + GetForestNodeNum(node->firstChild) + GetForestNodeNum(node->nextSibling);
    }
    else{
        return 0;
    }
}

int GetLeavesNodeNum(csNode *node){
    if (node != NULL){
        if (!node->firstChild){
            //若结点孩子结点为空，则其为叶子结点
            return 1 + GetLeavesNodeNum(node->nextSibling);
        }
        else{
            return GetLeavesNodeNum(node->firstChild) + GetForestNodeNum(node->nextSibling);
            //森林的叶子结点个数等于其子树的叶子结点数加上其兄弟结点数
        }
    }
    else {
        return 0;
    }
}

void GetForestDegree(csNode *node){
    if (node != NULL){
        csNode *ptemp = node;
        int i = 0;
        while(ptemp != NULL){
            i++;
            ptemp = ptemp->nextSibling;
        }
        if (degree < i){
            degree = i;
        }
        GetForestDegree(node->firstChild);
        GetForestDegree(node->nextSibling);
    }
}

void InputForestDateAndLevel(csNode *node , int level){
    if (node != NULL){
        cout << "date:" << node->data << "  level:" << level+1 << endl;
        InputForestDateAndLevel(node->firstChild, level+1);
        //孩子结点比当前结点的层数大一
        InputForestDateAndLevel(node->nextSibling, level);
        //兄弟结点与当前结点在同一层
    }
}

void InputGeneralizedListTree(csNode *node){
    if (node != NULL){
        cout << node->data ;
        if (node->firstChild){
            cout << "(";
        }
        InputGeneralizedListTree(node->firstChild);
        if (node->nextSibling){
             cout << ",";
        }
        else{
            cout << ")";
        }
        InputGeneralizedListTree(node->nextSibling);
    }
}




