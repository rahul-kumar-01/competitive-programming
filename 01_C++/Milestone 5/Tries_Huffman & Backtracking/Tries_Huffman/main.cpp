#include<iostream>
using namespace std;

void printSudoko(int sudoko[9][9],int n){
    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j){
            cout<<sudoko[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    return;
}


class triplet{
public:
    bool empty;
    int row ;
    int col;
    triplet(){
        empty = false;
    }
};

bool helper(int output[3][5],int n){
    int
}

triplet isEmpty(int sudoko[9][9],int n){
    for(int  i=0;i<n;++i){
        for(int j=0;j<n;++j){
            if(sudoko[i][j] == 0){
                triplet t1;
                t1.row = i;
                t1.col = j;
                t1.empty = true;
                return t1;
                
            }
        }
    }
    triplet t1;
    return t1;
}


bool solveSudoko(int sudoko[9][9],int n){
    triplet t1 = isEmpty(sudoko, 9);
    if( t1.empty == false){
        printSudoko(sudoko,n);
        return true;
    }
    int empty_row = t1.row;
    int empty_col = t1.col;
    sudoko[empty_row][empty_col] = helper(sudoko,empty_row,empty_col,9);
    solveSudoko(sudoko, 9);
    return false;
}

int main(){
    int sudoko[9][9];
    int n = 9;
    for(int i=0;i<n;f++i){
        string s1;
        cout<<"enter the data of "<<i+1<<" th row : ";
        cin>>s1;
        for(int j=0;j<n;++j){
            sudoko[i][j] = s1[j];
        }
    }
    solveSudoko(sudoko,9);
}













//#include<iostream>
//using namespace std;
//
//
//
//pair<int, bool> missing_element(int board[9][9],int row,int col){
//    return 0;
//}
//
//bool solveSudoko(int board[9][9],int row,int col){
//    pair<int, bool> temp = missing_element(board, row, col);
//    if(temp.second == true){
//        board[row][col] = temp.first;
//        return true;
//    }
//    else return false;
//}
//
//void solveSudoko(int board[9][9]){
//    pair<int,int> empty =
//
//}
//
//int main(){
//    int board[9][9];
//    for(int i=0;i<9;++i){
//        string s1;
//        cout<<"Enter the "<<i+1<<" row data : ";
//        cin>>s1;
//        for(int j=0;j<9;++j){
//            board[i][j] = s1[i]-'0';
//        }
//    }
//    solveSudoko(board);
//}


























//#include<iostream>
//using namespace std;
//
//void pathToDestiny(int ** maze,int **solution,int size,int row,int col){
//    if(row <0 || col<0 || row>=size || col>=size || maze[row][col] == 0 || solution[row][col] == 1) return ;
//
//    if(row==size-1 && col == size-1){
//        solution[row][col] = 1;
//        for(int i=0;i<size;++i){
//            for(int j=0;j<size;++j){
//                cout<<solution[i][j]<<" ";
//            }
//            cout<<endl;
//        }
//        cout<<endl;
//        solution[row][col] = 0;
//        return;
//    }
//
//        solution[row][col] = 1;
//        pathToDestiny(maze, solution, size, row, col+1);
//        pathToDestiny(maze, solution, size, row+1, col);
//        pathToDestiny(maze, solution, size, row+1, col+1);
//        solution[row][col] = 0;
//}
//
//void ratMaze(int ** maze,int size){
//    int** solution = new int*[size];
//    for(int i=0;i<size;++i){
//        solution[i] = new int[size];
//        for(int j=0;j<size;++j){
//            solution[i][j] = 0;
//        }
//    }
//    pathToDestiny(maze,solution,size,0,0);
//}
//
//int main(){
//    int size;
//    cout<<"Enter the size of Maze : ";
//    cin>>size;
//    int ** maze = new int*[size];
//    for(int i=0;i<size;++i){
//        maze[i] = new int[size];
//        for(int j=0;j<size;++j){
//            cout<<"Enter the data of "<<i<<" row & "<<j<<" col : ";
//            cin>>maze[i][j];
//        }
//    }
//    ratMaze(maze,size);
//}
//
































//#include<iostream>
//using namespace std;
//bool isSafe(int ** arr,int size,int i,int j){
//    if(i== size || j==size || i<0 || j<0) return false;
//
//    // vertically upward
//    for(int a = i;a>=0;--a){
//        if(arr[a][j] == 1){
//            return false;
//        }
//    }
//
//    // Diagonally backward
//    for(int a = i,b = j ;a>=0 && b>=0;--a,--b){
//        if(arr[a][b] == 1){
//            return false;
//        }
//    }
//
//    //Diagonally Front
//    for(int a = i, b = j ;a>=0 && b<size ;--a,++b){
//        if(arr[a][b] == 1){
//            return false;
//        }
//    }
//    return true;
//}
//
//void nQueen(int ** arr,int size,int row){
//
//
//
//    //Base Case
//    if(row == size){
//        for(int i=0;i<size;++i){
//            for(int j=0;j<size;++j){
//                cout<<arr[i][j]<<" ";
//            }
//            cout<<endl;
//        }
//        cout<<endl;
//        return;
//    }
//
//
//        for(int col=0;col<size;++col){
//            if(isSafe(arr,size,row,col)){
//                arr[row][col] = 1;
//                nQueen(arr, size, row+1);
//                arr[row][col] = 0;
//
//            }
//    }
//    return;
//}
//
//
//int main(){
//    int size;
//    cout<<"enter the size of chess board : ";
//    cin>>size;
//
//    int ** arr = new int*[size];
//    for(int i=0;i<size;++i){
//        arr[i] = new int[size];
//        for(int j=0;j<size;++j){
//            arr[i][j] = 0;
//        }
//    }
//    nQueen(arr,size,0);
//
//}
