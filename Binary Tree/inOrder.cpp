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

vector<int> inOrder(Node* root){
    stack<Node*> s;
    vector<int> res;
    Node* node=root;

    while(true){
        if(node!=NULL){
            s.push(node);
            node=node->left;
        }

        else{
            if(s.empty()==true){
                break;  
            }
            node=s.top();
            s.pop();
            res.push_back(node->data);
            node=node->right;
        }
    }

    return res;
}

int main(){

}