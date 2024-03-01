#include<iostream>
using namespace std;


int helper_3(int** solution,int * weight , int*value,int temp,int n, int maxWeight){
    if(temp ==n  || maxWeight ==0) return 0;
    
//    for(int i=0;i<=n;++i){
//        solution[i][0] = 0;
//    }
//    for(int j=0;j<=maxWeight;++j){
//        solution[n][j] = 0;
//    }
    
    for(int i=n-1;i>=0;--i){
        for(int j=1;j<=maxWeight;++j){
            if(weight[i] > j){
                solution[i][j] = solution[i+1][j];
            }
            else{
                solution[i][j] = max(solution[i+1][j-weight[i]] + value[i], solution[i+1][j]);
            }
        }
    }
    return solution[0][maxWeight];
}

int knapsack_3(int *  weights,int * values,int n,int maxWeight){
    int ** solution = new int*[n+1];
    for (int i = 0; i <= n; i++){
        solution[i] = new int[maxWeight + 1];
    }
    int ans =  helper_3(solution, weights, values, 0,n, maxWeight);
    for(int i=0;i<=n;++i){
        for(int j=0;j<=maxWeight;++j){
            cout<<solution[i][j]<<" ";
        }
        cout<<endl;
    }
    return ans;
}
int helper_2(int ** solution,int * weight,int * value,int n,int maxWeight){
    //Base call
    if(n==0 || maxWeight ==0 ) return 0;
    
    if(solution[n][maxWeight] != -1){
        return solution[n][maxWeight];
    }
    
    if(weight[0] > maxWeight){
        solution[n][maxWeight] = helper_2(solution,weight+1,value+1,n-1,maxWeight);
    }
    
    else{
        int ans1 = helper_2(solution, weight+1, value+1,n-1,maxWeight-weight[0]) + value[0];
        int ans2 = helper_2(solution, weight+1, value+1,n-1,maxWeight);
        solution[n][maxWeight] = max(ans1,ans2);
    }
    return solution[n][maxWeight];
}



int knapsack_2(int* weight, int* value, int n, int maxWeight) {
    // Write your code here
    int** solution = new int*[n+1];
    for (int i = 0; i <= n; i++)
        solution[i] = new int[maxWeight + 1];

    for (int i = 0; i <= n; i++){
        for (int j = 0; j <= maxWeight + 1; j++){
            solution[i][j] = -1;
        }
    }
    return helper_2(solution, weight, value, n, maxWeight);
    
}


int knapsack(int *weights, int *values, int n, int maxWeight)
{
    //write your code here
    if(n==0 || maxWeight==0) return 0;
    
    if(weights[0] > maxWeight){
        return knapsack(weights+1, values+1 , n-1, maxWeight) ;
    }
    
    int ans1 = knapsack(weights+1, values+1, n-1, maxWeight-weights[0]) + values[0];
    int ans2 = knapsack(weights+1, values+1 , n-1, maxWeight) ;
    return max(ans1,ans2);
    
}
int main(){
    int weights[]= {5,7,3,1};
    int values[] = {3,1,2,4};
    int W = 7;
    cout<<knapsack(weights,values,4,W)<<endl;
    cout<<knapsack_2(weights,values,4,W)<<endl;
    cout<<knapsack_3(weights,values,4,W)<<endl;
}
