#include<iostream>
using namespace std;

int  print_subsequence(string input,string output[]){
    if(input.empty()){
        output[0]="";
        return 1;
    }
    string smallOutput[100];
    int ans=print_subsequence(input.substr(1), smallOutput);
    int k=0;
    for(int i=0;i<ans;++i){
        for(int j=0;j<=smallOutput[i].length();++j){
            output[k++]=smallOutput[i].substr(0,j)+input[0]+smallOutput[i].substr(j);
        }
    }
    return k;
}



int main(){
    string input;
    cin>>input;
    string output[1000];
    int ans=print_subsequence(input,output);
    for(int i=0;i<ans;++i){
        cout<<output[i]<<endl;
    }
    
}
           
