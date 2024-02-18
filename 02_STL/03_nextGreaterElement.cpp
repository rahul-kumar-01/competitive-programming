// eg: arr->   9 10 2 3  4  next greater element to right of each element 
// output ->  10 -1 3 4 -1

#include<iostream>
#include<stack>
using namespace std;

void nextGreaterElementToRight(int * arr,int n){
    stack<int>s;
    for(int i=n-1;i>=0;--i){
        while(!s.empty() && s.top() < arr[i]) s.pop();
        
        if(s.empty()) {
            s.push(arr[i]);
            cout<<s.top()<<endl;
            arr[i] = -1;
            continue;
        }
        if(!s.empty() && s.top() > arr[i]) {
            int temp = arr[i];
            arr[i] = s.top();
            s.push(temp);
        }
    }    
    return;
}

int main(){
    int n; cin>>n;
    int * arr = new int [n];
    for(int i=0;i<n;++i){
        cin>>arr[i];
    }
    nextGreaterElementToRight(arr,n);
    for(int i=0;i<n;++i){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    delete [] arr;
}