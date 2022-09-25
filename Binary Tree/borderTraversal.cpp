#include<iostream>
#include<queue>
#include<vector>
using namespace std;


// 1 2 4 -1 -1 5 7 -1 -1 -1 3 -1 6 -1 -1
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

bool isLeaveNode(Node* root){
    if(root->left==NULL and root->right==NULL){
        return true;
    }
    return false;
}

void addLeft(Node* root,vector<int> &result){
    Node* current=root->left;

    while(current){
        if(!isLeaveNode(current)){
            res.push_back(current->data);
        }

        if(current->left){
            current=current->left;
        }

        else{
            current=current->right;
        }
    }
}

void addRight(Node* root,vector<int> &res){
    Node* curr=root->right;
    stack<int> s;

    while(curr){
        if(!isLeaveNode(curr)){
            s.push(curr->data);
        }

        if(curr->right){
            curr=curr->right
        }
        else{
            curr=curr->left
        }
    }

    for(int i:s){
        res.push_back(i);
    }
}

void addLeaves(Node* root,vector<int> &res){
    if(isLeaveNode(root)){
        res.push_back(root->data);
        return;
    }

    if(root->left){
        addLeaves(root->left,ans);
    }

    if(root->right){
        addLeaves(root->right,ans);
    }
}

vector<int> printBoundary(Node* root){
    vector<int> res;
    
    if(root==NULL){
        return res;
    }

    addLeft(root,res);
    addLeaves(root,res);
    addRight(root,res);
    return res;
    
}