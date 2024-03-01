template<typename t>
class Node {
        public :
        t data;
        Node<t> *next;

        Node(t data) {
            this->data = data;
            next = NULL;
        }
    };

template<typename t>
class Queue {
    // Define the data members
    Node<t> * head ;
    Node<t> * tail;
    int size;
   public:
    Queue() {
        head = NULL;
        tail = NULL;
        size = 0;
    }
    
    int getSize() {
        // Implement the getSize() function
        return size;
    }

    bool isEmpty() {
        // Implement the isEmpty() function
        return size==0;
    }

    void enqueue(int data) {
        // Implement the enqueue() function

        Node<t> * newNode = new Node<t>(data);
        if(head==NULL){
            head = newNode;
            tail = newNode;
        }
        tail->next = newNode;
        tail = newNode;
        ++size;
        return;
    }

    t dequeue() {
        // Implement the dequeue() function
        if(size==0) return -1;
        Node<t> * temp = head;
        t ans = head->data;
        head = head->next;
        delete temp;
        --size;
        return ans;
    }

    t front() {
        // Implement the front() function
        if(size==0) return -1;
        return head->data;
    }
};
