#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

class Node{
    char data;
    public:
    unordered_map<char,Node*> m;
    bool isTerminal;

    Node(char d){
        data=d;
        isTerminal=false;
    }
};


class Trie{
    public:
    Node* root;

    Trie(){
        root=new Node('\0');
    }

    void insert(string word){
        Node* temp=root;

        for(char c:word){
            if(temp->m.count(c)==0){
                Node* n=new Node(c);
                temp->m[c]=n;
            }
            temp=temp->m[c];
        }
        temp->isTerminal=true;
    }

    bool search(string word){
        Node* temp=root;

        for(char ch:word){
            if(temp->m.count(ch)==0){
                return false;
            }
            temp=temp->m[ch];
        }
        return temp->isTerminal;
    }
};

int main(){
    vector<string> word{"apple","mango","orange","banana","peach","coconut"};
    Trie t;
    for(auto s:word){
        t.insert(s);
    }

    string srch;
    int q;
    cin>>q;

    while(q--){
        cin>>srch;
        bool s=t.search(srch);

        if(s){
            cout<<"yes"<<endl;
        }
        else{
            cout<<"no"<<endl;
        }
    }

}