#include<iostream>
#include<climits>
#include<cmath>
using namespace std;


int helper_3(int ** input,int ** output,int row,int col,int x,int y){
    
    output[row-1][col-1] = input[row-1][col-1];
    for(int i = col-2; i>=0; --i){
        output[row-1][i] = output[row-1][i+1] + input[row-1][i];
    }
    for(int j = row-2; j>=0;--j){
        output[j][col-1] = output[j+1][col-1] + input[j][col-1];
    }
    for(int i=row-2;i>=0;--i){
        for(int j=col-2;j>=0;--j){
            int mini= min(output[i+1][j],min(output[i+1][j+1],output[i][j+1]));
            output[i][j] = input[i][j] + mini;
        }
    }
    
    return output[0][0];
}

int table_3(int ** input,int row,int col){
    int ** output = new int*[row];
    for(int i=0;i<row;++i){
        output[i] = new int[col];
    }
    return helper_3(input,output,row,col,0,0);
}

int helper_2(int ** input,int ** output,int row,int col,int x,int y){
    if(x == row-1 && y == col-1){
        return input[x][y];
    }
    if(x>=row || y>=col){
        return INT_MAX;
    }
    if(output[x][y] != -1){
        return output[x][y];
    }
    
    int ans1 = helper_2(input,output,row,col,x,y+1);
    int ans2 = helper_2(input,output,row,col,x+1,y+1);
    int ans3 = helper_2(input,output,row,col,x+1,y);
    
    output[x][y] = min(ans1,min(ans2,ans3)) + input[x][y];
    return output[x][y];
}

int table_2(int ** input ,int row, int col){
    int ** output = new int*[row];
    for(int i=0;i<row;++i){
        output[i] = new int[col];
        for(int j=0;j<col;++j){
            output[i][j] = -1;
        }
    }
    
    return helper_2(input,output,row,col,0,0);
}

int helper(int ** input,int m,int n,int x,int y){
    if(x == m-1 && y == n-1){
        return input[x][y];
    }
    if(x>=m || y>=n){
        return INT_MAX;
    }
    
    int ans1 = helper(input,m,n,x,y+1);
    int ans2 = helper(input,m,n,x+1,y+1);
    int ans3 = helper(input,m,n,x+1,y);
    
    int final_ans = min(ans1,min(ans2,ans3)) + input[x][y];
    return final_ans;
}


int table_1(int** input,int m,int n){
    return helper(input,m,n,0,0);
}


int main(){
    int row,col;
    cout<<"enter the row : ";
    cin>>row;
    cout<<"enter the col : ";
    cin>>col;
    int ** input = new int * [row];
    for(int i=0;i<row;++i){
        input[i] = new int[col];
        for(int j =0;j<col;++j){
            cout<<"enter the "<<i<<" th row "<<j<<" th col : ";
            cin>>input[i][j];
        }
    }
    
    cout<<table_1(input,row,col)<<endl;
    cout<<table_2(input,row,col)<<endl;
    cout<<table_3(input,row,col)<<endl;
    
}
