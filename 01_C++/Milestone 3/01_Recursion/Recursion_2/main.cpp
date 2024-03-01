#include<iostream>
using namespace std;

void replaceCharacter(char input[], char c1, char c2) {
    if(input[0] == '\0') return;
    replaceCharacter(input+1, c1, c2);
    if(input[0] == c1) input[0] = c2;
    return;
}

void removeConsecutiveDuplicates(char *input) {
    if(input[0] == '\0') return;
    removeConsecutiveDuplicates(input+1);
    if(input[0] == input[1]){
        int i=0;
        for(;i<strlen(input)-1;++i){
            input[i] = input[i+1];
        }
        input[i] = '\0';
    }
    return;
}

void swap(int &a,int &b){
    int temp = a;
    a = b;
    b = temp;
}

void mergeTwoSortedArray(int * arr,int si,int ei,int mid){
    int output[1000] = {0};
    int i=si;
    int j=mid+1;
    int k =si;
    
    while(i <= mid && j<= ei){
        if(arr[i] >= arr[j]) output[k++] = arr[j++];
        else if(arr[i] < arr[j]) output[k++] = arr[i++];
    }
    
    while(i<=mid){
        output[k++] = arr[i++];
    }
    while(j<=ei){
        output[k++] = arr[j++];
    }
    for(int i=si;i<=ei;++i){
        arr[i] = output[i];
    }
    return;
}



void mergeSort(int * arr,int si,int ei){
    if(si>=ei) return;
    int mid = (si+ei)/2;
    mergeSort(arr,si,mid);
    mergeSort(arr,mid+1,ei);
    mergeTwoSortedArray(arr,si,ei,mid);
}

void mergeSort(int * arr,int n){
    mergeSort(arr,0,n-1);
}

int partition(int *input,int si,int ei){
     
    int pivot = input[si];
    int count = si;
    for(int i=si+1;i<=ei;++i){
        if(input[i] < pivot) ++count;
    }
    int pivotIndex = count;
    
    swap(input[pivotIndex],input[si]);
    
    int i = si;
    int j = ei;
    
    while(i<pivotIndex && j>pivotIndex){
        if(input[i] <= pivot) ++i;
        else if(input[j] > pivot) --j;
        else swap(input[i++],input[j--]);
    }
    return pivotIndex;
}

void quickSort(int * input,int si,int ei){
    if(si>=ei) return;
    int pivotIndex = partition(input,si,ei);
    quickSort(input, si, pivotIndex-1);
    quickSort(input, pivotIndex+1, ei);
}


void quickSort(int input[], int size) {
    quickSort(input,0,size-1);
}






int main(){
    //    char arr[100] = {'a','a','a','v','b','b','a'};
    //    replaceCharacter(arr, 'a', 'b');
    //    removeConsecutiveDuplicates(arr);
    //    for(int i=0;i<strlen(arr);++i){
    //        cout<<arr[i]<<" ";
    //    }
    //    cout<<endl;
    
//    int arr[10] = {0,4,78,343,-3,34,6,8,3,2};
//    quickSort(arr,10);
//    for(int i=0;i<10;++i){
//        cout<<arr[i]<<" ";
//    }
//    cout<<endl;
    

    
}
