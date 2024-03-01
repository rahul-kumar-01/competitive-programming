#include<iostream>
using namespace std;

void helper(int ** edges,int v,bool*visited,int si){
    visited[si] = true;
    for(int i=0;i<v;++i){
        if(!visited[i] && edges[si][i] == 1){
            helper(edges,v,visited,i);
        }
    }
}

bool isConnected(int ** edges,int v){
    bool * visited = new bool[v];
    for(int i=0;i<v;++i) visited[i] = false;
    helper(edges,v,visited,0);
    for(int i=0;i<v;++i) {
        if(visited[i] == false) return false;
    }
    return true;
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
            int f,s;
            cin>>f>>s;
            edges[f][s] = 1;
            edges[s][f] = 1;
        }
        cout<<boolalpha<<isConnected(edges,v);
    }
}