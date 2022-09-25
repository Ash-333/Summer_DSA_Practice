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
        l=new list<int>[V];
    }

    void insertEdge(int i,int j,bool undir=true){
        l[i].push_back(j);
        if(undir){
            l[j].push_back(i);
        }
    }

    void bsf(int source){
        queue<int> q;
        bool *visited=new bool[V]{0};
        int *dist=new int[V]{0};
        int *parent=new int[V];

        for(int i=0;i<V;i++){
            parent[i]=-1;
        }

        q.push(source);
        dist[source]=0;
        visited[source]=true;
        parent[source]=source;

        while(!q.empty()){
            int f=q.front();
            cout<<f<<" ";
            q.pop();

            for(auto nbr:l[f]){
                if(!visited[nbr]){
                    q.push(nbr);
                    parent[nbr]=f;
                    dist[nbr]=dist[f]+1;
                    visited[nbr]=true;

                }
            }
        }
    }

}