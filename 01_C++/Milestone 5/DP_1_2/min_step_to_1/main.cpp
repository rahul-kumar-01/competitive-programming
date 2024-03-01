#include<iostream>
using namespace std;
#include<cmath>
#include<climits>


int helper_3(int * arr,int n){
    if(n<=1) return 0;
    arr[0] = 0;
    arr[1] = 0;
    
    for(int i=2;i<=n;++i){
        if(i%2==0 && i%3==0){
            arr[i] = min(arr[i-1],min(arr[i/2],arr[i/3])) + 1;
        }
        else if(i%2 ==0){
            arr[i] = min(arr[i-1],arr[i/2]) +1;
        }
        else if(i%3==0){
            arr[i] = min(arr[i-1] ,arr[i/3])+1;
        }
        else{
            arr[i] = arr[i-1] + 1;
        }
    }
    return arr[n];
}



int min_3(int n){
    int * arr = new int[n+1];
    return helper_3(arr,n);
}


int helper_2(int * arr, int n){
    if(n<=1) return 0;
    if(arr[n] != -1){
        return arr[n];
    }
    
    int ans1 = INT_MAX,ans2 = INT_MAX,ans3 =INT_MAX;
    if(n%3==0){
        ans1 = helper_2(arr,n/3) +1;
    }
    if(n%2==0){
        ans2 = helper_2(arr,n/2)+1;
    }
    ans3 = helper_2(arr,n-1)+1;
    arr[n] =  min(ans1,min(ans2,ans3));
    return arr[n];
}


int min_2(int n){
    int * arr = new int[n+1];
    for(int i=0;i<=n;++i){
        arr[i] = -1;
    }
    return helper_2(arr,n);
}




int min_1(int n){
    if(n<=1) return 0;
    int ans1 = INT_MAX,ans2 = INT_MAX,ans3 =INT_MAX;
    if(n%3==0){
        ans1 = min_1(n/3) +1;
    }
    if(n%2==0){
        ans2 = min_1(n/2)+1;
    }
    ans3 = min_1(n-1)+1;
    return min(ans1,min(ans2,ans3));
   
}





//
//int min_step_1(int n,int count){
//    if(n<0) return 0;
//    if(n==0) return 1;
//    for(int i=1;i<=(int)(sqrt(n));++i){
//        int rem_num = n - pow(i,2);
//        int temp = min_step_1(rem_num,count)+1;
//        if(temp < count){
//            count = temp;
//        }
//    }
//    return count;
//}

int main(){
    int n;
    cout<<"enter the integer : ";
    cin>>n;
    
//    cout<<min_step_1(n,INT_MAX)<<endl;
    cout<<min_3(n)<<endl;
    cout<<min_2(n)<<endl;
    cout<<min_1(n)<<endl;
    
}
