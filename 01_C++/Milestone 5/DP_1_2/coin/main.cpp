#include<iostream>
using namespace std;

int helper_3(int ** solution,int arr[],int size,int value){
//    if(value <0) return 0;
//    if(size <0) return 0;
    for(int i=0;i<=size;++i){
        solution[i][0] = 1;
    }
    for(int j=0;j<=value;++j){
        solution[size][j] = 0;
    }
    for(int i=size-1;i>=0;--i){
        for(int j=1;j<=value;++j){
            if(j-arr[i] == 0){
                solution[i][j-arr[i]] = 1;
            }
            else if(j-arr[i] <0){
                solution[i][j-arr[i]] =0;
            }
            solution[i][j] = solution[i+1][j] + (solution[i][j-arr[i]] );
        }
    }
    return solution[0][value];
}

int countWaysToMakeChange_3(int arr[],int size,int value){
    int ** solution = new int*[size+1];
    for(int i=0;i<=size;++i){
        solution[i]  = new int[value+1];
    }
    return helper_3(solution,arr,size,value);
}

int countWaysToMakeChange(int denominations[], int numDenominations, int value){
    //Write your code here
    if(value<0) return 0;
    if(value ==0) return 1;
    if(numDenominations <= 0){
        return 0;
    }

    int ans1 =
    countWaysToMakeChange(denominations,numDenominations, value-denominations[0] ) ;
     int ans2 =
    countWaysToMakeChange(denominations+1, numDenominations-1, value);

    return ans1 + ans2;
}
int main(){
    int denominations [8] = {6,9,1,2,3,5,8,9};
//    int value = 300;
    
    cout<<countWaysToMakeChange_3(denominations,8,200)<<endl;
    cout<<countWaysToMakeChange(denominations,8,200)<<endl;
}
