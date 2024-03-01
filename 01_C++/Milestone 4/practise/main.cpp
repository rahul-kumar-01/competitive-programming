
#include <iostream>
using namespace std;

class Box{
    public :
    int width;
    int height;
    int length;
    void volume(){
        cout << length * width * height;
    }
};

int main() {
    Box b;
    b.height = 5;
    b.width = 4;
    b.volume();
    cout<<b.length<<endl;
    
}
//#include<iostream>
//#include <stack>
//using namespace std;
//
//
//void reverseStringWordWise(char input[]) {
//    stack<char>c;
//  for(int i=0;input[i]!='\0';i++){
//      c.push(input[i]);
//  }
//    int k;
//  for(k=0;input[k]!='\0';k++){
//      input[k]=c.top();
//      c.pop();
//  }
//    input[k] = '\0';
//
//  int i=0; int x=0;
////
////    for(int i=0;input[i] !='\0';++i){
////        cout<<input[i]<<" ";
////    }
////    cout<<endl;
//
//while(input[i]!='\0'){
//
//  stack<char>u;
//  while(input[i] != '\0' && input[i]!=' '){
//     u.push(input[i]);
//      i++;
//  }
//
//  while(u.size()!=0){
//      cout<<u.top()<<" ";
//      input[x]=u.top();
//      u.pop();
//      ++x;
//  }
//    ++i;
//
//  }
//}
//
//int main(){
//    char str[] = {'r','a','m',' ','i','s',' ','g','o','d'};
//    reverseStringWordWise(str);
//    for(int i=0;i<3;++i){
//        cout<<str[i]<<" ";
//    }
//}
