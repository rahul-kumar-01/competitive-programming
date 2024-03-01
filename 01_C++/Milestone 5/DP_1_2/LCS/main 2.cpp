#include<iostream>
using namespace std;


int LCS_3_helper(string s1,string s2,int ** solution){
    if(s1.length()==0 && s2.length()==0) return 0;
    
    
    
     
    
    return 0;
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
        return LCS_2_helper(s1.substr(1), s2.substr(1),solution) + 1;
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
    int ** solution = new int*[m];
    for(int i=0;i<=m;++i){
        solution[i] = new int[n];
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
