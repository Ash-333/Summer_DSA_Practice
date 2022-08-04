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

vector<int> postOrder(Node* root){
    vector<int> arr;
    stack<Node*> s1;
    stack<Node*> s2;

    s1.push(root);

    while(!s1.empty()){
        root=s1.top();
        s1.pop();
        s2.push(root);

        if(root->left!=NULL){
            s1.push(root->left)
        }

        if(root->right!=NULL){
            s1.push(root->right);
        }
    }
    while (!s2.empty()){
       arr.push_back(s2.top()->data);
       s.pop();
    }
    return arr;    
}

int main(){

}