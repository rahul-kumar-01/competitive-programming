#include<iostream>
#include<queue>
using namespace std;

void printbfs(int ** edges,int vertices,bool * visited,int startIndex){
    if(vertices == 0) return;
    queue<int> pendingNodes;
    pendingNodes.push(startIndex);
    visited[startIndex] = true;
    
    
    while(!pendingNodes.empty()){
        int front = pendingNodes.front();
        pendingNodes.pop();
        cout<<front<<" ";
        for(int i=0;i<vertices;++i){
            if(edges[front][i] == 1 && visited[i] == false){
                pendingNodes.push(i);
                visited[i] = true;
            }
        }
    }
    return;
}


void printBFS(int ** edges,int vertices){
    bool * visited = new bool[vertices];
    for(int i=0;i<vertices;++i){
        visited[i] = false;
    }
    printbfs(edges,vertices,visited,0);
}



int main(){
    
    int vertices;
    int noOfEdges;
    cout<<"enter the vertices : ";
    cin>>vertices;
    cout<<"enter the no of edge : ";
    cin>>noOfEdges;
    
    int ** edges = new int*[vertices];
    for(int i=0;i<vertices;++i){
        edges[i] = new int[vertices];
        for(int j =0;j<vertices;++j){
            edges[i][j] = 0;
        }
    }
    
    int firstEdges,secondEdges;
    for(int i=0;i<noOfEdges;++i){
        cin>>firstEdges>>secondEdges;
        edges[firstEdges][secondEdges] = 1;
        edges[secondEdges][firstEdges] = 1;
    }
    
    
    printBFS(edges,vertices);
    

}
