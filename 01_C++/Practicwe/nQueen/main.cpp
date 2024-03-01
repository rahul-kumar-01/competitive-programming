#include<iostream>
#include<vector>
using namespace std;

bool isSafe(vector<vector<int>> &v1,int n,int row,int col){
    for(int i=row-1;i>=0;--i){
        if(v1[i][col] == 1) return false;
    }
    for(int i=row-1,j=col-1;i>=0&&j>=0; --i,--j){
        if(v1[i][j] == 1) return false;
    }
    for(int i=row-1,j=col+1; i>=0 && j<n ;--i,++j){
        if(v1[i][j] == 1) return false;
    }
    return true;
}

void nQueenHelper(vector<vector<int>> &v1,int n,int row){
    if(row == n){
        for(int i=0;i<n;++i){
            for(int j=0;j<n;++j){
                cout<<v1[i][j]<<" ";
            }
            cout<<endl;
        }
        return;
    }
    
    for(int i=0;i<n;++i){
        if(isSafe(v1,n,row,i)){
            v1[row][i] = 1;
            nQueenHelper(v1, n, row+1);
            v1[row][i] = 0;
        }
    }
    return;
}


void nQueen(int n){
    vector<vector<int>> v1;
    for(int i=0;i<n;++i){
        vector<int> v;
        for(int j=0;j<n;++j){
            v.push_back(0);
        }
        v1.push_back(v);
    }
    nQueenHelper(v1,n,0);
}


int main(){
    int n;
    cin>>n;
    nQueen(n);
    
    
//    vector<vector<int>> v1;
//    for(int i=0;i<n;i=i+2){
//        vector<int>v;
//        for(int j=0;j<2*n;++j){
//            int num;
//            cin>>num;
//            v.push_back(num);
//        }
//        v1.push_back(v);
//    }
}
