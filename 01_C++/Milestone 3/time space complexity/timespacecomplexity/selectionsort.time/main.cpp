#include<sys/time.h>
#include<iostream>
using namespace std;


long getTimeinMicroSeconds(){
    struct timeval start;
    gettimeofday(&start,NULL);
    return start.tv_sec*1000000+start.tv_usec;
}
void selectionSort(int input[],int start,int end){
    if(start>=end) return ;
    int smallest=input[start];
    for(int i=start+1;i<end;++i){
        if(smallest>input[i]){
            smallest=input[i];
            input[i]=input[start];
            input[start]=smallest;
        }
    }  
    selectionSort(input+1,start+1,end);
}


int main(){
    
    for(int n=10;n<=1000000;n*=10){
        int *arr=new int[n];
        long starttime,endtime;
        for(int i=0;i<n;++i){
            arr[i]=n-i;
        }
        
        starttime = getTimeinMicroSeconds();
        selectionSort(arr,0,n);
        endtime = getTimeinMicroSeconds();
        cout<<"merge sort n = "<<n<<"  time = "<<endtime-starttime<<endl;
        
    }
}


