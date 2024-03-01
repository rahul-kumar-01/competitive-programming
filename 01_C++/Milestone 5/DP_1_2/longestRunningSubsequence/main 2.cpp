#include<iostream>
using namespace std;
int longestIncreasingSubsequence(int* arr, int n) {
    // Write your code here
    if(n<=0){
        return 0;
    }
    int ans1 = 0,ans2 = 0;
    if(arr[0]<arr[1]){
        ans1 = longestIncreasingSubsequence(arr+1,n-1) + 1;
    }
    else{
        ans2 = longestIncreasingSubsequence(arr+1, n-1);
    }
    return max(ans1,ans2);
}
int main(){
    int arr[]= {10,15,30,20};
    cout<<longestIncreasingSubsequence(arr,4)<<endl;
    
}

