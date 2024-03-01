#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

void dikstraAlgo(int ** edges,int v){
    vector<bool>visited(v,false);
    vector<int>weight(v,INT_MAX);
    weight[0] = 0;
    int count = 0;
    while(count < v){
        int minIndex = -1;
        for(int i=0;i<v;++i){
            if(!visited[i]){
                if(minIndex == -1) minIndex = i;
                else if(weight[minIndex] > weight[i]) minIndex = i;
            }
        }
        visited[minIndex] = true;
        ++count;
        for(int i=0;i<v;++i){
            if(!visited[i] && edges[minIndex][i] != 0){
                weight[i] = min(weight[i],weight[minIndex]+edges[minIndex][i]);
            }   
        }
    }
    for(int i=0;i<v;++i){
        cout<<i<<" "<<weight[i]<<endl;
    }
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int v,e;
        cin>>v>>e;
        int** edges = new int*[v];
        for(int i=0;i<v;++i){
            edges[i] = new int[v];
            for(int j=0;j<v;++j){
                edges[i][j] = 0;
            }
        }

        for(int i=0;i<e;++i){
            int v1,v2,w;
            cin>>v1>>v2>>w;
            edges[v1][v2] = w;
            edges[v2][v1] = w;
        }
        dikstraAlgo(edges,v);
    }
}