#include<iostream>
using namespace std;


void printSolution(int ** solution,int n){
    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j){
            cout<<solution[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}


void helper(int **maze,int ** solution,int x ,int y,int n){
    
    //Base Case - printting solution
    if(x == n-1 && y == n-1){
        solution[x][y] = 1;
        printSolution(solution,n);
        solution[x][y] = 0;
        return;
    }
    
    if(x>=n || y>=n || y<0 || x<0 ||maze[x][y] == 0 || solution[x][y] == 1){
        return;
    }
    solution[x][y] = 1;
    
    helper(maze,solution,x-1,y,n);
    helper(maze,solution,x+1,y,n);
    helper(maze,solution,x,y-1,n);
    helper(maze,solution,x,y+1,n);
    
    solution[x][y] = 0;
    
}

void possibility(int ** maze,int n){
    
//    // Initialization of solution 2D array with 0
//      for(int i=0; i<n; i++){
//        memset(solution[i], 0, n*sizeof(int));
//      }
//
    // Intialize Solution 2D Array To Zeros
    int ** solution = new int* [n];
    for(int i=0;i<n;++i){
        solution[i] = new int[n];
        for(int j=0;j<n;++j){
            solution[i][j] = 0;
        }
    }
   
    
    helper(maze,solution,0,0,n);
    
}


int main(){
    int n;
    cout<<"Enter the maze size : ";
    cin>>n;
    
    // Maze Input
    int ** maze = new int* [n];
    for(int i=0;i<n;++i){
        maze[i] = new int [n];
        for(int j = 0;j<n;++j){
            cout<<"Data of "<<i<<" th row "<<j<<" th col : ";
            cin>>maze[i][j];
        }
    }
    
    possibility(maze,n);
}
