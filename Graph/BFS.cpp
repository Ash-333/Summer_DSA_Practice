#include<iostream>
#include<list>
#include<queue>
using namespace std;

class Graph{
public:
    list<int> *l;
    int V;

    Graph(int v){
        V=v;
        l=new list<int>[v];
    }

    void addEdge(int i,int j,bool undir=true){
        l[i].push_back(j);
        if(undir){
            l[j].push_back(i);
        }
    }

    void bfs(int source){
        queue<int> q;
        bool *visited=new bool[V]{0};

        q.push(source);
        visited[source]=true;
        
        while(!q.empty()){
            int f=q.front();
            cout<<f<<" ";
            q.pop();

            for(auto nbr:l[f]){
                if(!visited[nbr]){
                    q.push(nbr);
                    visited[nbr]=true;
                }
            }
        }

    }

};

int main(){
    Graph g(6);
    g.addEdge(0,1);
    g.addEdge(0,4);
    g.addEdge(2,1);
    g.addEdge(3,4);
    g.addEdge(4,5);
    g.addEdge(2,3);
    g.addEdge(3,5);
    g.bfs(0);
}