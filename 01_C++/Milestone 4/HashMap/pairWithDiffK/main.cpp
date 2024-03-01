#include <iostream>
using namespace std;
#include<unordered_map>

int getPairsWithDifferenceK(int *arr, int n, int k) {
    unordered_map<int, int> map1;
    for(int i=0;i<n;++i){
        ++map1[arr[i]];
    }
    int count = 0;
    for(int i=0;i<n;++i){
        int currentNumber = arr[i];
        int find1Num = arr[i] - k;
        int find2Num = arr[i] + k;
        if(map1.count(find1Num)>0){
            count += (map1[currentNumber] * map1[find1Num]);
        }
        if(map1.count(find2Num)>0){
            count +=  (map1[currentNumber] * map1[find2Num]);
        }
        map1[currentNumber] = 0;
    }
    return count;
}
int main() {
    int n;
    cin >> n;
    int *input = new int[n];
    for (int i = 0; i < n; i++) {
        cin >> input[i];
    }
    int k;
    cin >> k;
    cout << getPairsWithDifferenceK(input, n, k);
    delete[] input;
}
