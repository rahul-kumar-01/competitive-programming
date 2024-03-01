template <typename t>
class Node{
public:
    Node<t> * next;             //specify because my Node class made of template
    t data;
    Node(t data){               //constructo don't require <t>
        next = NULL;
        this->data = data;
    }
};

template<typename t>
class Stack{
public:
    Node <t> * head ;
    int size;       //no of element present in stack
    Stack(){
        head = NULL;
        size = 0;
    }
    int getSize(){
        return size;
    }
    bool isEmpty(){
        return head == NULL;   //or we can use size==0
    }
    void push(t element){
        Node<t> * newNode = new Node<t> (element);  //because node is made of template we
                                                    // have to specify when ever we use
        if(head == NULL){       //no use of this if you can remove
            head = newNode;
        }
        else{
            newNode->next = head;
            head = newNode;
        }
        ++size;
    }
    t pop(){
        if(head == NULL){
            cout<<"stack is empty"<<endl;
            return 0;
        }
        
        t ans = head->data;
        Node <t> * temp = head;
        head = head->next;
        delete temp;
        --size;
        return ans;
    }
    t top(){
        if(isEmpty()){
            cout<<"stack is empty"<<endl;
            return 0;
        }
        return head->data;
    }
    
};
