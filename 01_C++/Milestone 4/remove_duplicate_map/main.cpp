#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
vector<int> removeDuplicate(int * a ,int n){
    vector<int> ans;
    unordered_map<int , bool> seen;
    for(int i=0;i<n;++i){
        if(seen.count (a[i])>0){  //error (seen.count(a[i]>0) not give corrent output
            continue;
        }
        seen[a[i]] = true;
        ans.push_back(a[i]);
    }
    return ans;
    
}
int main(){
    int a[]= {3,5,2,6,34,2,6,8,5,4,7,2};
    vector<int> output = removeDuplicate(a,12);
    for(int i=0;i<output.size();++i){
        cout<<output[i]<<" ";
    }
    cout<<endl;
}
