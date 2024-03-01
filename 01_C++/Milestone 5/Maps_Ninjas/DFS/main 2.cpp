//DFS : Depth First Search go to depth in one direction until path got disconnected ans then return and go to next path

#include<iostream>
using namespace std;

void printdfs(int ** edges,int vertices,bool * visited,int startIndex){
    if(vertices == 0) return;
    cout<<startIndex<<" ";
    visited[startIndex] = true;
    for(int i=0;i<vertices;++i){
        if(edges[startIndex][i] == 1 && visited[i] == false){
            printdfs(edges,vertices,visited,i);
        }
    }
    return;
}

void printDFS(int ** edges,int vertices){
    bool * visited = new bool[vertices];
    for(int i=0;i<vertices;++i){
        visited[i] = false;
    }
    printdfs(edges,vertices,visited,0);
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
    
    
    printDFS(edges,vertices);
}


