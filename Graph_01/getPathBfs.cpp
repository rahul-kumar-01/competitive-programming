#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
using namespace std;

vector<int> helper(int ** edges,int v,int si,int ei,bool * visited,queue<int>levelOrderNodes,unordered_map<int,int>pathMap){
    vector<int>bfsPathVector;
    levelOrderNodes.push(si);
    visited[si] = true;
    while(!levelOrderNodes.empty()){
        int front = levelOrderNodes.front();
        levelOrderNodes.pop();
        for(int i=0;i<v;++i){
            if(!visited[i] && edges[front][i] == 1){
                pathMap[i] = front;
                levelOrderNodes.push(i);
                visited[i] = true;
                if(i == ei){
                    bfsPathVector.push_back(ei);
                    while(ei != si){
                        bfsPathVector.push_back(pathMap[ei]);
                        ei = pathMap[ei];
                    }
                }
            }
        }
    }
    return bfsPathVector;
}

vector<int> getPathBfs(int ** edges,int v,int si,int ei){
    bool * visited = new bool [v];
    for(int i=0;i<v;++i) visited[i] = false;
    queue<int>levelOrderNodes;
    unordered_map<int,int> pathMap;
    return helper(edges,v,si,ei,visited,levelOrderNodes, pathMap);
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