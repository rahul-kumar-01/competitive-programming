#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;



vector<int> removeDuplicates(int arr[],int size){
    unordered_map<int , bool> seen;
    vector<int> output;
    for(int i=0;i<size;++i){
        if(seen.count(arr[i])>0){
            continue;
        }
        else{
            seen[arr[i]] = true;
            output.push_back(arr[i]);
        }
    }
    return output;
}
int main(){
    int arr[7] = {4,6,3,4,6,4,2};
    int size = 7;
    vector<int> output = removeDuplicates(arr,size);
    for(int i=0;i<output.size();++i){
        cout<<output[i]<<" ";
    }
    cout<<endl;
}
