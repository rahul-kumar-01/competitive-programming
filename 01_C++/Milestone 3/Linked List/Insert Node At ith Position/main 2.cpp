#include<iostream>
using namespace std;
class Node{
public:
    int data;
    Node * next;
    
    Node (int num){
        data = num;
        next = NULL;
    }
};

void print(Node * p){
    Node * temp = p;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

Node* take_input(){
    int num;
    cin>>num;
    Node * head = NULL;
    Node * tail = NULL;
    while(num != -1){
        Node * newNode = new Node(num);
        if(head ==  NULL){
            head = newNode;
            tail = newNode;
        }
        else {
            tail->next = newNode;
            //tail = newNode;
            tail = tail->next;
            
        }
        cin>>num;
    }
    return head;
}
/* for i not equal to zero
void insertNode(Node * head, int index, int data){
    
    Node * newNode = new Node(data);
    int count = 0;
    Node * temp = head;
    while(temp != NULL && count<index-1){      //temp != NULL is optional for seg fault
        temp = temp->next;
        count++;
    }
    if(temp != NULL){         //optional for segemation fault if occur index > no of node
        Node * a = temp->next;
        temp->next = newNode;
        newNode->next = a;
    }
 }
    */
// for i equal to zero
// we have change head so have to return it and also change in main

Node * insertNode(Node * head, int index, int data){
    
    Node * newNode = new Node(data);
    int count = 0;
    Node * temp = head;
    if(index==0){
        newNode->next = head;
        head = newNode;
        return head;
    }
    
    while(temp != NULL && count<index-1){      //temp != NULL is optional for seg fault
        temp = temp->next;
        count++;
    }
    
    if(temp != NULL){         //optional for segemation fault if occur index > no of node
        Node * a = temp->next;
        temp->next = newNode;
        newNode->next = a;
    }
    return head;
}
void delelteIndex(Node * &head,int index){
    int count = 0;
    Node * temp = head;
    if(index == 0){
        head = temp->next;
    }
    while(temp != NULL && count < index -1){
        temp = temp->next;
        ++count;
    }
    if(temp != NULL){
        Node * a = temp->next;
        if(a!=NULL){
            Node * b = a->next;
            temp -> next = b;
        }
    }
    
}



    
    int main(){
        Node *head =take_input();
        insertNode(head, 3, 4);
        delelteIndex(head, 5);
        print(head);
    }


