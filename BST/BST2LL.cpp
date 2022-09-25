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

pair<Node*,Node*> list(Node* root){
    if(root==NULL){
        return {NULL,NULL};
    }

    pair<Node*,Node*> l;

    if(root->left==NULL and root->right==NULL){
        l.first=l.second=root;
        return l;
    }

    else if(root->left!=NULL and root->right==NULL){
        pair<Node*,Node*> leftL=list(root->left);
        leftL.second->right=root;

        l.first=leftL.first;
        l.second=root;
    }
    else if(root->right!=NULL and root->right==NULL){
        pair<Node*,Node*> rightL=list(root->right);
        root->right=rightL.first;

        l.first=root;
        l.second=rightL.second;
    }

    else{
        pair<Node*,Node*> leftL=list(root->left);
        pair<Node*,Node*> rightL=list(root->right);

        leftL.second->right=root;
        root->right=rightL.first;

        l.first=leftL.first;
        l.second=rightL.second;
    }

    return l;
}

int main(){
    vector<int> arr={8,3,10,1,6,14,4,7,13};
    Node* root=NULL;

    for(int i:arr){
        root=insert(root,i);
    }

    auto l=list(root);

    while(l.first!=NULL){
        cout<<l.first->data<<"-> ";
        l.first=l.first->right;
    }
    cout<<"Program Completed";
}