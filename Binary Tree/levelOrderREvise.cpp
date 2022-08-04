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
        cin>>c1>>c2;
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

void preOrderTraverse(Node* root){
    if(root==NULL){
        return;
    }

    preOrderTraverse(root->left);
    cout<<root->data;
    preOrderTraverse(root->right);
}

int height(Node* root){
    if(root==NULL){
        return 0;
    }

    int h1=height(root->left);
    int h2=height(root->right);
    return 1+max(h1,h2);
}

int diameter(Node* root){
    if(root==NULL){
        return 0;
    }

    int D1=height(root->left)+height(root->right);
    int D2=height(root->left);
    int D3=height(root->right);
    return max(D1,max(D2,D3));
}


//Optimised diameterCode

int heightOt(Node* root,int &diameter){
    if(root==NULL){
        return 0;
    }

    int lh=heightOt(root->left,diameter);
    int rh=heightOt(root->right,diameter);

    diameter=max(diameter,lh+rh);
    return 1+max(lh,rh);
}

int diameterOt(Node* root){
    if(root==NULL){
        return 0;
    }

    int diameter=0;
    heightOt(root,diameter);
    return diameter;
}


int main(){
    Node* root=levelOrderBuild();
    cout<<"Diameter of tree is"<<diameterOt(root)<<endl;
    preOrderTraverse(root);
    cout<<endl;

    
}
