#include<iostream>
using namespace std;
class Node{
public:
    int data;
    Node* next;
    Node(int data){
        this->data = data;
        next = NULL;
    }
};

Node* takeInput(){
    int data;
    cout<<"Enter the data : ";
    cin>> data;
    Node * head = NULL;
    Node * temp = NULL;
    
    while(data != -1){
        Node * newNode = new Node(data);
        if(head == NULL){
            head = newNode;
            temp = newNode;
        }
        head->next = newNode;
        head =  newNode;
        head->next = temp;
        cout<<"Enter the data : ";
        cin>>data;
    }
    return temp;
}

void print(Node * head){
    Node * temp = head;
    do{
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    while(temp != head);{
        cout<<endl;
        return;
    }
    
}

void deletion(Node * temp){
    
}


int main(){
    Node * circularLL = takeInput();
    print(circularLL);
}
