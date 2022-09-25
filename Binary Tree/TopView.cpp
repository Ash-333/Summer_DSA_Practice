#include<iostream>
#include<queue>
#include<vector>
#include<map>
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

vector<int> topView(Node* root){

    vector<int> ans;
    if(root==NULL){
        return ans;
    }
    
    map<int,int> mpp;
    queue<pair<Node*,int>> q;

    q.push({root,0});

    while(!q.empty()){
        auto it=q.front();
        q.pop();

        Node* node=it.first;
        int line=it.second;
        
        if(mpp.find(line)==mpp.end()){
            mpp[line]=node->data;
        }

        if(node->left!=NULL){
            q.push({node->left,line-1});
        }
        
        if(node->right!=NULL){
            q.push({node->right,line+1});
        }
    }

    for(auto it:mpp){
        ans.push_back(it.second);
    }

    return ans;
}