#include<iostream>
#include<stack>
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

void preOrder(Node* root){
    stack<Node*> s;

    s.push(root);
    while(!stack.empty()){
        Node* temp=s.top();
        s.pop();
        cout<<temp->data;

        if(root->left){
            s.push(root->left);
        }

        if(root->right){
            s.push(root->right);
        }
    }
}

int main(){

}