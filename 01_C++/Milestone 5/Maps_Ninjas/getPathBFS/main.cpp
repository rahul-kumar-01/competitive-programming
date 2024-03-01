#include<iostream>
#include<queue>
#include<map>
using namespace std;

vector<int>* getPathBFSHelper(int ** edges,int vertices,bool * visited,int si,int ei){
    
    map<int,int>map;
    queue<int> pendingNodes;
    pendingNodes.push(si);
    visited[si] = true;
    
    bool flag =  false;
    while(!pendingNodes.empty() && !flag){
        int front = pendingNodes.front();
        pendingNodes.pop();
        
        for(int i=0;i<vertices;++i){
            if(edges[front][i] == 1 && visited[i] == false){
                pendingNodes.push(i);
                visited[i] = true;
                map[i] = front;
                if(i == ei){
                    flag = true;
                    break;
                }
            }
        }
    }
    
    if(flag == false){
        return NULL;
    }
    
    vector<int>* v = new vector<int>();
//    int current = pendingNodes.front();           //wrong
    int current = pendingNodes.back();
    //or use
//    int current = ei;
    v->push_back(current);
    while(current != si){
        current = map[current];
        v->push_back(current);
    }
    return v;
}


vector<int>* getPathBFS(int ** edges,int vertices){
    bool * visited = new bool[vertices];
    for(int i=0;i<vertices;++i){
        visited[i] = false;
    }
    int si,ei;
    cout<<"enter the startIndex : ";
    cin>>si;
    cout<<"enter the endIndex : ";
    cin>>ei;
    return getPathBFSHelper(edges,vertices,visited,si,ei);
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
    
    
    vector<int>* v = getPathBFS(edges,vertices);
    if(v!=NULL){
        for(int i=0;i<v->size();++i){
            cout<<v->at(i)<<" ";
        }
        cout<<endl;
    }
    else {
        cout<<"No Path Found"<<endl;
    }
    

}
