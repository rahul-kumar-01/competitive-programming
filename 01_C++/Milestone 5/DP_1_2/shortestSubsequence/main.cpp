#include <iostream>
using namespace std;
#include <cstring>
#include <climits>
#define MAX 1000




int helper_3(string s,string v,int sLen,int vLen,int ** arr){
    for(int i=0;i<=vLen;++i){
        arr[sLen][i] = MAX;
    }
    for(int i=0;i<sLen;++i){
        arr[i][vLen] = 1;
    }
    
    for(int i=sLen-1;i>=0;--i){
        char sFirstChar = s[i];
        for(int j=vLen-1;j>=0;--j){
            int a;
            for(a =j;a<vLen;++a){
                if(sFirstChar == v[a]){
                   
                    break;
                }
            }

            if(a==vLen){
                arr[i][j] = 1;
            }
            else{
                arr[i][j] = min(arr[i+1][j] , (arr[i+1][a+1]+1));
                
            }
            
        }
    }
    int ans =   arr[0][0];
    if(ans >= MAX){
        ans = -1;
    }
    return ans;
}
    



int shortestUnSub_3(string s, string v){
    int sLen = s.length();
    int vLen = v.length();
    int ** arr = new int*[sLen+1];
    for(int i=0;i<sLen+1;++i){
        arr[i] = new int [vLen+1];
    }
    return helper_3(s,v,sLen,vLen,arr);
}




int helper(string s, string v) {
    if (s.length() == 0) return MAX-1;
    if (v.length() <= 0) return 1;
   
    int i=0;
    for(i=0;i<v.length();++i){
        if(v[i] == s[0]){
            break;
        }
    }
    if(i == v.length()) return 1;
    int a = helper(s.substr(1), v);
    int b  = helper(s.substr(1), v.substr(i+1)) +1;
    return min(a, b);
    }
    
    
int shortestUnSub(string s, string v){
    int ans = helper(s,v);
    if(ans >= MAX) return -1;
    else return ans;
}

int main() {
    string s, v;
    cin >> s >> v;
    long result = shortestUnSub(s, v);
    cout << "Length of the shortest subsequence not present in V: " << result << endl;
    result = shortestUnSub_3(s, v);
    cout << "Length of the shortest subsequence not present in V: " << result << endl;
    return 0;
}

