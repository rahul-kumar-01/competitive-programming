#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> longestConsecutiveIncreasingSequence(int *arr, int n) {

    unordered_map<int, bool> map1;
    unordered_map<int, int> map2;       // element to index mapping
    for(int i=0;i<n;++i){
        map1[arr[i]] = false;
        map2[arr[i]] = i;
    }
    
    int totalMaxCount = INT_MIN;
    vector<int>outputVector;
    int tempIndex = 1000;

    
    for(int i=0;i<n;++i){
        if(map1[arr[i]] == true) continue;
        int firstIndex = arr[i];

        int firstIndex2 = arr[i]+1;
        int subCount = 0;
        vector<int> output;

        while(map1.count(firstIndex)>0 && map1[firstIndex] == false){
                ++subCount;
//                output.push_back(firstIndex);
                map1[firstIndex] = true;
                --firstIndex;
        }
        output.push_back(firstIndex+1);


            while(map1.count(firstIndex2)>0 && map1[firstIndex2] == false){
                ++subCount;
//                output.push_back(firstIndex2);
                map1[firstIndex2] = true;
                ++firstIndex2;
            }
        output.push_back(firstIndex2-1);

        if(totalMaxCount <= subCount){
            if(totalMaxCount == subCount){
                if(tempIndex > map2[firstIndex+1]){
                    tempIndex = map2[firstIndex+1];
                    totalMaxCount = subCount;
                    outputVector = output;
                }
            }
            else{
                tempIndex = map2[firstIndex+1];
                totalMaxCount = subCount;
                outputVector = output;
            }
            
        }
    }
    return outputVector;
}



int main() {
    int size;
    cin >> size;
    int* arr = new int[size];
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }
    vector<int> ans = longestConsecutiveIncreasingSequence(arr, size);
    for (auto i = ans.begin(); i != ans.end(); ++i)
        cout << *i << " ";
    delete[] arr;
}

