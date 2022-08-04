#include<iostream>
#include<stack>
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

int replaceWithSum(Node* root){
    if(root==NULL){
        return 0;
    }

    if(root->left==NULL and root->right==NULL){
        return root->data;
    }

    int LS=replaceWithSum(root->left);
    int RS=replaceWithSum(root->right);

    int temp=root->data;
    root->data=LS+RS;
    return root->data+temp;

}

Node* bulidTree(){
    
    int a;
    cin>>a;

    if(a==-1){
        return NULL;
    }

        Node* n=new Node(a);
        n->left=bulidTree();
        n->right=bulidTree();
    
    return n;
}

void inorderTraversal(Node* root){
    if(root==NULL){
        return;
    }

    inorderTraversal(root->left);
    cout<<root->data;
    inorderTraversal(root->right);
}

int main(){
    Node* root=bulidTree();
    cout<<replaceWithSum(root)<<endl;;
    inorderTraversal(root);
}