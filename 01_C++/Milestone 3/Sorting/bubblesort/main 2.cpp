#include<iostream>
using namespace std;
void swap(int &a,int &b){
    int temp=a;
    a=b;
    b=temp;
}

void BubbleSort(int *arr,int size){
    for(int j=size-1;j>0;--j){
        for(int i=0;i<j;++i){
            if(arr[i]>arr[i+1]){
                swap(arr[i],arr[i+1]);
            }
        }
    }
}


int main(){
    int size;
    cout<<"Lenght of input : ";
    cin>>size;
    int *arr = new int[size];
    for(int i=0;i<size;++i){
        cin>>arr[i];
    }
    BubbleSort(arr,size);
    
    for(int i=0;i<size;++i){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
