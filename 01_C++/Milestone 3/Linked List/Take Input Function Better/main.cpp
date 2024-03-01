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
    
    int main(){
        Node *head =take_input();
        
        print(head);
        
    }

