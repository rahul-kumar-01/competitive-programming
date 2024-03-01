/*Longest Consecutive Sequence

You are given an array of unique integers that contain numbers in random order. You have to find the longest possible sequence of consecutive numbers using the numbers from given array.
You need to return the output array which contains starting and ending element. If the length of the longest possible sequence is one, then the output array must contain only single element.

 
 Note:
 1. Best solution takes O(n) time.
 2. If two sequences are of equal length, then return the sequence starting with the number whose occurrence is earlier in the array.

 */
  
// this solution is not 0(n)
// some sample example is below


#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> longestConsecutiveIncreasingSequence(int *arr, int n) {
    // Your Code goes here
    int * arr2 = new int[n];
    for(int i=0;i<n;++i){
        arr2[i] = arr[i];
    }
    vector<int> v1;
    sort(arr,arr+n);
    int count = 1;
    int max = 1;
    int start = 0;
    for(int i=0;i<n-1;++i){
        bool a = false;
        while(i<n-1 && arr[i] == arr[i+1]-1){
            int temp = 0; ;
            while (a == false) {
              temp = i;
              a = true;
            }
            ++count;
            if (max < count) {
              max = count;
              start = temp;
            }
            if(max == count){
                int tempIndex = 0;
                int startIndex = 0;
                for(int i=0;i<n;++i){
                    if(arr[temp] == arr2[i]) tempIndex = i;
                    if(arr[start] == arr2[i]) startIndex = i;
                }
                if(startIndex > tempIndex){
                    start = temp;
                }
            }
            ++i;
        }
        count = 1;
    }
    
        v1.push_back(arr[start]);
        v1.push_back(arr[start+max-1]);
    
    return v1;
}
int main(){
    int n;
    cin>>n;
    int * arr = new int[n];
    for(int i=0;i<n;++i){
        cin>>arr[i];
    }
    vector<int> output = longestConsecutiveIncreasingSequence(arr,n);
    for(int i=0;i<output.size();++i){
        cout<<output[i]<<" ";
    }
    cout<<endl;
}


/*Sample Output 1 :
8 12
Sample Input 2 :
7
3 7 2 1 9 8 41
Sample Output 2 :
7 9
Explanation: Sequence should be of consecutive numbers. Here we have 2 sequences with same length i.e. [1, 2, 3] and [7, 8, 9], but we should select [7, 8, 9] because the starting point of [7, 8, 9] comes first in input array and therefore, the output will be 7 9, as we have to print starting and ending element of the longest consecutive sequence.
Sample Input 3 :
7
15 24 23 12 19 11 16
Sample Output 3 :
15 16

*/
