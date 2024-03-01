#include<iostream>
#include<queue>
using namespace std;

vector<int> getPathFromSi(int ** edges,int v,int si,bool* visited,queue<int>pendingNodes){
    vector<int>ans;
    pendingNodes.push(si);
    visited[si] = true;
    while(!pendingNodes.empty()){
        int front = pendingNodes.front();
        pendingNodes.pop();
        ans.push_back(front);
        for(int i=0;i<v;++i){
            if(!visited[i] && edges[front][i] == 1){
                pendingNodes.push(i);
                visited[i] = true;
            }
        }
    }
    return ans;
}


vector< vector<int> > connectedComponentPaths (int ** edges,int v){
    vector< vector<int> > connectedPaths;
    queue<int>pendingNodes;
    bool * visited = new bool[v+1];
    for(int i=0;i<=v;++i) visited[i] = false;
    for(int i=1;i<=v;++i){
        if(!visited[i]){
            vector<int>path = getPathFromSi(edges,v,i,visited,pendingNodes);      
            connectedPaths.push_back(path); 
        }
    }
    return connectedPaths;
}

int main(){
    int t,v,e;
    cin>>t;
    while(t--){
        cin>>v>>e;
        int ** edges = new int* [v+1];
        for(int i=0;i<=v;++i){
            edges[i] = new int[v+1];
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
        vector< vector<int> > connectedComponent = connectedComponentPaths(edges,v);
        for(int i=0;i<connectedComponent.size();++i){
            sort(connectedComponent[i].begin(),connectedComponent[i].end());
            for(int j=0;j<connectedComponent[i].size();++j){
                cout<<connectedComponent[i][j]<<" ";
            }
            cout<<endl;
        }
    }
}