/*** Cycle dtection in undirected grph using DSF***/
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

    void addEdge(int i,int j){
        l[i].push_back(j);

        l[j].push_back(i);

    }

    bool dfsHelper(int s,bool *visited,int parent){
        visited[s]=true;
        

        for(int nbr:l[s]){
            if(!visited[nbr]){
                bool containsCycle=dfsHelper(nbr,visited,s);
                if(containsCycle){
                    return true;
                }
            }

            else if(nbr!=parent){
                return true;
            }
        }
        return false;
    }

    bool containsLoop(int source){
        bool *visited=new bool[V]{0};
        return dfsHelper(source,visited,-1);

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