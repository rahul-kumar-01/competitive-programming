#include<iostream>
#include<climits>
#include<vector>
#include<algorithm>

using namespace std;

int prismAlgo(int ** edges,int v,int si){
    vector<bool>visited(v,false); 
    vector<int>parent(v,-1);
    vector<int>weight (v,INT_MAX);
    weight[si] = 0;
    int visitedElement = 0;
    while(visitedElement < v-1){
        int currentIndex = -1;
        for(int i=0;i<v ;++i){
            if(!visited[i]){
                if(currentIndex == -1) currentIndex = i;
                else if(weight[currentIndex] > weight[i]) currentIndex = i;
            }
        }
        visited[currentIndex] = true;
        ++visitedElement;
        for(int i=0;i<v;++i){
            if(!visited[i] && edges[currentIndex][i] != 0 ){
                weight[i] = min(weight[i],edges[currentIndex][i]);
            }
        }
    }
    int minWeight = 0;
    for(int i=0;i<v;++i) minWeight += weight[i];
    return minWeight;
}



int main(){
    int t; cin>>t;

    while(t--){
        int v,e; cin>>v>>e;
        int ** edges = new int*[v];
        for(int i=0;i<v;++i){
            edges[i] = new int[v];
            for(int j=0;j<v;++j){
                edges[i][j] = INT_MAX;
            }
        }
        for(int i=0;i<e;++i){
            int v1,v2,w;
            cin>>v1>>v2>>w;
            edges[v1][v2] = min(w,edges[v1][v2]);
            edges[v2][v1] = min(w,edges[v2][v1]);
        }
        cout<<prismAlgo(edges,v,0)<<endl;
    }
}