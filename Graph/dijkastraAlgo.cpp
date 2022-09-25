/*** Cycle dtection in undirected grph using DSF***/
#include<iostream>
#include<list>
#include<set>
#include<vector>
using namespace std;

class Graph{
public:
    int V;
    list<pair<int,int>> *l;

    Graph(int v){
        V=v;
        l=new list<pair<int,int>>[V];
    }

    void addEdge(int i,int j,int wt,bool undir=true){
        l[i].push_back({wt,j});

        if(undir){
            l[j].push_back({wt,i});
        }
    }

    int dijkstra(int source,int dest){
        vector<int> dist(V,INT_MAX);
        set<pair<int,int>> s;
        dist[source]=0;
        s.insert({0,source});

        while(!s.empty()){
            auto it=s.begin();
            int node=it->first;
            int currentDist=it->second;
            s.erase(it);

            for(auto nbrPair:l[node]){
                int nbr=nbrPair.second;
                int currentEdge=nbrPair.first;

                if(currentEdge+currentDist<dist[nbr]){

                    auto f=s.find({dist[nbr],nbr});
                    if(f!=s.end()){
                        s.erase(f);
                    }
                    

                    dist[nbr]=currentEdge+currentDist;
                    s.insert({dist[nbr],nbr});
                }
            }
        }

        for(int i=0;i<V;i++){
            cout<<"Node "<<i<<" Dist "<<dist[i]<<endl;
        }
        return dist[dest];
    }
};

int main(){

    Graph g(6);
	g.addEdge(0,1,1);
	g.addEdge(1,2,1);
	g.addEdge(0,2,4);
	g.addEdge(0,3,7);
	g.addEdge(3,2,2);
	g.addEdge(3,4,3);

	cout << g.dijkstra(0,3)<<endl;

}