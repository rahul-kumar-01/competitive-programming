#include<iostream>
using namespace std;


int subsetSumToK(int input[], int n, int output[][50], int k) {
   if(n==0) {
        if(k==0){
            output[0][0] = 0;
            return 1;
        }
        return 0;
    }
    int smallOutput1[100][50];
    int smallOutput2[100][50];
    int temp1 = subsetSumToK(input+1, n-1, smallOutput1, k);
    int temp2 = subsetSumToK(input+1, n-1, smallOutput2, k-input[0]);
    
    
    int a = 0;
    for(int i=0;i<temp1;++i){
        for(int j=0;j<=smallOutput1[i][0];++j){
            output[a][j] = smallOutput1[i][j];
        }
        a++;
    }
    for(int i=0;i<temp2;++i){
        output[a][0] = smallOutput2[i][0] + 1;
        output[a][1] = input[0];
        for(int j=0;j<smallOutput2[i][0];++j){
            output[a][j+2] = smallOutput2[i][j+1];
        }
        ++a;
    }
    return temp1+temp2;;
}

void printSubsetSumTok(int* input,int size,int k,int *output,int oSize){
    if(size ==0){
        if(k==0){
            for(int i=0;i<oSize;++i){
                cout<<output[i]<<" ";
            }
            cout<<endl;
            return;
        }
        else return;
    }
    printSubsetSumTok(input+1, size-1,k, output, oSize);
    output[oSize] = input[0];
    printSubsetSumTok(input+1, size-1,k-input[0], output, oSize+1);
    
}


int main(){
    int arr[]={2,1,4,3};
//    int output[100][50];
//    int ans = subsetSumToK(arr, 4, output, 4);
//    for(int i=0;i<ans;++i){
//        for(int j=1;j<=output[i][0];++j){
//            cout<<output[i][j]<<" ";
//        }
//        cout<<endl;
//    }
    int output[100] = {0};
    printSubsetSumTok(arr, 4, 4, output, 0);
    
}
