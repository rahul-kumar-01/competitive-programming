#include<iostream>
using namespace std;


int helper(int a,int b,int*output,int current){
    output[0] = 1;
        for(int i=1;i<=a;++i){
       
        for(int j = 1;j<=pow(i,((1.0)/b));++j){
            output[i] += output[i - (int)(pow(j,b))];
        }
    }
    return output[a];
}

int allPossibleWays_3(int a,int b){
    int * output = new int[a+1];
    for(int i=0;i<a+1;++i){
        output[i] = 0;
    }
    
    int ans = helper(a,b,output,1);
    for(int i=0;i<a+1;++i){
        cout<<output[i]<<endl;
    }
    return ans;
}


int allPossibleWays(int a,int b,int unique){
    if(a == 0 ) return 1;
    if(b == 0) return 0;
    int ans = 0;
    for(int i= unique;i<=pow(a,((1.0)/b));++i){
        int temp = allPossibleWays(a - pow(i,b), b,i+1);
        
        ans += temp;
    }
    return ans;
}




int main(){
    int a,b;
    cin>>a>>b;
    cout<<allPossibleWays(a,b,1)<<endl;
    cout<<allPossibleWays_3(a,b);
}
