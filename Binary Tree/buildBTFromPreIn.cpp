#include <bits/stdc++.h>

using namespace std;

class Node {
    public:
  int data;
  Node * left, * right;

  Node(int d){
    data=d;
    left=NULL;
    right=NULL;
  }
};

Node* constructTree(vector<int> &preorder,int preS,int preE,vector<int> &inorder,int inS,int inE,map<int,int> &mp){
    if(preS>preE or inS>inE){
        return NULL;
    }

    Node* root=new Node(preorder[preS]);

    int element=mp[root->data];
    int subTree=element-inS;

    root->left=constructTree(preorder,preS+1,preS+subTree,inorder,inS,element-1,mp);
    root->right=constructTree(preorder,preS+element+1,preE,inorder,element+1,inE,mp);
    return root;
}

Node* buildTree(vector<int> preorder,vector<int> inorder){
    map<int,int> mp;
    int preE=preorder.size()-1;
    int inE=inorder.size()-1;

    for(int i=0;i<inorder.size();i++){
        mp[inorder[i]]=i;
    }

    return constructTree(preorder,0,preE,inorder,0,inE,mp);
}

void pre(Node* root){
    if(root==NULL){
        return;
    }

    cout<<root->data<<" ";
    pre(root->left);
    pre(root->right);
}
int main() {


  vector<int> preorder{3,9,20,15,7};
  vector<int> inorder{9,3,15,20,7};
  Node * root = buildTree(preorder, inorder);
  pre(root);
  return 0;
}