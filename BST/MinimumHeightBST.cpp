#include<iostream>
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

Node* treeCreation(vector<int> a,int s,int e){

    if(s>e){
        return NULL;
    }

    int mid=(s+e)/2;

    Node* root=new Node(a[mid]);
    root->left=treeCreation(a,s,mid-1);
    root->right=treeCreation(a,mid+1,e);

    return root;
}

void print(Node* root){
    if(root==NULL){
        return;
    }

    cout<<root->data;
    print(root->left);
    print(root->right);
}

int isClosest(Node* root,int k){
    int close;
    int diff=INT_MAX;
    Node* temp=root;

    while(temp!=NULL){
        int current_diff=abs(temp->data-k);

        if(current_diff==0){
            return temp->data;
        }
        
        if(current_diff<diff){
            diff=current_diff;
            close=temp->data;
        }

        if(temp->data>k){
            temp=temp->right;
        }
        else{
            temp=temp->left;
        }
    }

    return close;
}

int main(){
    vector<int> arr={1,2,3,4,5,6,7,8};
    int e=arr.size();
    Node* root=treeCreation(arr,0,e);
    cout<<isClosest(root,9);
}