#include<iostream>
using namespace std;


void helper(int ** edges,int vertices,bool*visited, int startIndex){
    for(int i=0;i<vertices;++i){
        if(edges[startIndex][i] == 1 && !visited[i]){
            visited[i] = true;
            helper(edges,vertices,visited,i);
        }
    }
    return;
}

int noOfIsland(int ** edges,int vertices){
    bool * visited = new bool[vertices];
    for(int i=0;i<vertices;++i){
        visited[i] = false;
    }
    int count = 0;
    for(int i=0;i<vertices && !visited[i] ;++i){
        visited[i] = true;
        helper(edges,vertices,visited,i);
        ++count;
    }
    return count;
}


int main(){
    int noOfEdges;
    int vertices;
    cout<<"enter the no of vertices : ";
    cin>>vertices;
    cout<<"enter no of edges : ";
    cin>>noOfEdges;
    int ** edges = new int* [vertices];
    for(int i=0;i<vertices;++i){
        edges[i] = new int[vertices];
        for(int j=0;j<vertices;++j){
            edges[i][j] = 0;
        }
    }
    int firstEdge;
    int secondEdge;
    for(int i=0;i<noOfEdges;++i){
        cout<<"1st Edges : ";
        cin>>firstEdge;
        cout<<"2nd Edges : ";
        cin>>secondEdge;
        edges[firstEdge][secondEdge] = 1;
        edges[secondEdge][firstEdge] = 1;
    }
    cout<<noOfIsland(edges,vertices)<<endl;
}



