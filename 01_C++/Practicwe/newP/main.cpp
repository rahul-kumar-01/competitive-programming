#include<iostream>
using namespace std;


void reverseStringWordWise(char input[]) {
    int n1 = strlen(input);
 int len=0;
int i=0;
/*while(input[i] != ‘\0’){
    len++;
    i++;
}*/


int start = 0;
int end = n1 - 1;
while(start<end){
    swap(input[start], input[end]);
    start++;
    end-- ;
}

i=0;
while(input[i] != '\0'){
    cout<<"rahul"<<endl;

    start=i;
    while(input[i] != '\0' && input[i] != ' '){
        cout<<"123"<<endl;
        i++;
      }
    end=i-1;

     while(start<end){
         swap(input[start], input[end]);
         start++;
         end--;
     }
    ++i;
  
}

}
int main(){
//    char input[] = {'a','b','c',' ', 'r','a',' ','m','r','\0'};
//    cout<<strlen(input)<<endl;
//    reverseStringWordWise(input);
//    for(int i=0;i<strlen(input);++i){
//        cout<<input[i]<<" ";
//    }
//    cout<<endl;
    int a =  3*3 / 2 * 2 *2 /4%4+9/4*2;

    cout<<a<<endl;
}

