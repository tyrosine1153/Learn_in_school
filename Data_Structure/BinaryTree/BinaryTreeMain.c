#include<stdio.h>
#include"BinaryTree.h"

int main(void){
    BTreeNode* bt1 = makeBTreeNode();
    BTreeNode* bt2 = makeBTreeNode();
    BTreeNode* bt3 = makeBTreeNode();
    BTreeNode* bt4 = makeBTreeNode();

    SetData(bt1, 1);
    SetData(bt2, 2);
    SetData(bt3, 3);
    SetData(bt4, 4);

    MakeLeftSubTree(bt1, bt2);
    MakeRightSubTree(bt1, bt3);
    MakeLeftSubTree(bt2, bt4);

    printf("%d \n",GetData(GetLeftSubTree(bt1)));
    printf("%d \n",GetData(GetRightSubTree(bt1)));

    return 0;
}
