#include<iostream>
#include<unordered_map>
using namespace std;

int printSumToZero(int arr[],int size){
    unordered_map<int, int> pair;
    int count = 0;
    for(int i=0;i<size;++i){
        ++pair[arr[i]];
    }
    for(int i=0;i<size;++i){
        int temp = arr[i];
        int tempRev = -temp;
        if(pair[tempRev] == 0){
            continue;
        }
        else{
            int value=pair[tempRev];
            int pvalue = pair[temp];
            int noOfPair = value*pvalue;
            for(int j= 0;j<noOfPair;++j){
                ++count;
            }
            pair[arr[i]] = 0;
        }
    }
    
    return count;
}


int main(){
    int arr[13] = {-2, -12, 2, 11, 12, -2, 1 ,-2, 2, -11, 12, 2, 6};
    int size = 13;
    cout<<printSumToZero(arr,size)<<endl;
}

