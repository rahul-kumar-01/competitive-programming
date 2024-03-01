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

class Pair{
public:
    Node * head ;
    Node * tail ;
};

Node * reversal_independent_part1(Node * head){
    Node * next = NULL;
    Node * temp = NULL;
    while(head != NULL){
        if(next == NULL){
            temp = head;
            next = head->next;
            head->next = NULL;
            head = next;
        }
        else{
            next = head->next;
            head->next = temp;
            temp = head;
            head = next;
            
        }
    }
    return temp;
}

Node * recursion_reversal_part2(Node * head){
    if(head == NULL || head -> next == NULL){
        return head;
    }
    Node * headOfSmallRecrsion = recursion_reversal_part2(head->next);
    Node * tail = headOfSmallRecrsion;
    while(tail->next != NULL){
        tail = tail -> next;
    }
    tail->next = head;
    head -> next = NULL;
    return headOfSmallRecrsion;
}
   
// we have to iterate multiple times because of recursion to find the tail  in previous reversal solution part2
// so to deal with this we have to create a function which return two value
// which is possible through use of class in function

Pair reversall_2(Node * head){
    if(head == NULL || head->next ==NULL){
        Pair ans;
        ans.head = head;
        ans.tail = head;
        return ans;
    }
    Pair smallans = reversall_2(head->next);
    smallans.tail->next = head;
    head->next = NULL;
    
    Pair finalAns ;
    finalAns.head = smallans.head;
    finalAns .tail = head;
    return finalAns;
    
}
Node * reversal(Node * head){
    return reversall_2(head).head;
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
void print(Node * p){
    Node * temp = p;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

Node *bubbleSort(Node *head)
{
    // Write your code here
    Node * head_copy = head;
    int count = 0;
    while(head_copy != NULL){
            ++count;
        head_copy = head_copy->next;
    }
    for(int i=0;i<count-1;++i){
        Node * previous = NULL;
        Node * next = NULL;
        Node * current = head;
        
        while(current->next != NULL){
            
            if((current->data) > (current->next->data)){
                if(previous != NULL){
                    previous ->next = next;
                    head = previous;
                }
                next = current->next;
                current ->next = next ->next;
                next ->next = current;
                previous = next;
            }
            else{
                previous = current;
                current = current->next;
            }
        }
    }
    return head;
}
Node* reversal_2(Node* head){
    if(head == NULL) return NULL;
    Node * temp = NULL;
    Node * next = NULL;
    while(head != NULL){
        if(temp == NULL){
            temp  = head;
            next = head->next;
            head->next = NULL;
            head = next;
        }
        else{
            next = head->next;
            head->next = temp;
            temp = head;
            head = next;
            
        }
    }
    return temp;
}
 

int main(){
    Node * head = take_input();
    print(head);
   
//    bubbleSort(head);
//    print(head);
//
    Node * head3 = reversal_2(head);
    print(head3);
//    Node * head2 = reversal_independent_part1(head);
//    print(head2);
//
//    Node * head3 = recursion_reversal_part2(head2);
//    print(head3);
//
    
}

