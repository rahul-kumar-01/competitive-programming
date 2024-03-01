#include<iostream>
#include<vector>
#include<queue>
using namespace std;

vector<int> * getPathDFS_2(int ** edges,int vertices,bool * visited,int v1,int v2){
    
    if(v1 == v2) {
        vector<int>*v = new vector<int>();
        v->push_back(v1);
        return v;
    }
    
    visited[v1] = true;
    for(int i=0;i<vertices;++i){
        if(edges[v1][i] == 1 && visited[i] == false){
            vector<int> *v = getPathDFS_2(edges,vertices,visited,i,v2);
            if(v!=NULL){
                v->push_back(v1);
                return v;
            }
        }
    }
    return NULL;
}


vector<int>* getPathDFS(int ** edges,int vertices,int v1,int v2){
    bool * visited = new bool[vertices];
    for(int i=0;i<vertices;++i){
        visited[i] = false;
    }
    return getPathDFS_2(edges,vertices,visited,v1,v2);
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
    
    int v1,v2;
    cout<<"enter the v1 : ";
    cin>>v1;
    cout<<"enter the v2 : ";
    cin>>v2;
    vector<int>* v = getPathDFS(edges,vertices,v1,v2);
    for(int i=0;i<v->size();++i){
        cout<<v->at(i)<<endl;
    }
    

}
