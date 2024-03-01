//////////#include <iostream>
//////////#include <unordered_map>
//////////using namespace std;
//////////
//////////char most_frequent_char(string str) {
//////////    unordered_map<char, int> freq_map;
//////////     for(char c : str) {
//////////        freq_map[c]++;
//////////    }
//////////
//////////    char most_freq_char = ' ';
//////////    int max_freq = 0;
//////////    for(auto it = freq_map.begin(); it != freq_map.end(); ++it) {
//////////        if(it->second > max_freq) {
//////////            max_freq = it->second;
//////////            most_freq_char = it->first;
//////////        }
//////////    }
//////////    return most_freq_char;
//////////}
//////////
//////////int main() {
//////////    int n;
//////////    cin>>n;
//////////    string * s1 = new string[n];
//////////    for(int i=0;i<n;++i){
//////////          cin>>s1[i];
//////////    }
//////////
//////////    for(int i=0;i<n;++i){
//////////            char most_freq_char = most_frequent_char(s1[i]);
//////////            cout << most_freq_char << endl;
//////////    }
//////////
//////////    return 0;
//////////
//////////}
//////////
////////
////////#include <iostream>
////////#include <vector>
////////#include <map>
////////using namespace std;
////////
////////int main() {
////////    int n, k;
////////    cin >> n >> k;
////////    vector<int> arr(n);
////////    for(int i=0; i<n; i++) {
////////        cin >> arr[i];
////////    }
////////
////////    map<int, int> freq;
////////    for(int i=0; i<n; i++) {
////////        freq[arr[i]]++;
////////    }
////////
////////    int moves = 0;
////////    for(auto it : freq) {
////////        int x = it.first;
////////        int cnt_x = 0;
////////        for(int i=0; i<n; i++) {
////////            if(arr[i] != x && i+k < n && arr[i+k] == x) {
////////                cnt_x++;
////////            }
////////        }
////////        moves += (n - cnt_x - it.second);
////////    }
////////
////////    cout << moves << endl;
////////
////////    return 0;
////////}
//////
//////#include <cmath>
//////#include <cstdio>
//////#include <vector>
//////#include <iostream>
//////#include <algorithm>
//////
//////using namespace std;
//////
//////int main() {
//////    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
//////    int n;
//////    cin >> n;
//////
//////    vector<int> temp(n);
//////
//////    for(int i = 0; i < n; i++){
//////        cin >> temp[i];
//////    }
//////
//////    vector<int> sol(n, 1);
//////
//////    long long int ans = 0;
//////
//////    for(int i = 0; i < n; i++){
//////        if(i == 0){
//////            if(i+1 < n && temp[i] > temp[i+1]){
//////                sol[i] = max(sol[i], sol[i+1] + 1);
//////            }
//////        }
//////        else if(i != n-1){
//////            if(temp[i] > temp[i+1]){
//////                sol[i] = max(sol[i], sol[i+1] + 1);
//////            }
//////            if(temp[i] > temp[i-1]){
//////                sol[i] = max(sol[i], sol[i-1] + 1);
//////            }
//////        }
//////    }
//////
//////    for(int i = n-1; i >= 0; i--){
//////        if(i == n-1){
//////            if(i-1 >= 0 && temp[i] > temp[i-1]){
//////                sol[i] = max(sol[i], sol[i-1] + 1);
//////            }
//////        }
//////        else if(i != 0){
//////            if(temp[i] > temp[i+1]){
//////                sol[i] = max(sol[i], sol[i+1] + 1);
//////            }
//////            if(temp[i] > temp[i-1]){
//////                sol[i] = max(sol[i], sol[i-1] + 1);
//////            }
//////        }
//////        else{
//////            if(temp[i] > temp[i+1]){
//////                sol[i] = max(sol[i], sol[i+1] + 1);
//////            }
//////        }
//////    }
//////
//////    for(int i = 0; i < n; i++){
//////        ans = ans + sol[i];
//////    }
//////
//////    cout << ans << endl;
//////
//////    return 0;
//////}
////
////// C++ code to find elements whose
////// frequency is more than n/k
////#include<iostream>
////using namespace std;
////
////
////void morethanNbyK(int arr[], int n, int k)
////{
////    int x = n / k;
////
////    // unordered_map initialization
////    unordered_map<int, int> freq;
////
////    for (int i = 0; i < n; i++) {
////        freq[arr[i]]++;
////    }
////
////    // Traversing the map
////    for (auto i : freq) {
////
////        // Checking if value of a key-value pair
////        // is greater than x (where x=n/k)
////        if (i.second > x) {
////
////            // Print the key of whose value
////            // is greater than x
////            cout << i.first - << endl;
////        }
////    }
////}
////
////// Driver Code
////int main()
////{
////    int arr[] = { 4,2,2,2 };
////    int n = sizeof(arr) / sizeof(arr[0]);
////    int k =2;
////
////    morethanNbyK(arr, n, k);
////
////    return 0;
////}
////
////// This code is contributed by chayandas018
//
//// C++ program to find sum of boundary elements
//// of matrix.
//#include <iostream>
//using namespace std;
//
//const int MAX = 100;
//
//int getBoundarySum(int a[][MAX], int m, int n)
//{
//    long long int sum = 0;
//    for (int i = 0; i < m; i++) {
//        for (int j = 0; j < n; j++) {
//            if (i == 0)
//                sum += a[i][j];
//            else if (i == m - 1)
//                sum += a[i][j];
//            else if (j == 0)
//                sum += a[i][j];
//            else if (j == n - 1)
//                sum += a[i][j];
//        }
//    }
//    return sum;
//}
//
//// Driver code
//int main()
//{
//    int a[][MAX] = { { 3,2 },
//                    { 1,2 },
//                    };
//
//    // Function call
//    long long int sum = getBoundarySum(a, 2,2);
//    cout << "Sum of boundary elements is " << sum;
//    return 0;
//}





#include<iostream>
using namespace std;
int main(){
    cout<<"hello world"<<endl;
    return 0;
}



