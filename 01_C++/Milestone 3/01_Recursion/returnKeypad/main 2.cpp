#include<iostream>
using namespace std;

string getString(int n){
    if(n==2) return "abc";
    if(n==3) return "def";
    if(n==4) return "ghij";
    else return "";
}

int returnKeypad(int num,string output[]){
    if(num == 0){
        output[0] = "";
        return 1;
    }
    
    string soutput[100];
    int lastDigit = num%10;
    string temp = getString(lastDigit);
    num = num/10;
    int smallOutput = returnKeypad(num ,soutput);
    
    
    int k = 0;
    for(int i=0;i<temp.length();++i){
        for(int j=0;j<smallOutput;++j){
            output[k++] = soutput[j] + temp[i];
        }
    }
    return k;
}


void printKeypad(int num,string output){
    if(num == 0) {
        cout<<output<<endl;
        return;
    }
    string temp = getString(num%10);
    num = num/10;
    
    for(int i=0;i<temp.length();++i){
        printKeypad(num,temp[i] +  output );
    }
}





int main(){
    int num;
    cout<<"enter the keypad number : ";
    cin>>num;
//    string output[100] ;
//    int size = returnKeypad(num,output);
//    for(int i=0;i<size;++i){
//        cout<<output[i]<<endl;
//    }
    
    
    printKeypad(num, "");
    
}
