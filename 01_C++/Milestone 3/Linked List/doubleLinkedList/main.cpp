//USE OF DOUBLE LINKED LIST
// 1.. LRU (least recently used) Cache
// 2.. forward and backward direction
// 3.. can be used in stack and queue

#include<iostream>
using namespace std;

class Node{
public:
    int data;
    Node * next;
    Node(int data){
        this->data = data;
        next = NULL;
    }
};

class DLLNode {        // (element) of double LL
public:
    int data;
    DLLNode* next;
    DLLNode* previous;
    
    DLLNode(int data){
        this->data = data;
        next = NULL;
        previous = NULL;
    }
    
};

class DLL{
public:
    DLLNode * front ;       //staring of DLL
    DLLNode * end ;         //end of DLL
    DLL(){
        front = NULL;
        end = NULL;
    }
    
    //single insetion
    void insert(int data){
        DLLNode * newNode = new DLLNode(data);
        if(end == NULL) {
            front = newNode;
            end = newNode;
        }
        else{
            end ->next = newNode;
            newNode->previous = end;
            end = newNode;
            
        }
    }

    
    void print(){
        DLLNode * temp = front;
        while(temp != NULL){
            cout<<temp->data<<" ";
            temp = temp->next;
        }
        cout<<endl;
    }
    
   void insertionAtFront(int data){
        DLLNode * temp = front;
        DLLNode * newNode = new DLLNode(data);
        newNode->next = front;
        temp->previous = newNode;
        front = newNode;
    }
    
    void insertionAtEnd(int data){
        DLLNode * temp = end;
        DLLNode * newNode = new DLLNode(data);
        end -> next = newNode;
        newNode->previous = temp;
        end = newNode;
    }
    
    //insertion before the node
    void insertion(int data,DLLNode* temp){
        if(temp == NULL) return;
        DLLNode * newNode = new DLLNode(data);
        newNode->next = temp;
        DLLNode * previousNode = temp->previous;
        newNode->previous = previousNode;
        previousNode->next = newNode;
        temp->previous =newNode;
    }
    
    void deletion(DLLNode* temp){
        if(temp == front){
            DLLNode* tempNext = temp->next;
            temp->next = NULL;
            delete temp;
            front = tempNext;
            return;
        }
        else if (temp == end){
            DLLNode * tempPre = temp->previous;
            tempPre->next = NULL;
            end = tempPre;
            delete temp;
            return;
        }
        else{
            DLLNode * tempNext = temp->next;
            DLLNode * tempPre = temp->previous;
            tempNext -> previous = tempPre;
            tempPre -> next = tempNext;
        }
    }
    
};

DLL insertionContinous(){
    cout<<"Enter the data : ";
    int data;
    cin>> data;
    
    DLLNode* head = NULL;
    DLLNode* temp = NULL;
    
    while(data != -1){
        DLLNode * newNode= new DLLNode (data);
        if(head == NULL){
            head = newNode;
            temp = newNode;
        }
        else{
            temp ->next = newNode;
            newNode->previous = temp;
            temp = newNode;
        }
        cout<<"Enter the data : ";
        cin>>data;
    }
    DLL ans;
    ans.front = head;
    ans.end = temp;
    return ans;
}





int main(){
    
    DLL head = insertionContinous();
    head.print();
    head.insertionAtEnd(6);
    head.print();
    head.deletion(head.front);
    cout<<"\nAfter the FRONT deletion"<<endl;
    head.print();
    head.deletion(head.end);
    cout<<"\nAfter the END deletion"<<endl;
    head.print();
    
    DLLNode * temp = head.front;
    int count  = 0;
        int index  = 2;
        while(count != index){
            temp = temp ->next;
            ++count;
        }
    
    
    head.deletion(temp);
    cout<<"\nAfter the "<< index <<" index deletion"<<endl;
    head.print();
//    DLL d;
//    d.insert(10);
//    d.insert(20);
//    d.insert(30);
//    d.insert(50);
//    d.insert(60);
//
//    d.print();
//    DLLNode* temp = d.front;
//
//
//
//    int count  = 0;
//    int index  = 3;
//    while(count != index){
//        temp = temp ->next;
//        ++count;
//    }
//
//    d.insertion(69, temp);
//
//    d.print();
//    d.insertionAtEnd(4);
//    d.insertionAtFront(0);
//    d.print();
//
    
}
