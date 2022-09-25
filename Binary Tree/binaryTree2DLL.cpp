#include<iostream>
#include<queue>
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

Node* BTToDLL(Npde* root){
    Node* prev=NULL;

    if(root==NULL){
        return root;
    }

    Node* head=BTToDLL(root->left);
    if(prev==NULL){
        head=root;
    }
    else{
        root->left=prev;
        prev->right=root;
    }

    prev=root;
    BTToDLL(root->right);
    return head;
}

int main(){

}