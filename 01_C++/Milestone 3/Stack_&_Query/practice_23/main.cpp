#include<iostream>
using namespace std;

class Node{
public:
    int data;
    Node * next;
    Node(int data){
        this->data  = data;
        next = NULL;
    }
};

class queueUsingLinkedList{
public:
    Node * head;
    Node * tail;
    
    queueUsingLinkedList(){
        head = NULL;
        tail = NULL;
    }
    
    void push(int data){
        Node* newNode = new Node(data);
        if(head == NULL){
            head = newNode;
            tail = newNode;
        }
        tail->next = newNode;
        tail = tail->next;
    }
    
    
    int pop(){
        Node * temp = head;
        int ans = head->data;
        head = head->next;
        delete temp;
        return ans;
    }
    
    int front(){
        return head->data;
    }
    
    int size(){
        Node * temp = head;
        int count = 0;
        while(temp!= NULL){
            temp = temp->next;
            ++count;
        }
        return count;
    }
    
    bool isEmpty(){
        return (head==NULL);
    }
    
    };
    
    


int main(){
    queueUsingLinkedList q1;
    q1.push(10);
    q1.push(12);
    q1.push(34);
    q1.push(56);
    q1.push(78);
    q1.push(99);
    
    cout<<q1.pop()<<endl;
    cout<<q1.pop()<<endl;
    cout<<q1.pop()<<endl;
    cout<<q1.front()<<endl;
    cout<<q1.size()<<endl;
    cout<<q1.isEmpty()<<endl;
    cout<<q1.pop()<<endl;
    cout<<q1.pop()<<endl;
    cout<<q1.pop()<<endl;
    cout<<q1.isEmpty()<<endl;
    cout<<q1.front()<<endl;
    
    
    
}

