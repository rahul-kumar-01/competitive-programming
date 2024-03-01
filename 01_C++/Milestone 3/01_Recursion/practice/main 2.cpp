#include<iostream>
#include<string>
using namespace std;

string sub(string s){
    if(s.length()==0){
        return "";
    }
    string temp = sub(s.substr(1));
    bool flag = true;
    
    for(int i=1;i<=temp.length();++i){
        if(s[i] != temp[i-1]) {
            flag = false;
            break;
        }
    }
    
    
    if(flag == true){
        if(s[0] == temp[0]) return temp;
        else return s[0] + temp;
    }
    return temp;
}


int main(){
    cout<<pow(2,3)<<endl;
}
