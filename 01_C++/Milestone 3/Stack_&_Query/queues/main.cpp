// queues is first in first out like cinema hall ticket buying
// also a abstract data type like stack
// abstract data type - i don't care how my element saved i care about in which order it saved & in which order in coming out
#include<iostream>
using namespace std;
#include"modified.h"
int main(){
    Queues <int> q1(5);

 
    
    //problem with queues.h
//        q1.push(100);
//        q1.push(200);
//        q1.push(300);
//        q1.push(400);
//        q1.push(500);
//        q1.push(600);
//        cout<<q1.pop()<<endl;
//        cout<<q1.pop()<<endl;
//        cout<<q1.pop()<<endl;
//        cout<<q1.pop()<<endl;
//        cout<<q1.pop()<<endl;
//        cout<<q1.pop()<<endl;
//        q1.push(800);
//        cout<<q1.top()<<endl;
//        cout<<q1.getS()<<endl;
//
    
    q1.enqueue(10);
    q1.enqueue(20);
    q1.enqueue(30);
    q1.enqueue(40);
    q1.enqueue(50);
    q1.enqueue(60);
    
    cout<<q1.front()<<endl;
    cout<<q1.dequeue()<<endl;
    cout<<q1.dequeue()<<endl;
    cout<<q1.dequeue()<<endl;
    
    cout<<q1.getSize()<<endl;
    cout<<q1.isEmpty()<<endl;
   
    
    
    
    
    
}
