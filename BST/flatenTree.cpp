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

Node* insert(Node* root,int d){
    if(root==NULL){
        return new Node(d);
    }

    if(d<root->data){
        root->left=insert(root->left,d);
    }

    if(d>root->data){
        root->right=insert(root->right,d);
    }
    return root;
}

void flattenData(Node* root){
    stack<Node*> st;
    if(root==NULL){
        return;
    }

    st.push(root);

    while(!st.empty()){
        Node* current=st.top();
        st.pop();

        if(current->right){
            st.push(current->right);
        }
        if(current->left){
            st.push(current->left);
        }
        if(!st.empty()){
            current->right=st.top();
        }
        current->left=NULL;

    }
}

int main(){
    vector<int> arr={1,2,3,4,5,6,7,8};
    Node* root=NULL;

    for(int i:arr){
        insert(root,i);
    }

    
}