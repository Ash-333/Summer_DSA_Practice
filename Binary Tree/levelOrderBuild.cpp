#include<iostream>
#include<queue>
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


Node* levelOrderBuild(){
    int d,c1,c2;
    cin>>d;

    Node* root=new Node(d);
    queue<Node*> q;
    q.push(root);

    while(!q.empty()){
        Node* current=q.front();
        q.pop();

        cin >>c1>>c2;

        if(c1!=-1){
            current->left=new Node(c1);
            q.push(current->left);
        }

        if(c2!=-1){
            current->right=new Node(c2);
            q.push(current->right);
        }
    }
    return root;    
}

void levelOrderPrint(Node* root){
    queue<Node*> q;

    q.push(root);

    while(!q.empty()){
        Node* temp=q.front();
        q.pop();
        cout<<temp->data;

        if(temp->left){
            q.push(temp->left);
        }
        if(temp->right){
            q.push(temp->right);
        }
    }
}

int main(){

    Node* root=levelOrderBuild();
    levelOrderPrint(root);

}