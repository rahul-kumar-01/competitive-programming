#include<iostream>
using namespace std;


int helper_3(int * arr,int n,vector<int>* dp,int startIndex,int endIndex){
    for(int len=2;len<n;++len){
        
        for(int row = 0, col = len; row<n-len;++row,++col){
            int minCost = INT_MAX;
            for(int k= row+1;k<col;++k){
                minCost = min(minCost,(dp[row][k] + dp[k][col]+ (arr[k]*arr[row]*arr[col]) ));
            }
            dp[row][col] = minCost;
        }
    }
    return dp[0][endIndex];
}

int matrixChainMultiplication_3(int* arr, int n) {
    vector<int>* dp = new vector<int>[n+1];
    for(int i=0;i<n+1;++i){
        for(int j=0;j<n+1;++j){
            dp[i].push_back(0);
        }
    }
    return helper_3(arr,n,dp,0,n-1);
}

int helper_2(int * arr,int n,int startIndex,int endIndex, vector<int>* dp){
    if(startIndex == endIndex) {
        dp[startIndex][endIndex] = 0;
        return 0;
    }
    else if(startIndex == endIndex-1){
        dp[startIndex][endIndex] = 0;
        return 0;
    }
    if(dp[startIndex][endIndex] != -1){
        return dp[startIndex][endIndex];
    }
    int minCost = INT_MAX;
    for(int k=startIndex+1;k<=endIndex-1;++k){
      
        minCost = min(minCost,(helper_2(arr, n, startIndex, k, dp)+
                                                helper_2(arr, n, k, endIndex,dp)+ (arr[startIndex]*arr[endIndex]*arr[k])));
    }
    dp[startIndex][endIndex] = minCost;
    return dp[startIndex][endIndex];
}


int matrixChainMultiplication_2(int *arr,int n){
    vector<int>* dp = new vector<int>[n+1];
    for(int i=0;i<n+1;++i){
        for(int j=0;j<n+1;++j){
            dp[i].push_back(-1);
        }
    }
    return helper_2(arr,n,0,n-1,dp);
  
}


int helper(int * arr ,int n, int startIndex,int endIndex){
    if(startIndex == endIndex) return 0;        //empty matix
    if(startIndex == endIndex-1) return 0;      //single matrix
    
    int minCost = INT_MAX;
    for(int k=startIndex+1;k<=endIndex-1;++k){
        int ans = 0;
        int a = helper(arr,n,startIndex,k);
        int b = helper(arr,n,k,endIndex);

        int c = arr[startIndex] * arr[k] * arr[endIndex];

        ans = a+b+c;

        
        minCost = min(minCost,ans);
    }
    return minCost;
}

int matrixChainMultiplication(int* arr, int n) {
    // Write your code here
    return helper(arr,n,0,n-1);
}

int main(){

    int arr[31] = {26,57, 55, 62, 74, 95, 33 ,29, 21, 87, 82, 96, 88, 70, 43, 84, 45, 50, 25, 83, 25, 23, 57, 98, 71, 25, 30 ,62 ,69 ,44 ,81 };
    
//    cout<<matrixChainMultiplication(arr, 31)<<endl;  infinite time
    cout<<matrixChainMultiplication_2(arr, 31)<<endl;
    cout<<matrixChainMultiplication_3(arr, 31)<<endl;
}
