#include<iostream>
#include<cmath>
using namespace std;


int LCS_3_helper(string s1,string s2,int ** solution){
    long m = s1.length();
    long n = s2.length();
 
    
    for(int i=0;i<=n;++i){
        solution[0][i] = 0;
    }
    for(int i=0;i<=m;++i){
        solution[i][0] = 0;
    }
    for(int i=1;i<=m;++i){
        for(int j=1;j<=n;++j){
            if(s1.substr(m-i)[0] == s2.substr(n-j)[0]) {
                solution[i][j] = 1+solution[i-1][j-1];
            }
            else{
                int temp = max(solution[i-1][j] , max(solution[i][j-1] , solution[i-1][j-1]));
                solution[i][j] = temp;
            }
        }
    }
    return solution[m][n];
}



int LCS_3(string s1,string s2){
    long m = s1.length();
    long n = s2.length();
    int ** solution = new int*[m+1];
    for(int i=0;i<=m;++i){
        solution[i] = new int[n+1];
    }
    return LCS_3_helper(s1,s2,solution);
}

int LCS_2_helper(string s1,string s2,int ** solution){
    if(s1.length() ==0 || s2.length() ==0) return 0;
    
    long m = s1.length();
    long n = s2.length();
    if(solution[m][n] != -1){
        return solution[m][n];
    }
    
    if(s1[0] == s2[0]){
        solution[m][n] =  LCS_2_helper(s1.substr(1), s2.substr(1),solution) + 1;
        return  solution[m][n];
    }
    
    
    int ans1 = LCS_2_helper(s1.substr(1), s2,solution);
    int ans2 = LCS_2_helper(s1 , s2.substr(1),solution);
    int ans3 = LCS_2_helper(s1.substr(1),s2.substr(1),solution);
    
    solution[m][n] =  max(ans1,max(ans2,ans3));
    return solution[m][n];
}


int LCS_2(string s1,string s2){
    long m = s1.length();
    long n = s2.length();
    
    int ** solution = new int*[m+1];
    for(int i=0;i<=m;++i){
        solution[i] = new int[n+1];
        for(int j=0;j<=n;++j){
            solution[i][j] = -1;
        }
    }
    return LCS_2_helper(s1,s2,solution);
}




int LCS_1(string s1,string s2){
    if(s1.length()==0 || s2.length()==0){
        return 0;
    }
    
    if(s1[0] == s2[0]){
        return LCS_1(s1.substr(1), s2.substr(1)) + 1;
    }
    
    int ans1 = LCS_1(s1.substr(1), s2);
    int ans2 = LCS_1(s1 , s2.substr(1));
    int ans3 = LCS_1(s1.substr(1),s2.substr(1));
    
    return max(ans1,max(ans2,ans3));
    
}




int main(){
    string s1;
    string s2;
    cout<<"Enter the string 1 : ";
    cin>>s1;
    cout<<"Enter the string 2 : ";
    cin>>s2;
    cout<<LCS_1(s1,s2)<<endl;
    cout<<LCS_2(s1,s2)<<endl;
    cout<<LCS_3(s1,s2)<<endl;
    return 0;
}
