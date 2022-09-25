#include<iostream>
#include<vector>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int d){
        data=d;
        left=NULL;
        right=NULL;
    }
};

bool isBSTHelper(Node* root,int min,int max){
    if(root==NULL)
        return 1;
    
    if(root->data<min or root->data>max){
        return 0;
    }

    return isBSTHelper(root->left,min,root->data-1) && isBSTHelper(root->right,root->data+1,max);
}

bool isBST(Node* root){
    return isBSTHelper(root,INT_MIN,INT_MAX);
}