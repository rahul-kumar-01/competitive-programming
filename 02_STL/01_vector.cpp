#include<iostream>
using namespace std;
int main(){
    vector<int> arr ; // empty vector
    vector<int> arr2 (10) ; // size = 10 , iniliaze to zero
    vector<int> arr3 (10,5); 
    int rowLen = 10, colLen = 10;
    vector<vector<int>> arr (rowLen,vector<int>(colLen));
    
    // function 
    arr.front();
    arr.back();
    arr.empty();            //return boolean
    arr.push_back(10);
    arr.pop_back();
    arr.clear();            //reset the size = 0 arr.empty() is true;
    




}