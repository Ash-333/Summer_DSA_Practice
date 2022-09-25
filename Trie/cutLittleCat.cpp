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
};

void search(Trie t,string document,int i,unordered_map<string,bool> &mp){
    Node* temp=t.root;

    for(int j=i;j<document.length();j++){
        char ch=document[j];

        if(temp->m.count(ch)==0){
            return;
        }
        temp=temp->m[ch];
        
        if(temp->isTerminal){
            string out=document.substr(i,j-i+1);
            cout<<out<<" ";
            mp[out]=true;
        }
        
    }
    cout<<endl;
}

void documentSearch(string document,vector<string> words){
    Trie t;

    for(auto str:words){
        t.insert(str);
    }

    unordered_map<string,bool> mp;
    for(int i=0;i<document.length();i++){
        search(t,document,i,mp);
    }        

    for(auto str:words){
        if(mp[str]){
            cout<<str<<" : true"<<endl;
        }
        else{
            cout<<str<<" : false"<<endl;
        }
    }
}

int main(){
    string document="little cute cat loves to code in c++, java & python";
    vector<string> words{"cute cat","ttle","cat","quick","big"};
    documentSearch(document,words);
}