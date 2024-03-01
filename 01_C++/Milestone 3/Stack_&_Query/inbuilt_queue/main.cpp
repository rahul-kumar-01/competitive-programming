//we use  inbuilt function of queue
//1. enqueue(t element)   -> void push(t element)
//2. t front()            -> t front()
//3. t dequeue()          -> void pop()
//4. int getSize()        ->int size()
//5. bool isEmpty()       ->bool empty()
                        //->t back();


//int* stockSpan(int *price, int size)  {
//    // Write your code here
//    int * output = new int[size];
//    int count = 0;
//
//    for(int i=0;i<size;++i){
//        int current_number = price[i];
//        count = 1;
//        for(int j=i-1;j>=0;--j){
//            if(current_number>price[j]){
//                ++count;
//            }
//            else{
//                break;
//            }
//        }
//
//        output[i] = count;
//
//    }
//
//    return output;
//}






#include<iostream>
#include<stack>
#include<queue>
using namespace std;
int main(){
//    string s1 ="abcdefg";
//    cout<<s1<<endl;
//    size_t n = s1.find("efgh",0,2);
//    cout<<n<<endl;
//    cout<<(n != string::npos)<<endl;
//    string s2 = "Hello";
//
//    size_t n =  s2.find("Hello",0,3);
//    cout<<(n != string::npos)<<endl;
    
    queue<int> q1;
    stack<int> s1;

    q1.push(10);
    q1.push(20);
    cout<<q1.front()<<endl;
    cout<<q1.back()<<endl;
    cout<<q1.size()<<endl;
    q1.pop();
    cout<<q1.size()<<endl;
    cout<<q1.front()<<endl;
    cout<<q1.back()<<endl;
    q1.pop();
    cout<<q1.empty()<<endl;
    
   
    
}
