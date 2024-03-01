#include<iostream>
using namespace std;
#include"queue.h"
class Node{
public:
    int data;
    Node * next ;
    Node(int data){
        next = NULL;
        this->data = data;
    }
};

class stack{
    Node * head;
    int size;
public:
    stack(){
        head = NULL;
        size = 0;
    }
    
    void push(int data){
        Node * newNode = new Node(data);
        if(head == NULL) head = newNode;
        else{
            head->next = newNode;
            head = newNode;
        }
        ++size;
    }
    
    int top(){
        return head->data;
    }
    
};
int main(){
    queue s1(100);
    s1.push(45);
    s1.push(34);
    cout<<s1.top()<<endl;
}
