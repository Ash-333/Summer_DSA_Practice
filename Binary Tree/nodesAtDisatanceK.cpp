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

void printAtLevelK(Node* root,int k){
    if(root==NULL){
        return;
    }

    if(k==0){
        cout<<root->data<<" ";
        return;
    }

    printAtLevelK(root->left,k-1);
    printAtLevelK(root->right,k-1);
    return;
}

void printNodeAtDistanceK(Node* root,Node* target,int k){
    if(root==NULL){
        return -1;
    }

    if(root==target){
        printAtLevelK(target,k);
    }

    int dl=printNodeAtDistanceK(root->left,target,k);
    if(dl!=-1){
        if(dl+1==k){
            cout<<root->data<<" ";
        }

        else{
            printAtLevelK(root->right,k-2-dl);
        }
        return 1+dl;
    }

    int dr=printNodeAtDistanceK(root->right,target,k);

    if(dr!=-1){
        if(dr+1==k){
            cout<<root->data<<" ";
        }

        else{
            printAtLevelK(root->left,k-2-dr);
        }

        return 1+dr;
    }
}

int main(){
    Node* root=new Node(1);
    root->left=new Node(2);
    root->right=new Node(3);
    root->left->left=new Node(4);
    root->left->right=new Node(5);
    root->right->left=new Node(6);
    root->right->right=new Node(7);

}