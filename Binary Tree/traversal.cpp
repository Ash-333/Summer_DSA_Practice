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

//Preorder Traversal

void preorderTraversal(Node* root){
    if(root==NULL){
        return;
    }

    cout<<root->data;
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}


void inorderTraversal(Node* root){
    if(root==NULL){
        return;
    }

    inorderTraversal(root->left);
    cout<<root->data;
    inorderTraversal(root->right);
}

void postorderTraversal(Node* root){
    if(root==NULL){
        return;
    }

    postorderTraversal(root->left);
    postorderTraversal(root->right);
    cout<<root->data;
}

Node* bulidTree(){
    
    int a;
    cin>>a;

    if(a==-1){
        return NULL;
    }

        Node* n=new Node(a);
        n->left=bulidTree();
        n->right=bulidTree();
    
    return n;
}

void leveOrder(Node* root){
    queue<Node*> q;
    vector<int> v;
    q.push(root);

    while(!q.empty()){
        Node* temp=q.front();

        if(temp!=NULL){
        q.pop();
        cout<<temp->data;
        }

        if(temp->left){
            q.push(temp->left);
        }
        if(temp->right){
            q.push(temp->right);
        }
        
    }

}

int main(){
    Node* root=bulidTree();
    //preorderTraversal(root);
    leveOrder(root);

}