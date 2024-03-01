#include<iostream>
using namespace std;






bool isValid(vector<vector<int>> v1, int row ,int col,int num){
    for(int i=0;i<v1.size();++i){
        if(v1[i][col] == num) return false;
    }
    for(int i=0;i<v1.size();++i){
        if(v1[row][i] == num) return false;
    }
    int tempRow = row - (row%3);
    int tempCol = col - (col%3);
    for(int i=tempRow;i<tempRow+3;++i){
        for(int j= tempCol;j<tempCol+3;++j){
            if(v1[i][j] == num) return false;
        }
    }
    return true;
}



bool isEmpty(vector<vector<int>> &v1,int &row,int &col){
    for(int i=0;i<v1.size();++i){
        for(int j=0;j<v1[0].size();++j){
            if(v1[i][j] == 0){
                row = i;
                col = j;
                return false;
            }
        }
    }
    return true;
}



bool solveSudoku(vector<vector<int>> &v1){
    int row = 0;
    int col = 0;
    
    if(isEmpty(v1, row, col)){
        return true;
    }
    
    for(int i=1;i<=9;++i){
        if(isValid(v1,row,col,i)){
            v1[row][col] = i;
            if(solveSudoku(v1) == true) return true;
            v1[row][col] = 0;
        }
    }
    return false;
}


int main(){

    vector<vector<int>> v1;
    
    for(int i=0;i<9;++i){
        vector<int>v;
        for(int j=0;j<9;++j){
            int n;
            cin>>n;
            v.push_back(n);
        }
        v1.push_back(v);
    }
    
    solveSudoku(v1);
    for(int i=0;i<9;++i){
        for(int j=0;j<9;++j){
            cout<<v1[i][j] <<" ";
        }
        cout<<endl;
    }
    
}















//    vector<char> v1 = {'5','3','.','.','7','.','.','.','.'};
//    vector<char> v2 = {'6','.','.','1','9','5','.','.','.'};
//    vector<char> v3 = {'.','9','8','.','.','.','.','6','.'};
//    vector<char> v4 = {'8','.','.','.','6','.','.','.','3'};
//    vector<char> v5 = {'4','.','.','8','.','3','.','.','1'};
//    vector<char> v6 = {'7','.','.','.','2','.','.','.','6'};
//    vector<char> v7 = {'.','6','.','.','.','.','2','8','.'};
//    vector<char> v8 = {'.','.','.','4','1','9','.','.','5'};
//    vector<char> v9 = {'.','.','.','.','8','.','.','7','9'};
//
//    vector<vector<char>> board;
//    board.push_back(v1);
//    board.push_back(v2);
//    board.push_back(v3);
//    board.push_back(v4);
//    board.push_back(v5);
//    board.push_back(v6);
//    board.push_back(v7);
//    board.push_back(v8);
//    board.push_back(v9);
