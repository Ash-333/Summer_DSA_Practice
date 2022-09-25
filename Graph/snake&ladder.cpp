#include<iostream>
#include<list>
#include<queue>
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
    int minCostBFS(int source,int dest){
        queue<int> q;
        bool *visited=new bool[V]{0};
        int *dist=new int[V]{0};

        q.push(source);
        visited[source]=true;
        dist[source]=0;
                
        while(!q.empty()){
            int f=q.front();
            q.pop();

            for(auto nbr:l[f]){
                if(!visited[nbr]){
                    q.push(nbr);
                    visited[nbr]=true;
                    dist[nbr]=dist[f]+1;
                    
                }
            }
        }
        return dist[dest];

    }
};

int min_dice_throws(int n,vector<pair<int,int> > snakes, vector<pair<int,int> > ladders){
    vector<int> board(n+1,0);
    
    //value of snakes
    for(auto sp:snakes){
        int s=sp.first;
        int e=sp.second;
        board[s]=e-s;
    }

    //values of ladders
    for(auto ld:ladders){
        int s=ld.first;
        int e=ld.second;
        board[s]=e-s;
    }

    Graph g(n+1);

    for(int u=1;u<n;u++){
        for(int dice=1;dice<=6;dice++){
            int value=u+dice;
            value+=board[value];
            if(value<=n){
                g.addEdge(u,value);
            }
        }

    }
    g.minCostBFS(1,n);
}