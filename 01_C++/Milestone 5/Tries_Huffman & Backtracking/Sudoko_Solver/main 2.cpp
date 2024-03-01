#include<iostream>
#define N 9
using namespace std;



//bool isSafeRow(int grid[N][N],int row,int num){
//    for(int i=0;i<N;++i){
//        if(grid[row][i] == num){
//            return false;
//        }
//    }
//    return true;
//}
//
//bool isSafeCol(int grid[N][N],int col,int num){
//    for(int i=0;i<N;++i){
//        if(grid[i][col]==num){
//            return false;
//        }
//    }
//    return true;
//}
//
//bool isSafeInSmallGrid(int grid[N][N],int row,int col,int num){
//    int rowFactor = row - (row%3);
//    int colFactor = col - (col%3);
//    for(int i=0;i<3;++i){
//        for(int j=0;j<3;++j){
//            if(grid[rowFactor+i][colFactor+j] == num){
//                return false;
//            }
//        }
//    }
//    return true;
//}
//
//
//bool isSafe(int grid[N][N],int row,int col,int i){
//    return isSafeRow(grid, row, i) && isSafeCol(grid, col, i) && isSafeInSmallGrid(grid, row, col, i);
//}
bool correct(int sudoko[N][N],int row,int col,int num){
    //horizontally check
    for(int i=0;i<N;++i){
        if(sudoko[row][i] == num) return false;
    }
    for(int i=0;i<N;++i){
        if(sudoko[i][col] == num) return false;
    }

    int startRow = row - (row%3);
    int startCol = col - (col%3);

    for(int i=startRow;i<startRow+3;++i){
        for(int j= startCol;j<startCol+3;++j){
            if(sudoko[i][j] == num) return false;
        }
    }
    return true;
}



bool findTheEmptyGrid(int grid[N][N],int &row,int &col){
    for(int i=0;i<N;++i){
        for(int j=0;j<N;++j){
            if(grid[i][j]==0){
                row = i;
                col = j;
                return true;
            }
        }
    }
    return false;
}

bool solveGrid(int grid[N][N]){
    int row;
    int col;
    if(!(findTheEmptyGrid(grid,row,col))){
        return true;
    }
    for(int i=1;i<=N;++i){
        if(correct(grid,row,col,i)){
            grid[row][col] = i;
//            solveGrid(grid);
            if(solveGrid(grid)){
                return true;
            }
            grid[row][col] = 0;
        }
    }
    return false;
}


int main(){
    int grid[N][N];
    for(int i =0;i<N;++i){
        for(int j=0;j<N;++j){
            cin>>grid[i][j];
        }
    }
    solveGrid(grid);
    for(int i=0;i<N;++i){
        for(int j=0;j<N;++j){
            cout<<grid[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}
