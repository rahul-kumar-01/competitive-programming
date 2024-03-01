#include<iostream>
using namespace std;
void swap(int &a, int &b){
    int temp=a;
    a=b;
    b=temp;
}
int partition(int * arr,int start,int end){
    int count=0;
    int pivot_number=arr[start];
    for(int i=start+1;i<=end;++i){
        if(pivot_number >= arr[i]){
            ++count;
        }
    }
    int  pivot_index = start + count;
    swap(arr[pivot_index],arr[start]);
    
    int i=start;
    int j=end;
    while(i<pivot_index && j>pivot_index){
        if(arr[i]<=pivot_number){
            ++i;
        }
        else if(arr[j]>pivot_number){
            --j;
        }
        else{
            swap(arr[i++],arr[j--]);
        }
    }
    
    return pivot_index;
}

void QuickSort(int * arr,int start,int end){
    if(start>=end) return;
    int c=partition(arr,start,end);
    QuickSort(arr,start,c-1);
    QuickSort(arr,c+1,end);
}

int main(){
    int size;
    cout<<"Lenght of input : ";
    cin>>size;
    int *arr = new int[size];
    for(int i=0;i<size;++i){
        cin>>arr[i];
    }
    QuickSort(arr,0,size-1);
    
    for(int i=0;i<size;++i){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
