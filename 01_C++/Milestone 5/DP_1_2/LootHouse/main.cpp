#include<iostream>
using namespace std;




int helper(int * arr, int n){
  if(n<=0){
    return 0;
  }
  int ans1 = helper(arr+2,n-2) + arr[0];
  int ans2 = helper(arr+1,n-1);
  return max(ans1,ans2);
}


int main(){
    int arr[]= {10,2,30,20};
    cout<<helper(arr,4)<<endl;
}
