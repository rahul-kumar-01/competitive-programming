#include<iostream>
using namespace std;
void getcodes(string input,string output){
    if(input.empty()) {
        cout<<output<<endl;
        return;
    }
    int first_number=input[0]-48;
    char first_char='a'+first_number-1;
   
    
    getcodes(input.substr(1),output+first_char);
    
    if(input[1]!='\0'){
        int second_number=first_number*10+input[1]-48;
        if(second_number>=10 && second_number<=26){
            char second_char='a'+second_number-1;
            getcodes(input.substr(2),output+second_char);
        }
    }
}
int main(){
    string input;
    string output="";
    cin>>input;
    getcodes(input,output);
    
}
