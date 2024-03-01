#include<iostream>
#include<cmath>
using namespace std;
#define MOD  (int)(pow(10,9)+7)
int staircase(int n) {
    if(n==0) return 1;
        if(n<0) return 0;
        else {
            return  staircase(n-1) + staircase(n-2) + staircase(n-3);
        }
  }


int staircase_2_helper(int n,int * arr){
    if(n==0) return 1;
    if(n<0) return 0;
    if(arr[n] != -1) {
        return arr[n];
    }
    
    arr[n] = staircase_2_helper(n-1, arr) + staircase_2_helper(n-2,arr)+
        staircase_2_helper(n-3,arr);

    return arr[n];
}

int staircase_2(int n){
    int * arr = new int[n+1];
    for(int i=0;i<n+1;++i){
        arr[i] = -1;
    }
    return staircase_2_helper(n,arr);
}

long helper_3(long *arr, int n) {
//   Base Case
      if(n==0 || n==1) return 1;

  arr[0] = 1;
  arr[1] = 1;
  arr[2] = 2;
  for (int i = 3; i <= n; ++i) {
    long ans1 =( arr[i - 1])% MOD;
    long ans2 = (arr[i - 2]) % MOD;
    long ans3 =(arr[i - 3]) % MOD;
      arr[i] =(ans1 + ans2 + ans3) % MOD;
//    arr[i] =(long) ((long long)(ans1 + ans2 + ans3) % MOD);    //may long + long = long long
  }
  
  return arr[n];
}

long staircase_3(int n) {
  long *arr = new long[n + 1];
  return helper_3(arr, n);
}


int main(){
//    cout<<MOD<<endl;
    cout<<staircase_3(3000)<<endl;
    cout<<staircase_2(30)<<endl;
    
    cout<<staircase(30)<<endl;
}
