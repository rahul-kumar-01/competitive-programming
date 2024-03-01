#include <iostream>
#include <unordered_map>
using namespace std;
int highestFrequency(int * arr,int n){
    unordered_map<int, int> map1;
    for(int i=0;i<n;++i){
        ++map1[arr[i]];
    }
    int maxNumber = -1;
    int maxFrequency = 0;
    for(int i=0;i<n;++i){
        if(maxFrequency < map1[arr[i]]){
            maxFrequency = map1[arr[i]];
            maxNumber = arr[i];
        }
    }
    return maxNumber;
}



int main() {
    int n;
    cin >> n;
    int* arr = new int[n];
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    cout << highestFrequency(arr, n)<<endl;
    delete[] arr;
}



//HINT :
// considered these two cases [ 1,2,2,1] output is 1
// [1,2,3,4] output is1

