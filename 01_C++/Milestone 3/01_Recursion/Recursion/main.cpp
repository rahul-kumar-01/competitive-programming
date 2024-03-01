#include<iostream>
using namespace std;

int factorial(int n){
    if(n==0) return 1;
    return n*factorial(n-1);
}

int fibronacci(int n){
    if(n==0 || n==1) return n;
    return fibronacci(n-1) + fibronacci(n-2);
}
int power(int x,int n){
    if(n==0) return  1;
    return x*power(x, n-1);
}

void printNumber(int n){
    if(n==0) return;
    printNumber(n/10);
    cout<<n%10;
}
void printNumberTillN(int n){
    if(n==0) return;
    printNumberTillN(n-1);
    cout<<n<<" ";
}


int noOfDigit(int n){
    if(n<10) return 1;
    return 1 +noOfDigit(n/10);
}

bool isSorted(int * arr,int n){
    if(n==0 || n==1) return true;
    if(arr[0] < arr[1]){
        return isSorted(arr+1, n-1);
    }
    else return false;
}

int sumOfArray(int * arr,int n){
    if(n==0) return 0;
    return sumOfArray(arr+1, n-1)+arr[0];
}

bool checkNumber(int *arr,int n,int x){
    if(n==0) return false;
    if(arr[0] == x) return true;
    else return checkNumber(arr+1, n-1, x);
}

int main(){
//    cout<<factorial(5)<<endl;
//    cout<<fibronacci(5)<<endl;
//    printNumber(3568);
//    cout<<endl;
//    printNumberTillN(5);
//    cout<<endl;
   
//   remember placing 0 in front of int be considered as octal
//    cout<<noOfDigit(0121)<<endl; convert 0121 convert to octal and result differ
//    cout<<noOfDigit(001000)<<endl;
    
//    int n;
//    cin>>n;
//    cout<<"No of Digit of "<<n<<" : "<<noOfDigit(n)<<endl;
    int arr[5] = {10,20,30,40,50};
    cout<<sumOfArray(arr, 5)<<endl;
    cout<<isSorted(arr, 5)<<endl;

}
