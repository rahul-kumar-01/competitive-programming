#include<iostream>
using namespace std;


int helper_3(int * winner ,int n,int x,int y){
    
    winner[1] = 1;
    winner[x] = 1;
    winner[y] = 1;
    
    for(int i=2;i<=n;++i){
        if( (1^(winner[i-1])) == 1){
            winner[i] = 1;
        }
        if(i-x>0){
            if(1^(winner[i-x] == 1)){
                winner[i] = 1;
            }
            if(i-y>0){
                if(1^(winner[i-y] == 1)){
                    winner[i] = 1;
                }
            }
        }

    
    }
    return winner[n];
}

string findWinner_3(int n,int x,int y){
    int * winner = new int[n+1];
    for(int i =0;i<n+1;++i){
        winner[i] = 0;
    }

    int ans =  helper_3(winner,n,x,y);
    if(ans == 1) return "Beerus";
    else return "Whis";
}


bool helper(int n,int x,int y){
    if(n==1 || n==x || n==y) return true;
    if (n < 1 ) return true;
    bool a = helper(n-1,x,y);
    bool b = helper(n-x,x,y);
    bool c = helper(n-y,x,y);
    if (a == false || b == false || c == false) return true;
    else return false;
}


string findWinner(int n, int x, int y){
    bool ans = helper(n,x,y);
    if(ans == true) return "Beerus";
    else return "Whis";
}


int main(){
    int n,x,y;
    cin>>n>>x>>y;
    cout<<findWinner(n, x, y)<<endl;
    cout<<findWinner_3(n, x, y)<<endl;
 
//    int a = 0^0^0;
//    cout<<a<<endl;
}
