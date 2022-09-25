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

Node* insert(Node* root,int d){
    if(root==NULL){
        return new Node(d);
    }

    if(d<root->data){
        root->left=insert(root->left,d);
    }

    if(d>root->data){
        root->right=insert(root->right,d);
    }
    return root;
}

int isClosest(Node* root,int k){
    int close;
    int diff=INT_MAX;
    Node* temp=root;

    while(temp!=NULL){
        int current_diff=abs(temp->data-k)

        if(current_diff==0){
            return temp->data;
        }
        
        if(current_diff<diff){
            diff=current_diff;
            close=temp->data;
        }

        if(temp->data>k){
            temp=temp->right;
        }
        else{
            temp=temp->left;
        }
    }

    return close;
}