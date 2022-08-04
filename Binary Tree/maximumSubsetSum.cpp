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

pair<int,int> maxSubset(Node* root){
    pair<int,int> p,l,r;

    if(root==NULL){
        p.first=p.second=0;
        return p;
    }

    l=maxSubset(root->left);
    r=maxSubset(root->right);

    p.first=root->data+l.second+r.second;
    p.second=max(l.first,l.second)+max(l.first,l.second);
    return p;
}

// another way to solve

int maxPath(Node* root,int &maxi){
    if(root==NULL){
        return 0;
    }

    int  left=max(0,maxPath(root->left,maxi));
    int right=max(0,maxPath(root->right,maxi));
    maxi=max(maxi,left+right+root->data);

    return max(left,right)+root->data;
}

int maxSumpath(Node* root){
    int maxi=INT_MIN;
    maxPath(root,maxi);
    return maxi;
}