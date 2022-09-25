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

Node* LCA(Node* root,int a,int b){
    if(root==NULL){
        return NULL;
    }

    if(a<root->data and b<root->data){
        return LCA(root->left,a,b);
    }
    if(a>root->data and b>root->data){
        return LCA(root->right,a,b);
    }
    return root;
}