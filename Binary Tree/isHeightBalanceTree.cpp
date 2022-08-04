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

pair<int,bool> isBalanced(Node* root){
    pair<int,bool> p,right,left;

    if(root==NULL){
        p.first=0;
        p.second=true;
        return p;
    }

    left=isBalanced(root->left);
    right=isBalanced(root->right);

    int height=max(left.first,right.first)+1;

    if(abs(left.first-right.first)<=1 and left.second and right.second){
        return make_pair(height,true);
    }

    return make_pair(height,false);
}