#include<iostream>
using namespace std;

void helper(int ** edges, int v,int si,bool * visited){
    cout<<si<<" ";
    visited[si] = true;
    for(int i=0;i<v;++i){
        if(!visited[i] && edges[si][i] == 1){
            helper(edges,v,i,visited);
        }
    }
}


void printDfs(int ** edges,int v){
    bool * visited = new bool [v];
    for(int i=0;i<v;++i) visited[i] = false;
    for(int i=0;i<v;++i){
        if(!visited[i]) helper(edges,v,i,visited);
    }
}

int main(){
    int v,e;
    cin>>v>>e;
    int ** edges = new int*[v];
    for(int i=0;i<v;++i){
        edges[i] = new int [v];
        for(int j=0;j<v;++j){
            edges[i][j] = 0;
        }
    }
    for(int i=0;i<e;++i){
        int f,s;
        cin>>f>>s;
        edges[f][s] = 1;
        edges[s][f] = 1;
    }
    printDfs(edges,v);
}