#include<iostream>
using namespace std;
#include<climits>
#include<cmath>


int min_count_1_helper(int n,int count){
    if(n<=0) return 0;
    for(int i=1;i<=(int)(sqrt(n));++i){
        int rem = n - pow(i,2);
        int ans = min_count_1_helper(rem,count)+1;
        
        if(count>ans){
            count = ans;
        }
    }
    return count;
}
int min_count_1(int n){
    return min_count_1_helper(n,INT_MAX);
}

int helper_worst(int * arr, int value,int count,int size){
    
    if(value == 0) {
//        cout<<count<<endl;
        return count;
    }
    if(value<0) return 0;
    if(size ==0) return 0;

    int ans1 = helper_worst(arr,value-pow(arr[0],2),count + 1,size);
    int ans2 = helper_worst(arr+1,value,count,--size);
    if(ans1 != 0 && ans2!=0) return min(ans1,ans2);
    if(ans1 == 0) return ans2;
    if(ans2 == 0) return ans1;
    else return 0;

}

int minCount_worst(int n){
    int boobs = (int)(sqrt(n));
    int * arr = new int[boobs];
    for(int i=0;i<boobs;++i){
        arr[i] = i+1;
    }
    return helper_worst(arr,n,0,boobs);
}



int main(){
    int n;
    cout<<"Enter the integer : ";
    cin>>n;
   
    cout<<minCount_worst(n)<<endl;
    cout<<min_count_1(n)<<endl;
  
}

