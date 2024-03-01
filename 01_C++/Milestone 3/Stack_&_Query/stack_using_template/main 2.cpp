#include<iostream>
using namespace std;
template <typename t>
class StackUsingArray{
    
    t * data;
    int startIndex;
    int capacity;
public:
    StackUsingArray(){
        data = new t [5];
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
    t pop(){
        if(isEmpty()){
            cout<<"stack is empty"<<endl;
            return 0;  //zero is null data type, character bool int float 
        }
        startIndex--;
        return data[startIndex];
    }
    t top(){
        return data[startIndex-1];
    }
    void push(t element){
        if(startIndex == capacity){
            t * data2 = new t[2*capacity];
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
    StackUsingArray <char> s;
    s.push(100);
    s.push(101);
    s.push(102);
    s.push(103);
    s.push(104);
    

    cout<<s.top()<<endl;
    cout<<s.pop()<<endl;
    cout<<s.pop()<<endl;
    cout<<s.pop()<<endl;
    cout<<s.size()<<endl;
    cout<<s.isEmpty()<<endl;
}

