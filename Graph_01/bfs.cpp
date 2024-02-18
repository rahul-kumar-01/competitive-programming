#include<iostream>
#include<queue>
using namespace std;


void helper(int ** edges,int v,bool * visited , queue<int>levelOrderVertices,int si){
    levelOrderVertices.push(si);
    visited[si] = true;
    while(!levelOrderVertices.empty()){
        int front = levelOrderVertices.front();
        levelOrderVertices.pop();
        cout<<front<<" ";
        for(int i=0;i<v;++i){
            if(!visited[i] && edges[front][i] == 1) {
                levelOrderVertices.push(i);
                visited[i] = true;
            }
        }
    }
}


void printBfs(int ** edges,int v){
    bool * visited = new bool [v];
    for(int i=0;i<v;++i) visited[i] = false;
    queue<int>levelOrderVertices;
    for(int si = 0; si < v; ++si){
        if(!visited[si]) helper(edges,v,visited,levelOrderVertices,si);
    }
}

int main(){
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
    printBfs(edges,v);
}