#include<iostream>
using namespace std;



int subset(int input[], int n, int output[][20]) {
    if(n==0){
        output[0][0] = 0;
        return 1;
    }
    
    int outputSize = subset(input+1,n-1,output);
    
    for(int i=0;i<outputSize;++i){
        output[i+outputSize][0] = output[i][0] + 1;
        output[i+outputSize][1] = input[0];
        for(int j = 0;j<output[i][0];++j){
            output[i+outputSize][j+2] = output[i][j+1];
        }
    }
    return 2*outputSize;
}

void helper(int input[],int size,int output[],int oSize){
    if(size == 0){
        for(int i=0;i<oSize;++i){
            cout<<output[i]<<" ";
        }
        cout<<endl;
        return;
    }
    
    helper(input+1,size-1,output,oSize);
    output[oSize] = input[0];
    helper(input+1,size-1,output,oSize+1);
}

void printSubsetsOfArray(int input[], int size) {
    int output[100];
    helper(input,size,output,0);
}


int main(){
    int arr[3] = {10,20,30};
//    int output[100][20];
//    int size = subset(arr, 3, output);
//    cout<<size<<endl;
//    for(int i=0;i<size;++i){
//        for(int j=1;j<=output[i][0];++j){
//            cout<<output[i][j]<<" ";
//        }
//        cout<<endl;
//    }
    printSubsetsOfArray(arr, 3);
}
