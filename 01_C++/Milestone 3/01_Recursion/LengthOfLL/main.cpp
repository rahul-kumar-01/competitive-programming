#include<iostream>
using namespace std;
#include"Node.h"

int lenLL(Node * head){
    Node * temp = head;
    int count = 0;
    while(temp != NULL){
        temp= temp->next;
        ++count;
    }
    return count;
}

int lenLLRec(Node * head){
    if(head == NULL) return 0;
    return 1 + lenLLRec(head->next);
}
int main(){
    Node * head = takeInput();
    print(head);
    cout<<lenLL(head)<<endl;
    cout<<lenLLRec(head)<<endl;
}
