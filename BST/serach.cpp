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

bool search(Node* root,int d){
    if(d==root->data){
        return true;
    }

    if(d<root->data){
        return search(root->left);
    }

    if(d>root->data){
        return search(root->right); 
    }

    return false;
}

int main(){

}