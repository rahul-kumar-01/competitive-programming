#include <iostream>
#include <unordered_map>
using namespace std;

int lengthOfLongestSubsetWithZeroSum(int* arr, int n) {
    unordered_map<int, int> map1;
    int sum = 0;
    int maxLen = INT_MIN;
 
    
    for(int i=0;i<n;++i){
        int currentNum = arr[i]+sum;
        sum = currentNum;
        if(sum == 0){                   //important 
            maxLen = i;
        }
        if(map1.count(sum) == 0){
            map1[sum] = i;
        }
        else{
            int foundNewLen = i - map1[sum];
            if(foundNewLen > maxLen){
                maxLen = foundNewLen;
            }
        }
    }
    return maxLen;
}

int main() {
    int size;
    cin >> size;
    int* arr = new int[size];
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }
    cout << lengthOfLongestSubsetWithZeroSum(arr, size);
    delete[] arr;
}
