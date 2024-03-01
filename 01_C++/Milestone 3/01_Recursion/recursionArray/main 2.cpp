#include<iostream>
using namespace std;

int firstIndex(int input[], int size, int x) {
    if(size == 0) return -1;
    if(input[0] == x) return 0;
    int temp =  firstIndex(input+1, size-1, x);
    if(temp == -1) return -1;
    else return 1 + temp;
}

//from front side

int lastIndex(int input[],int size,int x){
    if(size == 0) return -1;
    int temp = lastIndex(input+1, size-1, x);
    
    if(temp == -1){
        if(input[0] == x) return 0;
        else return -1;
    }
    
    return 1+ temp;
}



int allIndexes(int input[], int size, int x, int output[]) {
    if(size == 0) return 0;
    int smallOutputSize = allIndexes(input+1, size-1, x, output);
    if(input[0] == x){
        for(int i=smallOutputSize;i>0;--i){
            output[i] = output[i-1] + 1;
        }
        output[0] = 0;
        return 1 + smallOutputSize;
    }
    else{
        for(int i=0;i<smallOutputSize;++i){
            output[i] = output[i] + 1;
        }
        return smallOutputSize;
    }
    
}



int main(){
    int input[10]= {1,3,4,1,5,6,7,3,12,10};
    
    
}
