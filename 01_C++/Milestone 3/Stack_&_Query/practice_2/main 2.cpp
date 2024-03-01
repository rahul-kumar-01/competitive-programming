#include<iostream>
using namespace std;
class Node{
public:
    int data;
    Node * next;

    Node(int num){
        data = num;
        next = NULL;
    }
    
};
Node* get_input(){
    Node* head = NULL;
    Node * temp = NULL;
    int data;
    cin>>data;
    while(data != -1){
        Node * newNode = new Node(data);
        if(head==NULL){
            head = newNode;
            temp = newNode;
        }
        else{
            head->next = newNode;
            head = newNode;
        }
        cin>>data;
    }
    return temp;
}

void print(Node * head){
    while(head!=NULL){
        cout<<head->data<<" ";
        head = head->next;
    }
}

class Pair{
public:
    Node * head;
    Node * tail;

    Pair(){
        head = NULL;
        tail = NULL;
    }
};

Pair reverse_2(Node * head1){
    Pair p1;
    p1.head = head1;
    p1.tail = head1;
    
    reverse_2(head1->next);
    return p1;
    
}


Node * reverse(Node * head,int k){
    Node * head1 = head;
    Node * tail1 = head;
    k = 1;
    while(k!=4){
        tail1 = tail1->next;
        ++k;
    }
    Node * head2 = tail1->next;
    
    tail1->next = NULL;
    Node * ans1 = reverse_2(head1).head;
    Node * ans2 = reverse_2(head1).tail;
    
    Node * ans3 = reverse_2(head2).head;
    
    ans2->next = ans3;
    
    
    return ans1;
    
    
    
    
    
    
}


int main(){
    
    Node * head = get_input();
    print(head);
    
    int k;
    cin>>k;
    Node * head2  = reverse(head,k);
    print(head2);
    
    
}
