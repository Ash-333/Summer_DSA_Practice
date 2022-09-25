#include<iostream>
#include<list>
#include<stack>
using namespace std;

class Graph{
public:
    int V;
    list<int> *l;

    Graph(int v){
        V=v;
        l=new list<int>[V];
    }

    void addEdge(int i,int j,bool undir=true){
        l[i].push_back(j);
        if(undir){
            l[j].push_back(i);
        }
    }

    void dfsHelper(int s,bool *visited){
        visited[s]=true;
        cout<<s<<",";

        for(int nbr:l[s]){
            if(!visited[nbr]){
                dfsHelper(nbr,visited);
            }
        }
    }

    void dfs(int source){
        bool *visited=new bool[V]{0};
        dfsHelper(source,visited);

    }
};

int main(){
    Graph g(7);
    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(2,3);
    g.addEdge(3,5);
    g.addEdge(5,6);
    g.addEdge(4,5);
    g.addEdge(0,4);
    g.addEdge(3,4);

    g.dfs(0);
}