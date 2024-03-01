#include<iostream>
#include<cstring>
using namespace std;

//IMP always use null after the char array



void replacePi(char input[]) {
//    long len = strlen(input);
    
//    if(len == 0) return;
//    if(len <= 1) return; is also true
    if(input[0] ==  '\0' || input[1] == '\0') return;
    
    replacePi(input+1);
    if(input[0] == 'p' && input[1] == 'i'){
        for(long i=strlen(input)-1;i>=2;--i){
            input[i+2] = input[i];
        }
        input[0] = '3';
        input[1] = '.';
        input[2] = '1';
        input[3] = '4';
        
    }
    return;
}


void removeX(char input[]) {
    long len = strlen(input);
    if(len == 0) return ;
    removeX(input+1);
    if(input[0] == 'x'){
        long i = 0;
        for(;i<strlen(input)-1;++i){
            input[i] = input[i+1];
        }
        input[i] = '\0';
    }
    return;
}



int stringToNumber(char input[]) {
    return 0;
}

//    long len = strlen(input); is also correct
//    if(len <= 1) return;



void pairStar(char input[]) {
    if(input[0] == '\0' || input[1] == '\0') return;
        pairStar(input+1);
        long len = strlen(input);
    
        if(input[0] == input[1]){
            input[len+1] = '\0';
            long i;
            for(i = len;i>1;--i){
                
                input[i] = input[i-1];
            }
            input[i] = '*';
        }
        return;
}

int main(){
    char input[100] = {'p','p','i','p'};
    pairStar(input);
    
}
