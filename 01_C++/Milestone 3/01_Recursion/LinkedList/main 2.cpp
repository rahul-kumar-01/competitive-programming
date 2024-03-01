#include<iostream>
#include"Node.h"
using namespace std;




Node* reversal_1(Node*head){
    if(head == NULL || head->next == NULL) return head;
    int temp = len(head);
    Node * returnHead = NULL;
    for(int i = temp-2;i>=0;--i){
        int count  = 0;
        Node * temp = head;
        while(count != i){
            temp = temp->next;
            ++count;
        }
        if(returnHead == NULL) returnHead = temp->next;
        temp->next->next = temp;
    }
    head->next = NULL;
    return returnHead;
}

Node* reversal_2(Node* head){
    if(head == NULL || head->next == NULL) return head;
    Node* returnHead = reversal_2(head->next);
    Node* temp = returnHead;
    
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = head;
    head->next = NULL;
    return returnHead;
}

pair<Node* , Node*> reversal_3(Node* head){
    if(head == NULL || head ->next == NULL){
        pair<Node*, Node*> p;
        p.first = head;
        p.second = head;
        return p;
    }
    
    pair<Node*,Node*> p = reversal_3(head->next);
    p.second->next = head;
    head->next = NULL;
    
    pair<Node*, Node*> ans;
    ans.first = p.first;
    ans.second = head;
    return ans;
}

int main(){
    
    Node * head = takeInput();
    print(head);

//    head = reversal_1(head);
//    print(head);
//    head = reversal_2(head);
//    print(head);
    pair<Node*,Node*> ans = reversal_3(head);
    print(ans.first);
    
}
