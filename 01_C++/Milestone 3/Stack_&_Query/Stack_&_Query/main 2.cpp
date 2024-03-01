// A stack represents a sequence of objects or elements in a linear data structure format.
#include<iostream>
using namespace std;
class StackUsingArray{
    int * data;
    int startIndex;
    int capacity;
public:
    StackUsingArray(int capacity){
        data = new int[capacity];
        startIndex = 0;
        this->capacity = capacity;
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
            cout<<" stack is full."<<endl;
            return;
        }
        else{
            data[startIndex] = element;
            startIndex++;
        }
    }
    
};

int main(){
    StackUsingArray s(100);
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
