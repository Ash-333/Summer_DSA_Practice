#include<iostream>
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

int findMax(Node* root){
    if(root==NULL){
        return INT_MIN;
    }

    int max=root->data;
    int left=findMax(root->left);
    int right=findMax(root->right);

    if(left>max)
        max=left;
    
    if(right>max)
        max=right;
    
    return max;
}

int findMin(Node* root){
    if(root==NULL)
        return INT_MAX;
    
    int min=root->data;
    int left=findMin(root->left);
    int right=findMax(root->right);

    if(left<min)
        min=left;
    
    if(right<min)
        min=right;
    
    return min;
}