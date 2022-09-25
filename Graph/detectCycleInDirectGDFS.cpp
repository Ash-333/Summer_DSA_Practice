/*** Cycle dtection in directed grph using DSF***/
#include<iostream>
#include<list>
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

    void addEdge(int i,int j){
        l[i].push_back(j);

    }

    bool dfs(int s,vector<bool> &visited,vector<bool> &stack){
        visited[s]=true;
        stack[s]=true;

        for(int nbr:l[s]){
            if(stack[nbr]==true){
                return true;
            }
            else if(visited[nbr]==false){
                bool foundCycle=dfs(nbr,visited,stack);
                if(foundCycle){
                    return true;
                }
            }
        }

        stack[s]=false;
        return false;

        return false;
    }

    bool containsLoop(int source){
       vector<bool> visited(V,0);
       vector<bool> stack(V,0);

       for(int i=0;i<V;i++){
            int source=i;
            if(!visited[source]){
                if(dfs(source,visited,stack)){
                    return true;
                }
            }
       }
       return false;

    }
};

int main(){
    Graph g(3);
    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(2,0);

    if(g.containsLoop(0)){
        cout<<"contains loop";
    }
    else{
        cout<<"No loop present";
    }
}