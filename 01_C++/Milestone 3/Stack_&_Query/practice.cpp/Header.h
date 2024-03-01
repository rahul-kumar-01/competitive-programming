class Node{
public:
    int data;
    Node * next;
    Node(int data){
        this->data = data;
        next = NULL;
    }
};


class Queue{
    int * data;
    int frontIndex;
    int nextIndex;
    int capacity;
    int size;
public:
    Queue(int capacity){
        data = new int[capacity];
        frontIndex = -1;
        nextIndex = 0;
        this->capacity = capacity;
        size = 0;
    }
    
    
    int pop(){
        int temp = data[frontIndex];
        ++frontIndex;
        --size;
        return temp;
    }
    
    void push(int element){
        if(frontIndex == -1){
            ++frontIndex;
        }
        data[nextIndex] = element;
        ++size;
        ++nextIndex;
        if(nextIndex == capacity){
            nextIndex = nextIndex % capacity;
        }
    }
    
    int front(){
        return data[frontIndex];
    }
    
    int getSize(){
        return size;
    }
};


   
