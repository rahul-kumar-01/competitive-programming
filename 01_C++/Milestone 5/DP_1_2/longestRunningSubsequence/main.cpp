#include<iostream>

using namespace std;


int helper_3(int * input,int n,int * output){
    output[0] = 1;
    for(int i=1;i<n;++i){
        int maxSubsequence = 1;
        output[i] = 1;
        for(int j=i-1;j>=0;--j){
            if(input[j] >= input[i]){
                continue;
            }
            else{
                int maxSubsequence  = output[j] + 1;
                if(output[i] < maxSubsequence)  output[i] = maxSubsequence;
            }
        }
    }
    int max = INT_MIN;
    for(int i=0;i<n;++i){
        if(output[i] > max){
            max = output[i];
        }
    }
    return max;
}


int longestIncreasingSubsequence_3(int * arr,int n){
    int * output = new int [n];
    return helper_3(arr,n,output);
}



void helper(int input[],int size,int startIndex,int output[],int oSize,int &max){
    
    if(size == startIndex){
        int count = 1;
        
        for(int i=0;i<oSize-1;++i){
            if(output[i] < output[i+1]){
                ++count;
            }
            else{
                break;
            }
        }
        if(max < count) max = count;
        return;
    }
    helper(input,size,startIndex+1,output,oSize,max);
    int smallOutput[1000];
    int i;
    for (i = 0;i<oSize;++i){
        smallOutput[i] = output[i];
    }
    smallOutput[i]  = input[startIndex];
    helper(input,size,startIndex+1,smallOutput,oSize+1,max);

}



int printSubsetsOfArray(int input[], int size) {
    int max  = 0;
    int output[1000];

    helper(input,size,0,output,0,max);
    return max;
}



int longestIncreasingSubsequence_1(int * arr, int n){
    return printSubsetsOfArray(arr, n);
}




int main(){

    int arr[]= {10,20,30};
    int n = 3;
    cout<<longestIncreasingSubsequence_1(arr, n)<<endl;
    cout<<longestIncreasingSubsequence_3(arr, n)<<endl;
    
}



//wrong method

//int longestIncreasingSubsequence_3(int* arr, int n) {
//    // Write your code here
//    if(n<=0){
//        return 0;
//    }
//    int ans1 = 0,ans2 = 0;
//    if(arr[0]<arr[1]){
//        ans1 = longestIncreasingSubsequence_3(arr+1,n-1) + 1;
//    }
//    else{
//        ans2 = longestIncreasingSubsequence_3(arr+1, n-1);
//    }
//    return max(ans1,ans2);
//}
//

