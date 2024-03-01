// USE OF LINKED LIST
//1.. use memory in a effective manner if we want 100 integer , and if we use array size in memory should in continuos but if we linked list it is not neccessaty that memory loction should be continous so it is more effective in term of memory allocation



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
    Node * head;
    Node * tail;
};

Pair reversal_2(Node* head){
    if(head == NULL || head->next == NULL){
        Pair p1;
        p1.head = head;
        p1.tail = head;
        return p1;
    }
    Pair ans = reversal_2(head->next);
    ans.tail->next = head;
    head->next = NULL;
    Pair newAns;
    newAns.head = ans.head;
    newAns.tail = head;
    return newAns;
}


Node * reversal(Node*head){
    return reversal_2(head).head;
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
int main(){
    Node * head = take_input();
    print(head);
    Node * head1 = reversal(head);
    print(head1);
}
