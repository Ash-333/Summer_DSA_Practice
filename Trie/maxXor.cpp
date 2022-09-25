#include<iostream>
#include<vector>
using namespace std;

class Node{
    public:
    Node* left;
    Node* right;
};

class Trie{
    Node* root;
    public:

    Trie(){
        root=new Node();
    }
    
    void insert(int value){
        Node *temp=root;

        for(int i=31;i>=0;i--){
            int bit=(value>>i)&1;

            if(bit==0){
                if(temp->left==NULL){
                    temp->left=new Node();
                }
                
                    temp=temp->left;
            }

            else{
                if(temp->right==NULL){
                    temp->right=new Node();
                }
                temp=temp->right;
            }
        }
    }

    int maxXor_helper(int value){
        int currentAns=0;
        Node* temp=root;

        for(int i=31;i>=0;i--){
            int bit=(value>>i)&1;

            if(bit==0){
                if(temp->right!=NULL){
                    temp=temp->right;
                    currentAns+=(1<<i);
                }
                else{
                    temp=temp->left;
                }
            }

            else{
                if(temp->left!=NULL){
                    temp=temp->left;
                    currentAns+=(1<<i);
                }
                else{
                    temp=temp->right;
                }
            }
        }

        return currentAns;
    }

    int max_xor(vector<int> ele){

        int ans=0;

        for(int i=0;i<ele.size();i++){
            int value=ele[i];

            insert(value);
            int currentXor=maxXor_helper(value);
            ans=max(ans,currentXor);
        }
        return ans;
    }

};

int main(){
    vector<int> arr{25, 10, 2, 8, 5, 3};
    Trie t;
    cout<<t.max_xor(arr);
}