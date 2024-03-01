//keypoints - always use head == NULL && head->next == NULL both as base base return head ; it make code better


#include<iostream>
using namespace std;
class Node{
public:
    int data;
    Node* next;
    
    Node(int data){
        this->data = data;
        this->next = NULL;
    }

};

//recursion
int lengthRec(Node* head){
    if(head == NULL){
        return 0;
    }
    return 1 + lengthRec(head->next);
}

Node* insertRec(Node * head,int index,int data){
    if(head == NULL && index == 0){
        Node * newNode = new Node(data);
        return newNode;
    }
    if(index == 0){
        Node * newNode = new Node(data);
        newNode->next = head;
        return newNode;
    }
    Node* ans = insertRec(head->next, index-1, data);
    head->next = ans;
    return head;
}

Node * deleteNodeRec(Node * head,int index){
    if(head == NULL) return NULL;
    if(index == 0){
        Node * temp = head->next;
        delete head;
        return temp;
    }
    head->next = deleteNodeRec(head->next,index-1);
    return head;
}


Node* findNodeRec(Node * head,int data){
    if(head == NULL) return NULL;
    if(head -> data == data) return head;
    return findNodeRec(head->next , data);
}

Node * reverseLL(Node* head){
    Node * temp = head;
    Node * next = NULL;
    Node * previous = NULL;
    
    while(temp != NULL){
        next = temp->next;
        temp->next = previous;
        previous = temp;
        temp = next;
    }
    return previous;
}


Node* reverseLL2(Node*head){
    if(head == NULL) return NULL;
    Node* newHead = reverseLL2(head->next);
    Node * temp = newHead;
    while( newHead != NULL && newHead->next != NULL ){
        newHead = newHead->next;
    }
    if(newHead != NULL){
        newHead->next = head;
        head->next =  NULL;
        return temp;
    }
    else{
        return head;
    }
}

pair<Node*,Node*> reverseLLRec(Node* head){
    if(head == NULL){
        pair<Node*, Node*> p1;
        p1.first = head;
        p1.second = NULL;
        return p1;
    }
    pair<Node*,Node*> p2  = reverseLLRec(head->next);
    if(p2.second != NULL){
        p2.second->next = head;
        head->next = NULL;
    }
    else{
        p2.first = head;
        p2.second = NULL;
    }
    
    pair<Node*, Node*> p1;
    p1.first = p2.first;
    p1.second = head;
    return p1;
}





Node* insertNodeAti(Node*head,int index,int data){
    
    int count = 0;
    Node* temp = head;
    Node* newNode = new Node(data);
    
    if(index == 0){
        newNode->next = head;
        return newNode;
    }
    while(count != index-1){
        if(temp == NULL) return head;
        temp = temp ->next;
        ++count;
    }
    Node* indexNode = temp->next;
    
   
    temp->next = newNode;
    newNode->next = indexNode;
    return head;
}


Node* deleteNode(Node*head ,int index){
    int count = 0;
    Node * temp = head;
    Node * previous = NULL;
    if(index == 0){
        Node*temp = head;
        head = head->next;
        delete temp;
        return head;
    }
    while(count != index){
        previous = temp;
        temp = temp->next;
        ++count;
    }
    previous->next = temp->next;
    delete temp;
    return head;
}


void print(Node* head){
   while(head != NULL){
       cout<<head->data<<" ";
        head = head->next;
    }
    cout<<endl;
    return;
}
Node *mergeTwoSortedLinkedLists(Node *head1, Node *head2)
{
    //Write your code here
    // t is final
    Node * tHead = NULL;
    Node * tTail = NULL;
    if(head1==NULL) return head2;
    if(head2 == NULL) return head1;
    if(head1->data <= head2->data){
        tHead = head1;
        tTail = head1;
        head1 = head1->next;
    }
    else {
        tHead = head2;
        tTail = head2;
        head2 = head2->next;
    }


    while(head1 != NULL && head2 != NULL){
        if(head1->data  <=  head2->data){
            tTail ->next = head1;
            tTail = head1;
            head1 = head1->next;
        }
        else{
            tTail ->next = head2;
            tTail = head2;
            head2 = head2->next;
        }
    }
if(head1 ==NULL){
    tTail ->next = head2;
}
else if (head2 == NULL){
    tTail->next = head1;
}


return tHead;


}

Node* takeInput(){
    int data;
    cout<<"enter the node data : ";
    cin>>data;
    Node* head = NULL;
    Node* temp = NULL;
    while(data != -1){
        Node * newNode = new Node(data);
        if(head == NULL){
//            Node * newNode = new Node(data);
            head = newNode;
            temp = newNode;
        }
        else{
//            Node* newNode = new Node(data);
            temp->next = newNode;
            temp = temp->next;
        }
        cin>>data;
    }
    return head;
}


Node* removeDuplicate(Node * head,int data){
    if(head == NULL) return NULL;
    Node* temp = head;
    Node* next = NULL;
//    Node* previous = NULL;
    if(temp ->data == data){
        if(next == NULL){
            
            
        }
    }
    return NULL;
}

Node* appendLastToN(Node* head,int n){
    int count = 1;
    Node* temp = head;
    while(count != n-1){
        temp = temp->next;
        ++count;
    }
    Node * output = temp->next;
    temp->next = NULL;
    
    Node * outputtemp = output;
    
    while(outputtemp->next != NULL){
        outputtemp = outputtemp->next;
    }
    outputtemp->next = head;
    
    return output;
}

void printReverseLL(Node * head){
    if(head == NULL) return;
    printReverseLL(head->next);
    if(head != NULL){
        cout<<head->data<<" ";
    }
    
}

Node* midLL(Node* head){
    if(head == NULL) return NULL;
    Node * fast = head;
    Node * slow = head;
    
    while(fast->next != NULL && fast->next->next != NULL){
        fast = fast -> next ->next;
        slow = slow -> next;
    }
    return slow;
}

void removeDuplicates(Node * head){
    if(head == NULL) return ;
//    Node * temp = head;
    Node * next = head->next;
    
    while(next != NULL){
        if(head->data != next->data){
            head = head->next;
            next = next->next;
        }
        else{
            head->next = next->next;
            Node * temp = next;
            next = next->next;
            temp->next = NULL;
        }
        
    }
    return;
}

int findTheNode(Node* head,int n){
    if(head == NULL) return -1;
    if(head->data == n) return 0;
    int ans = findTheNode(head->next, n);
    if(ans != -1) return 1 + ans;
    else return -1;
}

Node* oddBeforeEven(Node* head){
    if(head == NULL) return NULL;
    Node * evenH = NULL;
    Node * evenT = NULL;
    Node * oddH = NULL;
    Node * oddT = NULL;
    Node * temp = head;
    
    while(temp != NULL){
        if(temp->data % 2 == 0){
            if(evenH == NULL){
                evenH = temp;
                evenT = temp;
            }
            else{
                evenT->next = temp;
                evenT = temp;
            }
        }
        
        else{
            if(oddH == NULL){
                oddH = temp;
                oddT = temp;
            }
            else{
                oddT->next = temp;
                oddT = temp;
            }
        }
        temp = temp->next;
    }
    if(evenT != NULL){
        evenT->next =  NULL;
    }
    else{
        oddT->next = NULL;
        return oddH;
    }
    
    if(oddT != NULL){
        oddT->next = evenH;
    }
    else{
        evenT->next = NULL;
        return evenH;
    }
    
    return oddH;
}

Node* deletenNodesAfterMnode(Node* head,int m,int n){
    if(m==0) return NULL;
    if(n==0) return head;
    Node* temp = head;
    int count = 0;
    int deleteIndex = 0;
    while(temp!=NULL){
        count = 0;
        deleteIndex = 0;
        while(count!=m-1){
            if(temp!=NULL){
                temp = temp->next;
            }
            ++count;
        }
        Node* ending = temp;
        while(deleteIndex != n+1){
            if(temp != NULL){
                temp = temp->next;
            }
            ++deleteIndex;
        }
        
        if(ending != NULL){
            ending ->next = temp;
        }
    }
    return head;
}


Node* swapTwoElement(Node* head,int i,int j){
    if(head == NULL) return 0;
    Node* head1 = NULL;
    Node* head2 = NULL;
    Node* previous1 = NULL;
    Node* previous2 = NULL;
    Node* temp = head;
    
    
    int count1 = 0,count2 = 0;
    while(count1 != i){
        previous1 = temp;
        temp = temp->next;
        ++count1;
    }
    head1 = temp;
    
    temp = head;
    while(count2 != j){
        previous2 = temp;
        temp = temp->next;
        ++count2;
    }
    head2 = temp;
    
    if(i==0 && abs(i-j) == 1){
        Node* help= head2->next;
        head2->next = head1;
        head1->next = help;
        return head2;
    }
    else if (i==0){
        Node * help = head2 -> next;
        head2 -> next = head1->next;
        previous2 -> next = head1;
        head1->next = help;
        return head2;
    }
    
    else if(abs(i-j) == 1){
        previous1->next = head2;
        head1->next = head2->next;
        head2->next = head1;
        return head;
    }
    else if(abs(i-j) >1){
        
        Node* help = head1->next;
        previous2->next =  head1;
        previous1->next = head2;
        head1->next = head2->next;
        head2->next = help;
        return head;
    }
    return head;
}

pair<Node*, Node*> kReverse(Node* head,int k){
    if(head == NULL){
        pair<Node*, Node*> p;
        p.first = NULL;
        p.second = NULL;
        return p;
    }
    int count = 0;
    Node* temp = head;
    Node* tail = NULL;
    while(count != k && temp->next != NULL){
        tail = temp;
        temp = temp->next;
        ++count;
    }
    if(count != k){
        return reverseLLRec(head);
    }
    else{
        tail->next = NULL;
        pair<Node*, Node*> p1 = reverseLLRec(head);
        pair<Node*,Node*> p2 =  kReverse(temp, k);
        p1.second ->next =  p2.first;
        pair<Node*, Node*> output ;
        output.first = p1.first;
        output.second = p2.second;
        return output;
    }
}

Node* bubbleSort(Node* head){
    if(head == NULL || head->next == NULL) return head;
    int count = 0;
    Node* previous1 = NULL;
    Node* previous2 = NULL;
    Node* temp = head;
    while(temp != NULL){
        temp = temp->next;
        ++count;
    }
    for(int i=count;i>=2;--i){
        temp = head;
        for(int j=0;j<count;++j){
            
            if(temp->data > temp->next->data){
                if(previous1 == NULL){
                    temp->next = temp->next->next;
                    temp->next->next = temp;
                    head = temp->next;
                    previous1 = temp;
                    temp = head->next;
                    previous2 = head;
                    
                }
                else{
                    temp->next = temp->next->next;
                    temp->next->next = temp;
                    previous1 ->next = temp->next;
                }
            }
            else{
                temp = temp->next;
                if(previous1 != NULL){
                    previous1 = previous1->next;
                }
                if(previous2 != NULL){
                    previous2 = previous2->next;
                }
            }
        }
        
    }
    return head;
}

int main(){
//    Node*head1 = takeInput();
//    print(head1);
//    printReverseLL(head);
//    print(head);
//    cout<<endl;
//
//    head = insertNodeAti(head, 3 , 45);
//    print(head);
//    head = deleteNode(head, 3);
//    print(head);
//    head = reverseLL(head);
//    print(head);
//    head = reverseLL2(head);
//    print(head);
//    pair<Node*,Node*>p1 =  reverseLLRec(head);
//    print(p1.first);
//    pair<Node*,Node*>p1 = reverseLLRec(head);
//    print(p1.first);
//    head = insertRec(head,2,69);
//    print(head);
//    cout<<lengthRec(head)<<endl;
//    head = deleteNodeRec(head,3);
//    print(head);
//    Node * temp = findNodeRec(head, 6);
//    if(temp == NULL){
//        cout<<"number not found"<<endl;
//    }
//    else{
//        cout<<"Number found"<<endl;
//    }
//    head = removeDuplicate(head, 2);
//    print(head);
//    head = appendLastToN(head, 4);
//    print(head);
//    Node * mid = midLL(head);
//    cout<<mid->data<<endl;
    
//    Node * head2 = takeInput();
//    Node * mergeNode = mergeTwoSorted(head1,head2);
//    print(mergeNode);
//
//    removeDuplicates(head1);
//    print(head1);
        
//    Node* head1 =takeInput();
//    print(head1);
//    Node* head2 = takeInput();
//    print(head2);
//    Node* head3 = mergeTwoSorted(head1, head2);
//    print(head1);
//    print(head2);
//    print(head3);
//
//    Node* head1 = takeInput();
//    Node* head2 = takeInput();
//    cout<<findTheNode(head, 10)<<endl;
//    Node * head3 = mergeTwoSortedLinkedLists(head1, head2);
//    print(head1);
//    print(head2);
//    print(head3);

    Node * head = takeInput();
    print(head);
//    head = oddBeforeEven(head);
//    head = deletenNodesAfterMnode(head, 2, 2);
//    print(head);
    head = swapTwoElement(head, 0,2);
    print(head);
//    pair<Node*, Node*> p = kReverse(head, 4);
//    print(p.first);
//    head = bubbleSort(head);
//    print(head);
}

