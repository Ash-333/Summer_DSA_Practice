#include<iostream>
#include<stack>
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

Node* inorderSuccessor(Node* root,Node* target){
    if(target->right!=NULL){
        Node* temp=root->right;

        while (temp->left!=NULL){
            temp=temp->left;
        }
        return temp;        
    }

    Node* temp=root;
    Node* succ=NULL;

    while(temp!=NULL){
        if(temp->data>target->data){
            succ=temp;
            temp=temp->left;
        }
        else if(temp->data < target->data){
            temp=temp->right;
        }
        else{
            break;
        }
        
    }
    return succ;    
}