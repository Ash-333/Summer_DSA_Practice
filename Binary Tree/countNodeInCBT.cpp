#include<iostream>
using namespace std;

class Node{
    int data;
    Node* left;
    Node* right;

    Node(int d){
        data=d;
        left=NULL;
        right=NULL;
    }
};

int findLeftHeight(Node* root){
    int h=0;

    while(root){
        h++
        root=root->left
    }
    return h;
}

int findRightHeight(Node* root){
    int h=0;

    while(root){
        h++
        root=root->right
    }
    return h;
}

int countNode(Node* root){
    if(root==NULL){
        return;
    }

    int lh=findLeftHeight(root->left);
    int rh=findRightHeight(root->right);

    if(lh==rh){
        return  (1<<lh)-1;
    }

    return 1+countNode(root->left)+countNode(root->right);
}

int main(){

}