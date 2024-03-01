// for non connected vertices also


#include<iostream>
using namespace std;

bool hasPath2(int ** edges,int vertices,bool * visited,int startIndex,int v1,int v2){
    
    if(startIndex == v2) return true;
//    cout<<startIndex<<" ";
    visited[startIndex] = true;
    for(int i=0;i<vertices;++i){
        if(edges[startIndex][i] == 1 && visited[i] == false){
            bool temp = hasPath2(edges,vertices,visited,i,v1,v2);
            if(temp == true) return true;
        }
    }
    return false;
}

bool hasPath(int ** edges,int vertices,int v1,int v2){
    bool * visited = new bool[vertices];
    for(int i=0;i<vertices;++i){
        visited[i] = false;
    }
    //we have to start search from v1 and check by dst non connected graph
    return hasPath2(edges,vertices,visited,v1,v1,v2);
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
    int v1;
    int v2;
    cout<<"enter the vertex 1 : ";
    cin>>v1;
    cout<<"enter the vertex 2 : ";
    cin>>v2;
    cout<<"Has path : "<<hasPath(edges,vertices,v1,v2)<<endl;
}


