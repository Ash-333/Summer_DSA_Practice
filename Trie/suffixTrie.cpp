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


class SuffixTrie{
    public:
    Node* root;

    SuffixTrie(){
        root=new Node('\0');
    }

    void insertHelper(string word){
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

    void insert(string word){
        for(int i=0;word[i]!='\0';i++){
            insertHelper(word.substr(i));
        }
        
    }
};

int main(){
    SuffixTrie t;
    string str="hello";
    t.insert(str);

    vector<string> s{"ello","loo","hello"};

    for(auto str:s){
        bool p=t.search(str);
        if(p){
            cout<<"yes";
        }
        else{
            cout<<"No";
        }
    }

}