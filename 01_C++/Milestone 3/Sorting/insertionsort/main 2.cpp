#include<iostream>
using namespace std;
void InsertionSort(int* arr,int size){
    for(int i=1;i<size;++i){
        int current = arr[i];
        int j;
        for(j=i-1;j>=0;++j){
            if(current<arr[j]){
                arr[j+1]=arr[j];
            }
        }
        arr[j+1]=current;
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
    InsertionSort(arr,size);
    
    for(int i=0;i<size;++i){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

