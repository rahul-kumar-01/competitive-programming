#include <iostream>
#include<unordered_map>
using namespace std;

int pairSumToZeroCount(int *arr, int n) {
    
    
    unordered_map<int,int>freq;
    int pairCount = 0;
    for (int i = 0; i < n; ++i) {
        int complement = -arr[i];
//        if (freq[complement]>0) {
        if (freq. find(complement) != freq.end()) {
            pairCount += freq [ complement ] ;
        }
        ++freq[arr [i]];
    }
    return pairCount;
}




int main() {
    int n;
    cin >> n;
    int* arr = new int[n];
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    cout << pairSumToZeroCount(arr, n)<<endl;
    delete[] arr;
}

//return count how much pair sum to zero
