class queue{
    int startIndex ;
    int nextIndex;
    int size ;
    int * arr;
    int data;
    int capacity;
    
public:
    queue(int capacity){
        arr = new int[capacity];
        startIndex = -1;
        nextIndex = 0;
        size = 0;
        this->capacity = capacity;
    }
    
    bool isEmpty(){
        if(startIndex == -1) return true;
        else return false;
    }
    
    void push(int data){
        if(startIndex == -1){
            arr[startIndex] = data;
            ++startIndex;
        }
        else if(nextIndex == capacity){
            int * newArr = new int[2*capacity];
            for(int i=0;i<capacity;++i){
                arr[i] = newArr[i];
            }
            arr = newArr;
            capacity = 2* capacity;
            arr[nextIndex] = data;
            ++nextIndex;
            ++size;
        }
        
    }
    
    int top(){
        return arr[startIndex];
    }
    
    int length(){
        return nextIndex;
    }
};
