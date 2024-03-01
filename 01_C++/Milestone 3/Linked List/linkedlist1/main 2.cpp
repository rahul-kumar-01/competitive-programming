#include<iostream>
using namespace std;
class Node{
public:
    int data;
    Node * next ;
    
    Node(int n){
        data = n;
        next = NULL;
    }
    
};
                            //outside of class
void print(Node * head){
    Node * temp = head;   //for not loosing head value
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

int main(){
    Node n1(2);
    Node * head = &n1;
    
    Node n2(5);
    Node n3(6);
    Node n4(7);
    Node n5(9);
    
    
    n1.next = & n2;
    n2.next = & n3;
    n3.next = & n4;
    n4.next = & n5;
    
    print(head);
    print(head);
    
    
    
    
    
//    dynamically node
//    Node * n3 = new Node (10);
//    Node * hea = n3;
//
//    Node * n4 = new Node (20);
//    n3->next = n4;
}
