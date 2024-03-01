#include<iostream>
using namespace std;

bool helper(int ** edges,int si,int parent,bool * visited,int v){
    visited[si] = true;
    for(int i=0;i<v;++i){
        if(edges[si][i] == 1){
            if(visited[i] && parent != i) return true;
            else if(visited[i] && parent == i) continue;
            else if(helper(edges,i,si,visited,v)) return true;
        }
    }
    return false;
}



bool detectCycle(int ** edges,int v){
    bool * visited = new bool [v];
    for(int i=0;i<v;++i) visited[i] = false;
    for(int i=0;i<v;++i){
        if(!visited[i]){
            if(helper(edges,i,-1,visited,v)) return true;
        }
    }
    return false;
}


int main(){
    int t;
    cin>>t;
    while(t--){
        int v,e;
        cin>>v>>e;
        int ** edges = new int*[v];
        for(int i=0;i<v;++i){
            edges[i] = new int[v];
            for(int j=0;j<v;++j){
                edges[i][j] = 0;
            }
        }
        for(int i=0;i<e;++i){
            int v1,v2;
            cin>>v1>>v2;
            edges[v1-1][v2-1] = 1;
            edges[v2-1][v1-1] = 1;
        }
        cout<<boolalpha<<detectCycle(edges,v);
    }
}

