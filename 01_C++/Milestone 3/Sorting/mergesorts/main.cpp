#include<iostream>
using namespace std;

void  MergeTwoSortedArray(int *arr,int start,int middle,int end){
    int i=start;
    int j=middle+1;
    // wrong practice int * output=new int [end+1];
    int output[100];
    int k=start;
    while(i<=middle && j<=end){
        if(arr[i]>=arr[j]){
            output[k++]=arr[j++];
        }
        else{
            output[k++]=arr[i++];
        }
    }
    if(i<=middle){
        while(i<=middle){
            output[k++]=arr[i++];
        }
    }
    if(j<=end){
        while(j<=end){
            output[k++]=arr[j++];
        }
    }
    
    for(int i=0;i<k;++i){
        arr[i]=output[i];
    }
}



void MergeSort(int *arr,int start,int end){
    if(start>=end) return;
    int middle=(start+end)/2;
    MergeSort(arr,start,middle);
    MergeSort(arr,middle+1,end);
    MergeTwoSortedArray(arr,start,middle,end);
    
}

int main(){
    int size;
    cout<<"Lenght of input : ";
    cin>>size;
    int *arr = new int[size];
    for(int i=0;i<size;++i){
        cin>>arr[i];
    }
    MergeSort(arr,0,size-1);
    
    for(int i=0;i<size;++i){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

