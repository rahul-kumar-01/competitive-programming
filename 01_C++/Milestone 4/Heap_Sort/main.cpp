#include<iostream>
using namespace std;

void implaceHeapSort(int arr[],int n){
    //insert to form a heap
    for(int i=1;i<n;++i){
        int childIndex = i;
        int parentIndex = (i-1)/2;
        
        while(parentIndex >= 0){
            
            if(arr[parentIndex] > arr[childIndex]){
                int temp = arr[parentIndex];
                arr[parentIndex] = arr[childIndex];
                arr[childIndex] = temp;
            }
            else{
                break;
            }
            childIndex = parentIndex;
            parentIndex = (childIndex-1)/2;
        }
    }
    
    //remove
    
    int size = n;
    
    while(size > 1){
        int temp = arr[0];
    arr[0] = arr[size-1];
    arr[size-1] = temp;
    --size;
    
    int parentIndex = 0;
    int lc = (2*parentIndex) +1;
    int rc = (2*parentIndex)+2;
    
        while(lc < size ){
            int minIndex = parentIndex;
            if(arr[minIndex] > arr[lc]){
                minIndex = lc;
            }
            if(rc < size &&  arr[minIndex] > arr[rc]){
                minIndex = rc;
            }
            if(minIndex == parentIndex) break;
            
            //swap
            int temp = arr[minIndex];
            arr[minIndex] = arr[parentIndex];
            arr[parentIndex] = temp;
            
            parentIndex = minIndex;
            lc = (2*parentIndex)+1;
            rc = (2*parentIndex)+2;
        }
    }
}

int main(){
    // implace algorithm space complexity O(N)
    int n;
    cout<<"enter the size : ";
    
    cin >> n;
    int * arr= new int[n];
    for (int i=0;i<n;++i){
        cin>>arr[i];
    }
    implaceHeapSort(arr,n);
    for(int i=0;i<n;++i){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    
}
