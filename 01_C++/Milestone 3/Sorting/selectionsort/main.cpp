#include<iostream>
using namespace std;
void SelectionSort(int* arr,int size){
    
    for(int i=0;i<size;++i){
        int smallest=arr[i];
        for(int j=i+1;j<size;++j){
            if(smallest>arr[j]){
                smallest=arr[j];
                arr[j]=arr[i];
                arr[i]=smallest;
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
    SelectionSort(arr,size);
    
    for(int i=0;i<size;++i){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
