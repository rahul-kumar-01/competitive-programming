#include<iostream>
#include<cmath>
#include<string>
#include<climits>
using namespace std;


int helper_3(int ** solution, string s1,string s2,long m,long n){
    
    solution[0][0] = 0;
    
    for(int i=1;i<=m;++i){
        solution[i][0] = i;
    }
    
    for(int i=1;i<=n;++i){
        solution[0][i] = i;
    }
    
    for(int i=1;i<=m;++i){
        for(int j=1;j<=n;++j){
            if(s1[m-i] == s2[n-j]){
                solution[i][j] = solution[i-1][j-1];
            }
            else{
                int ans = min(solution[i][j-1],min(solution[i-1][j],solution[i-1][j-1]));
                solution[i][j] = 1 + ans;
            }
        }
    }
    return solution[m][n];
}


int editDistance_3(string s1,string s2){
    long m = s1.length();
    long n = s2.length();
    int ** solution = new int* [m+1];
    for(int i=0;i<=m;++i){
        solution[i] = new int[n+1];
    }
    return helper_3(solution,s1,s2,m,n);
}




int helper_2(int ** solution,string s1,string s2){
    if(s1.length() == 0 && s2.length() == 0){
        return 0;
    }
    if(s1[0] == s2[0]){
        return  helper_2(solution,s1.substr(1), s2.substr(1));
    }
    
    long x = s1.length();
    long y = s2.length();
    if(solution[x][y] != -1){
        return solution[x][y];
    }
    
    
    int ans1 = INT_MAX,ans2 = INT_MAX,ans3 = INT_MAX;
    
    if(s1.length() != 0){
        ans1 = helper_2(solution,s1.substr(1), s2);
    }
    if(s2.length() != 0){
        ans2 = helper_2(solution,s1, s2.substr(1));
    }
    if(s1.length() != 0 && s2.length() != 0){
        ans3 = helper_2(solution,s1.substr(1), s2.substr(1));
    }
    
    int final_ans = 1 + min(ans1,min(ans2,ans3));
    solution[x][y] = final_ans;
    return solution[x][y];
}



int editDistance_2(string s1,string s2){
    
    long m = s1.length();
    long n = s2.length();
    int ** solution = new int*[m+1];
    for(int i=0;i<=m;++i){
        solution[i] = new int [n+1];
        for(int j=0;j<=n;++j){
            solution[i][j] = -1;
        }
    }
    return helper_2(solution,s1,s2);
}



long edit_distance(string s1,string s2){
//    if(s1.length() == 0 && s2.length() == 0){
//        return 0;
//    }
        if(s1.length() == 0 || s2.length() == 0){
            return max(s1.length() , s2.length());
        }
    
    
    if(s1[0] == s2[0]){
        return  edit_distance(s1.substr(1), s2.substr(1));
    }
    
//    int ans1 = INT_MAX,ans2 = INT_MAX,ans3 = INT_MAX;
    
//    if(s1.length() != 0){
       long  ans1 = edit_distance(s1.substr(1), s2);
//    }
//    if(s2.length() != 0){
        long ans2 = edit_distance(s1, s2.substr(1));
//    }
//    if(s1.length() != 0 && s2.length() != 0){
        long ans3 = edit_distance(s1.substr(1), s2.substr(1));
//    }
    
    long final_ans = min(ans1,min(ans2,ans3));
    
    return final_ans + 1;
}



int main(){
    string s1 , s2;
    cout<<"Enter the string 1 : ";
    cin>>s1;
    cout<<"Enter the string 2 : ";
    cin>>s2;
    cout<<edit_distance(s1,s2)<<endl;
    cout<<editDistance_2(s1,s2)<<endl;
    cout<<editDistance_3(s1,s2)<<endl;
}
