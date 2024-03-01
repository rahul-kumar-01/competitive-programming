#include<iostream>
using namespace std;

int getCodes(string input, string output[10000]) {
    if(input.length()==0){
        output[0] = "";
        return 1;
    }
    
    string smallOutput1[100];
    string smallOutput2[100];
    
    int firstNum = input[0] - '0';
    char firstChar = firstNum + 'a' - 1;
    
    
    int ans1 = getCodes(input.substr(1), smallOutput1);
    int ans2 = 0;
    char secondChar = '\0';
    
    if(input[1] != '\0'){
        int secondTemp = input[1] - '0';
        int secondNum = (firstNum*10) + secondTemp;
        secondChar  = secondNum + 'a' -1;
        if(secondNum >=10 && secondNum <=26){
            ans2 = getCodes(input.substr(2), smallOutput2);
        }
    }
    int k = 0;
    for(int i=0;i<ans1;++i){
        output[k++] = firstChar + smallOutput1[i];
    }
    for(int i=0;i<ans2;++i){
        output[k++] = secondChar + smallOutput2[i];
    }
    return ans1 + ans2;
}

void printAllPossibleCodes(string input,string output) {
    if(input.length()==0) {
        cout<<output<<endl;
        return;
    }
    
    int firstNum = input[0] - '0' ;
    char firstChar = firstNum + 'a' -1;
    printAllPossibleCodes(input.substr(1), output + firstChar);
    
    
    if(input[1] != '\0'){
        int second = input[1] - '0';
        int secondNum = (firstNum* 10) + second;
        if(secondNum >= 10 && secondNum<=26){
            char secondChar = secondNum + 'a' -1;
            printAllPossibleCodes(input.substr(2), output + secondChar);
        }
    }
    
    
   
}

int main(){
    string output[1000];
    string input;
    cin>>input;
//    int ans = getCodes(input, output);
//    cout<<ans<<endl;
//    for(int i=0;i<ans;++i){
//        cout<<output[i]<<endl;
//    }
    printAllPossibleCodes(input, "");
}
