#include<stdio.h>
#include<stdlib.h>
#include"AVL_tree.cpp"
#define MX 9

Node* insert_AVL_Node(Node** root, element x) {
    if (*root == NULL) {
        *root = (Node*)malloc(sizeof(Node));
        (*root)->item = x;
        (*root)->left = NULL;
        (*root)->right = NULL;
    }
    else if (x < (*root)->item) {
        (*root)->left = insert_AVL_Node(&(*root)->left, x);
        *root = reBalance(root);
    }
    else if (x > (*root)->item) {
        (*root)->right = insert_AVL_Node(&(*root)->right, x);
        *root = reBalance(root);
    }

    return *root;
}

Node* insert_BST_Node(Node* root, element x) {
    Node* New = (Node*)malloc(sizeof(Node));
    if (root == NULL) {
        New->item = x;
        New->left = NULL;
        New->right = NULL;
        root = New;
    }
    else if (x < root->item)
        root->left = insert_BST_Node(root->left, x);
    else if (x > root->item)
        root->right = insert_BST_Node(root->right, x);

    return root;
}

void p_out(int* p) {
    int a;
    for (a = 0; a < MX; ++a) {
        printf("%3d", *(p + a));
    } printf("\n");
}

void Pre_order(Node* p) {
    if (p) {
        printf("%3d(%d)\t", p->item, getBF(p));
        Pre_order(p->left);
        Pre_order(p->right);
    }
}

int main(void) {
    int data[MX] = { 6,5,7,3,2,9,8,1,4 };
    Node* root_AVL = NULL;
    Node* root_BST = NULL;
    int a;
    printf("\n입력자료: "); p_out(data);
    root_BST = insert_BST_Node(root_BST, data[0]);
    root_AVL = insert_AVL_Node(&root_AVL, data[0]);

    for (a = 1; a < MX; a++) {
        insert_BST_Node(root_BST, data[a]);
        insert_AVL_Node(&root_AVL, data[a]);

        printf("\n BST Tree: \t"); Pre_order(root_BST);
        printf("\n AVL Tree: \t"); Pre_order(root_AVL);
        printf("\n");
    }
    printf("\n\n 이진탐색트리를 reBalance하여 AVL트리로 변화시킨 후");
    root_BST->left = reBalance(&root_BST->left);
    root_BST->right = reBalance(&root_BST->right);
    printf("\n BST Tree: \t"); Pre_order(root_BST);
}
