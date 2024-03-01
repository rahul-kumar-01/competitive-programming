#include<iostream>
using namespace std;
int getcodes(string input,string output[]){
    if(input[0]=='\0'){
        output[0]="";
        return 1;
    }
    int first=input[0]-48;
    char first_char=first+'a'-1;
    
    char second_char='\0';
    string smallOutput1[100];
    string smallOutput2[100];
    
    int size1=getcodes(input.substr(1),smallOutput1);
    int size2=0;
    if(input[1]!='\0'){
    
        int second=(first*10)+input[1]-48;
        if(second>=10 && second<=26){
            second_char='a'+second-1;
            size2=getcodes(input.substr(2),smallOutput2);
        }
    }
    int k=0;
    for(int i=0;i<size1;++i){
        output[k++]=first_char+smallOutput1[i];
    }
    for(int i=0;i<size2;++i){
        output[k++]=second_char+smallOutput2[i];
    }
    return size1+size2;
}
int main(){
    string input;
    string output[1000];
    cin>>input;
    int ans=getcodes(input,output);
    for(int i=0;i<ans;++i){
        cout<<output[i]<<endl;
    }
}
