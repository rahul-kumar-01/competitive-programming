#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;

vector<int>* helper(int ** edges,int vertices,bool * visited,int startIndex){

    queue<int> pendingNodes;
    pendingNodes.push(startIndex);
    visited[startIndex] = true;

    vector<int>* v = new vector<int>();
    while(!pendingNodes.empty()){
        int front = pendingNodes.front();
        pendingNodes.pop();
        v->push_back(front);
        for(int i=0;i<vertices;++i){
            if(edges[front][i] == 1 && visited[i] == false){
                pendingNodes.push(i);
                visited[i] = true;
            }
        }
    }
    return v;
}


vector<vector<int>*>* connectedComponent(int ** edges,int vertices){
    bool * visited = new bool[vertices];
    for(int i=0;i<vertices;++i){
        visited[i] = false;
    }
    vector<vector<int>*>* output = new vector<vector<int>*> ();
    for(int i=0;i<vertices;++i){
        if(visited[i] == false){
            vector<int>* v = helper(edges,vertices,visited,i);
            output->push_back(v);
        }
    }
    return output;
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


    vector<vector<int>*>* v1 = connectedComponent(edges,vertices);
    if(v1 != NULL){

//        for(int i=0;i<v1->size();++i){
//            for(int j=0;j<v1->at(i)->size();++j){
//                cout<<v1->at(i)->at(j)<<" ";
//            }
//            cout<<endl;
//        }

        //if you want to print is sorted order

        for(int i=0;i<v1->size();++i){
            vector<int>* v = new vector<int>();
            v = v1->at(i);
            sort(v->begin(),v->end());
            for(int j=0;j<v->size();++j){
                cout<<v->at(j)<<" ";
            }
            cout<<endl;
        }
    }
}



//example : enter the vertices : 9 10
//0 8
//1 6
//1 7
//1 8
//5 8
//6 0
//7 3
//7 4
//8 7
//2 5
//enter the no of edge : 0 1 2 3 4 5 6 7 8

