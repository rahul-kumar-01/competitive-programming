#include<iostream>
#include<vector>
#include<climits>
using namespace std;

class Edge{
    public:
    int v1;
    int v2;
    int weight;
};

void bellmanFord(int n,int e,Edge** edges){
    int * dist = new int[n];
    for(int i=0;i<n;++i) dist[i] = INT_MAX;
    dist[0] = 0;
    for(int i=0;i<n-1;i++){
        for(int j=0;j<e;j++){
            int u = edges[j]->v1;
            int v= edges[j]->v2;
            int w = edges[j]->weight;

            if(dist[u] != INT_MAX && (dist[v] > dist[u]+w)){
                dist[v] = dist[u] + w;
            }
        }
    }
    for(int i=0;i<n;++i){
        cout<<dist[i]<<endl;
    }
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,e;
        cin>>n>>e;
        Edge ** edges = new Edge*[n];
        for(int i=0;i<e;++i){
            edges[i] = new Edge();
            cin>>edges[i]->v1>>edges[i]->v2>>edges[i]->weight;
        }
        bellmanFord(n,e,edges);
    }
    
    return 0;
}