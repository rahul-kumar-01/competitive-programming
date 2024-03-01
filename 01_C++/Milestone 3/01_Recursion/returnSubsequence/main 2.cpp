#include<iostream>
using namespace std;


int  returnSubsequence(string input,string output[]){
    if(input.length()==0) {
        output[0] = "";
        return 1;
    }
    int smallOutputSize = returnSubsequence(input.substr(1), output);
    int k = smallOutputSize;
    
    for(int i=0;i<smallOutputSize;++i){
        output[k++] = input[0] + output[i];
    }
    return 2*smallOutputSize;
}

void printSubsequence(string input,string output){
    if(input.length()==0){
        cout<<output<<endl;
        return;
    }
    printSubsequence(input.substr(1), output);
    printSubsequence(input.substr(1), output + input[0]);
}

int main(){
    
    string input;
    cout<<"enter the string : ";
    cin>>input;
    
//    string output[100];
//    int size = returnSubsequence(input, output);
    
    
    string output="";
    printSubsequence(input, output);
}
