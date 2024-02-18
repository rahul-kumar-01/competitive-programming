#include<iostream>
#include<vector>
using namespace std;

vector<int> helper(int ** edges,int v,int si,int ei,bool * visited){
    visited[si] = true;
    vector<int>path;
    if(si == ei) {
        path.push_back(si);
        return path;
    }
    for(int i=0;i<v;++i){
        if(!visited[i] && edges[si][i] == 1) {
            vector<int>path = helper(edges,v,i,ei,visited);
            if(!path.empty()) {
                path.push_back(si);
                return path;
            }
        }
    }
    return path;
}


vector<int> getPathDfs(int ** edges,int v,int si,int ei){
    bool * visited = new bool[v];
    for(int i=0;i<v;++i) visited[i] = false;
    return helper(edges,v,si,ei,visited);
}

int main(){
    int t,v,e;
    cin>>t;
    while(t--){
        cin>>v>>e;
        int ** edges = new int * [v];
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
        vector<int>path = getPathDfs(edges,v,si,ei);
        for(int i=0;i<path.size();++i) cout<<path[i]<<" ";
        cout<<endl;
    }
}