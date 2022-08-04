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

vector<vector<int>> zigzagTraversal(Node* root){
    vector<vector<int>> ans;

    queue<Node*> q;
    q.push(root);
    bool leftToRight=true;

    while(!q.empty()){
        int size=q.size();

        vector<int> row(size);
        for(int i=;i<size;i++){
            Node* node=q.front();
            q.pop();

            int index=(leftToRight) ? i: (size-1-i);

            row[index]=node->data;

            if(node->left){
                q.push(node->left);
            }

            if(node->right){
                q.push(node->right);
            }
        }

        leftToRight=!leftToRight;
        ans.push_back(row);
    }
    return ans;
}