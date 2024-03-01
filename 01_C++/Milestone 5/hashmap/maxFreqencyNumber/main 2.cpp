#include<iostream>
#include<unordered_map>
using namespace std;

int maxFrequencyNumber (int arr[],int size){
    int maxFreq = 0;
    unordered_map<int,int>freq;
    for(int i=0;i<size;++i){
        ++freq[arr[i]];
        if(maxFreq < freq[arr[i]]) maxFreq = freq[arr[i]];
    }
    int maxFrequencyNum = 0;
    for(int i=0;i<size;++i){
        if(freq[arr[i]] == maxFreq){
            maxFrequencyNum = arr[i];
            break;
        }
    }
    return maxFrequencyNum;
}

int main(){
    int arr[7] = {2,4,6,2,2,4,5};
    int size = 7;
    cout<<maxFrequencyNumber (arr,size)<<endl;
}
