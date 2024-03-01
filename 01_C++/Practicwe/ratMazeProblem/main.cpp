#include<iostream>
using namespace std;


void ratMazeHelper(vector<vector<int>> &input,vector<vector<int>> &output,int n,int i,int j){
    if(i == n-1 && j== n-1){
        output[i][j] = 1;
        for(int i=0;i<n;++i){
            for(int j=0;j<n;++j){
                cout<<output[i][j]<<" ";
            }
        }
        cout<<endl;
        output[i][j] = 0;
        return;
    }
    
    if(i<0 || j<0 || i>=n || j>=n || output[i][j] == 1) return;
    if(input[i][j] == 0) return;
    
    
    output[i][j] = 1;
    ratMazeHelper(input, output, n, i+1, j);
    ratMazeHelper(input, output, n, i, j+1);
    ratMazeHelper(input, output ,n, i-1, j);
    ratMazeHelper(input, output, n, i, j-1);
    output[i][j] = 0;
    
    
}

void ratMaze(vector<vector<int>> &v1,int n){
    vector<vector<int>> output;
    for(int i=0;i<n;++i){
        vector<int>v;
        for(int j=0;j<n;++j){
            v.push_back(0);
        }
        output.push_back(v);
    }
    return ratMazeHelper(v1,output,n,0,0);
}


int main(){
    int n;
    cin>>n;
    vector<vector<int>> v1;
    for(int i=0;i<n;++i){
        vector<int>v;
        for(int j=0;j<n;++j){
            int num;
            cin>>num;
            v.push_back(num);
        }
        v1.push_back(v);
    }
    ratMaze(v1,n);
}
