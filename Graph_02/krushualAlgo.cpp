#include<iostream>
#include<vector>
using namespace std;

class Edge{
public:
    int v1;
    int v2;
    int weight;
    Edge(int v1,int v2,int weight){
        this->v1 = v1;
        this->v2 = v2;
        this->weight = weight;
    }
};

bool cmp(Edge a , Edge b){
    return a.weight < b.weight;
}

bool select(Edge edge,vector<int>&parent){
    int v1 = edge.v1;
    int v2 = edge.v2;
    int weight = edge.weight;
    while(parent[v1] != v1) v1 = parent[v1];
    while(parent[v2] != v2) v2 = parent[v2];
    if(v1 == v2) return false;
    parent[v1] = v2;
    return true;
}

vector<Edge> krushualAlgo(vector<Edge>edges,int v,vector<int>&parent){
    vector<Edge>output;
    for(int i=0;i<edges.size() && output.size() < v-1;++i){
        bool ans = select(edges[i],parent);
        if(ans){
            output.push_back(edges[i]);
        }
    }
    return output;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int v,e;
        cin>>v>>e;
        vector<Edge>edges;
        vector<int>parent;
        for(int i=0;i<v;++i) parent.push_back(i);
        for(int i=0;i<e;++i){
            int v1,v2,weight;
            cin>>v1>>v2>>weight;
            edges.push_back(Edge(v1,v2,weight));
        }
        sort(edges.begin(),edges.end(),cmp);
        vector<Edge> mst = krushualAlgo(edges,v,parent);
        int totolWeight = 0;
        for(int i=0;i<mst.size();++i){
            cout<<mst[i].v1<<" "<<mst[i].v2<<" "<<mst[i].weight<<endl;
            totolWeight += mst[i].weight;
        }
        cout<<totolWeight<<endl;
    }
}