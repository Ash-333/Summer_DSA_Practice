/*** Cycle dtection in undirected grph using BSF***/
#include<iostream>
#include<list>
#include<queue>
#include<vector>
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

    bool detect(int source,vector<bool> &visited){
        queue<pair<int,int>> q;

        q.push({source,-1});
        visited[source]=true;

        while(!q.empty()){
            int node=q.front().first;
            int parent=q.front().second;

            for(int nbr:l[node]){
                if(!visited[nbr]){
                    q.push({nbr,node});
                    visited[nbr]=true;
                }
                else if(parent!=nbr){
                    return true;
                }
            }
        }
        return false;
    }

    bool detectCycle(int source){
        vector<bool> visited(V,0);

        return detect(source,visited);
    }
};

int main(){
    Graph g(3);
    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(2,0);

    if(g.detectCycle(0)){
        cout<<"contains loop";
    }
    else{
        cout<<"No loop present";
    }

    return 0;
}