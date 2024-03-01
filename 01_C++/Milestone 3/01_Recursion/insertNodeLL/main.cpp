#include<iostream>
using namespace std;
#include"Node.h"

Node* insertNode(Node *head, int i, int data) {
    if(head == NULL){
        if(i==0){
            Node* head = new Node(data);
            return head;
        }
        return NULL;
    }
    
 
    int count = 0;
    Node* temp = head;
    while(count != i-1){
        Node* next = temp->next;
        
    }
    
    
    
}


int main(){
    
}
