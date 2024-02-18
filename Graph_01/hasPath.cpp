#include<iostream>
using namespace std;

bool helper(int ** edges, int v,int si,int ei,bool * visited){
    if(si == ei) return true;
    visited[si] = true;
    for(int i=0;i<v;++i){
        if(!visited[i] && edges[si][i] == 1){
            bool ans = helper(edges,v,i,ei,visited);
            if(ans) return true;
        }
    }
    return false;
}


bool hasPath(int ** edges,int v,int si,int ei){
    bool * visited = new bool [v];
    for(int i=0;i<v;++i) visited[i] = false;
    return helper(edges,v,si,ei,visited);
}

int main(){
    int t ; 
    cin>>t;
    while(t--){
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
        int si,ei; 
        cin>>si>>ei;
        bool ans = hasPath(edges,v,si,ei);
        cout<<boolalpha<<ans<<endl;
    } 
}