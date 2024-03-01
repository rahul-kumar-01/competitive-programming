#include<iostream>
using namespace std;
class StackUsingArray{
    int * data;
    int startIndex;
    int capacity;
public:
    StackUsingArray(){
        data = new int[5];
        startIndex = 0;
        capacity = 5;
    }
    int size(){
        return startIndex;
    }
   
    bool isEmpty(){
        //if(startIndex==0) return true;
        //else return false;
        return startIndex==0;
    }
    int pop(){
        if(isEmpty()){
            cout<<"stack is empty"<<endl;
            return INT_MIN;
        }
        startIndex--;
        return data[startIndex];
    }
    int top(){
        return data[startIndex-1];
    }
    void push(int element){
        if(startIndex == capacity){
            int * data2 = new int[2*capacity];
            for(int i=0;i<capacity;++i){
                data2[i] = data[i];
            }
            capacity = 2* capacity;
            delete[]data;
            data = data2;
        }
            data[startIndex] = element;
            startIndex++;
    }
    
};

int main(){
    StackUsingArray s;
    s.push(100);
    s.push(200);
    s.push(300);
    s.push(400);
    s.push(500);
    

    cout<<s.top()<<endl;
    cout<<s.pop()<<endl;
    cout<<s.pop()<<endl;
    cout<<s.pop()<<endl;
    cout<<s.size()<<endl;
    cout<<s.isEmpty()<<endl;
}
