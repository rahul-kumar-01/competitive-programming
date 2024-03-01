//check each vertex is connected to each other


#include<iostream>
#include<queue>
using namespace std;


bool helper(int ** edges,int vertices,bool * visited,int startIndex){
    if(vertices == 0) return true;
    int count = 0;
    queue<int> pendingNodes;
    pendingNodes.push(startIndex);
    ++count;
    visited[startIndex] = true;
    
    
    while(!pendingNodes.empty()){
        int front = pendingNodes.front();
        pendingNodes.pop();
        for(int i=0;i<vertices;++i){
            if(edges[front][i] == 1 && visited[i] == false){
                pendingNodes.push(i);
                ++count;
                visited[i] = true;
            }
        }
    }
    return(count == vertices);
}


bool isConnected(int ** edges,int vertices){
    bool * visited = new bool[vertices];
    for(int i=0;i<vertices;++i){
        visited[i] = false;
    }
    return helper(edges,vertices,visited,0);
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
    if(isConnected(edges,vertices)){
        cout<<"true"<<endl;
    }
    else{
        cout<<"false"<<endl;
    }
}



