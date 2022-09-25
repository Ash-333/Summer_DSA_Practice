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

void print(Node* root){
    if(root==NULL){
        return;
    }

    print(root->left);
    cout<<root->data;
    print(root->right);
}


int main(){
    Node* root=NULL;

    for(int i=1;i<=10;i++){
        int a;
        cin>>a;
        root=insert(root,a);
    }

    print(root);


}