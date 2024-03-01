template <typename t>
class Queues{
private:
    int firstIndex ;
    int nextIndex;
    int size;
    t * data ;
    int capacity;
public:
    Queues(int s){
        data = new t [s];
        firstIndex = -1;
        nextIndex = 0;
        size = 0;
        capacity = s;
    }
    
    //insert element
    void enqueue(t element){
        if(firstIndex == -1) {
            ++firstIndex;
        }
        if(size==capacity){
            t * newArray = new t [2*capacity];
            int j=0;
            for(int i=firstIndex;i<capacity;++i){
                newArray[j++] = data[i];
            }
            for(int i=0;i<nextIndex;++i){    //or first index
                newArray[j++] = data[i];
            }
            delete[]data;
            data = newArray;
            firstIndex = 0;
            nextIndex = capacity;
            capacity = 2* capacity;
        }
        data[nextIndex] = element;
        nextIndex = (nextIndex+1)%capacity;
        ++size;
        return;
    }
    t dequeue(){
        if(firstIndex == -1) {
            cout<<"queues is empty"<<endl;
            return 0;
        }
        t temp = data[firstIndex];
        firstIndex = (firstIndex+1)%capacity;
        --size;
        if(size==0){
            firstIndex = -1;
            nextIndex = 0;
        }
        return temp;
    }
    t front(){
        return data[firstIndex];
    }
    int getSize(){
        return size;
    }
    bool isEmpty(){
        return size == 0;
    }
};
