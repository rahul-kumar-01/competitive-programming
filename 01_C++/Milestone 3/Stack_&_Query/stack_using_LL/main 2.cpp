//#include<iostream>
//using namespace std;
//#include"stack_using_LL.h"      //header have not main funciton
//                                //"" is why ? that we have to search in the current folder
//
//#include<stack>
//
//
////use all stack function, not have write stack class each time
////but when we declare use stack <int> s1;
////difference between we made stack class and inbuilt stack class
////my class vs inbluid class
////1. push(t element)  = s1.push(10) same
////2. t pop() = void pop(); ()donot return value we have to do it manually first top & then pop)
////3. bool isEmpty() = bool empty()
//
//
//int main(){
//    Stack <int> s1;
//
//    s1.push(100);
//    s1.push(101);
//    s1.push(102);
//    s1.push(103);
//    s1.push(104);
//    cout<<s1.top()<<endl;
//    cout<<s1.pop()<<endl;
//    cout<<s1.pop()<<endl;
//    cout<<s1.pop()<<endl;
//    cout<<s1.getSize()<<endl;
//    cout<<s1.isEmpty()<<endl;
//}
//
//char highestOccurringChar(char input[]) {
//    // Write your code here
//    int frequency [256]={0};
//
//
//    for(int i=0;input[i]!='\0';++i){
//
//        ++frequency[input[i]];
//    }
//    char ans=input[0];
//    int counti = frequency[input[0]];
//    for(int i=1;input[i]!='\0';++i){
//
//        if(counti<frequency[input[i]]){
//            ans=input[i];
//            counti=frequency[input[i]];
//        }
//    }
//    return ans;
//}

#include<iostream>
using namespace std;
int main(){
    int frequency [256]={0};
    int n;
    cin>>n;
    int * input = new int[n];
    
    for(int i=0;input[i]!='\0';++i){
        ++frequency[input[i]];
    }
    
    char ans=input[0];
        int counti = frequency[input[0]];
        for(int i=1;input[i]!='\0';++i){
            
            if(counti<frequency[input[i]]){
                ans+=input[i];
                counti=frequency[input[i]];          //imp;
                
                
            }
        }
        
}

