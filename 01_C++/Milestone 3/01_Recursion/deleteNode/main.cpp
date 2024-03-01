// verified 

#include<iostream>
using namespace std;
#include"Node.h"

Node *deleteNode(Node *head, int pos){
    if(head == NULL) return NULL;
    if(pos == 0){
        Node * temp = head->next;
        head->next = NULL;
        delete head;
        return temp;
    }
    int count = 0;
    Node* temp = head;
    
    while(count != pos-1 && temp != NULL){
        temp = temp->next;
        ++count;
    }
    if(temp!=NULL && temp->next!=NULL){
        temp->next = temp->next->next;
    }
    return head;
}

Node *deleteNodeRec(Node *head, int pos) {
    if(head == NULL) return NULL;
    if(pos == 0){
        return head->next;
    }
    Node* ans = deleteNodeRec(head->next, pos-1);
    
    head->next = ans;
    return head;
}





int main(){
    Node * head = takeInput();
    print(head);
//    head = deleteNode(head, 0);
//    print(head);
//    head = deleteNode(head, 2);
//    print(head);
//    head = deleteNode(head,5);
//    print(head);
    head= deleteNodeRec(head, 0);
    print(head);
    head= deleteNodeRec(head, 2);
    print(head);
    
}
