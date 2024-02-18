#include<iostream>
#include<vector>
#include<queue>
using namespace std;

vector<int> helper(int ** edges,int v,int si,int ei,bool * visited,queue<int>levelOrderNodes){
    levelOrderNodes.push(si);
    visited[si] = true;
    while(!levelOrderNodes.empty()){
        int front = levelOrderNodes.front();
        levelOrderNodes.pop();
        for(int i=0;i<v;++i){
            if(!visited[i] && edges[si][i] == 1){
                levelOrderNodes.push(i);
                visited[i] = true;
            }
        }
    }
    while(levelOrderNodes.empty()){
        levelOrderNodes.pop();
    }
    return vector<int>{1,2,3};
}

vector<int> getPathBfs(int ** edges,int v,int si,int ei){
    bool * visited = new bool [v];
    for(int i=0;i<v;++i) visited[i] = false;
    queue<int>levelOrderNodes;
    return helper(edges,v,si,ei,visited,levelOrderNodes);
}


int main(){
    int t,v,e;
    cin>>t;
    while(t--){
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
        int si,ei;
        cin>>si>>ei;
        vector<int> path = getPathBfs(edges,v,si,ei);
        for(int i=0;i<path.size();++i){
            cout<<path[i]<<" ";
        }
        cout<<endl;
    }
}