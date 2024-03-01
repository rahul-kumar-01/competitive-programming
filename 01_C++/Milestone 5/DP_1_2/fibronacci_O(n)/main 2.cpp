#include<iostream>
using namespace std;

//Time complexity = O(2^n) calling all nodes and do constant work
//Brute Force - simplest approach we can think
int fibronacci(int n){
    if(n<=1) return n;
    return fibronacci(n-1) + fibronacci(n-2);
}


int fibronacci_2_helper(int n,int * arr){
    if (n<=1) return n;
    if(arr[n] != -1){
        return arr[n];
    }
    int a = fibronacci_2_helper(n-1, arr);
    int b = fibronacci_2_helper(n-2, arr);
    arr[n] = a+b;
    return arr[n];
}

//Time Complixity = O(n) only at max n+1 node called including zero also
//memoization ( Top to Down approach )
int fibronacci_2(int n){
    int * arr = new int[n+1];
    for(int i=0;i<n+1;++i){
        arr[i]  = -1;
    }
    return fibronacci_2_helper(n,arr);
}


//Time complixity = O(n) which is better both approach because in recursion it took some space ( DP )
int fibronacci_3(int n){
    int * arr = new int[n+1];
    arr[0] = 0;
    arr[1] = 1;
    for(int i = 2;i<n+1;++i){
        arr[i] = arr[i-1] + arr[i-2];
    }
    return arr[n];
}




int main(){
    cout<<fibronacci(8)<<endl;
    cout<<fibronacci_2(7)<<endl;
    cout<<fibronacci_3(6)<<endl;
}
