#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;


int multiplyNumbers(int m, int n) {
    if(n==0 || m==0) return 0;
    return m+multiplyNumbers(m, n-1);
}
    
    
int countZeros(int n) {
    if(n<10){
        if(n==0) return 1;
        return 0;
    }
    if(n%10==0) return 1 + countZeros(n/10);
    return countZeros(n/10);
}

int geometricSum(int k){
    if(k==0) return 1;
    return 1/pow(2,k) + geometricSum(k-1);
}

bool helper(char * input,int si,long ei){
    
    if(si>=ei) return true;
    if(input[si] == input[ei]){
        return helper(input,si+1,ei-1);
    }
    return false;
}


bool checkPalindrome(char input[]) {
    return helper(input,0,strlen(input)-1);
}

int sumOfDigit(int n){
    if(n==0) return 0;
    return n%10 + sumOfDigit(n/10);
}

int main(){
    return 0;
}
