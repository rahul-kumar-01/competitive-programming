template <typename t>
class Queues{
private:
    int firstIndex ;
    int nextIndex;
    int pushIndex;
    int size;
    t * data ;
public:
    Queues(int s){
        data = new t [s];
        firstIndex = -1;
        pushIndex = 0;
        nextIndex = 0;
        size = 0;
    }
    void push(t element){
        if(firstIndex == -1) {
            ++firstIndex;
        }
        if(nextIndex == 5){
            if(pushIndex >= firstIndex) cout<<"Queues is full."<<endl;
            else {
                data[pushIndex] = element;
                ++pushIndex;
                ++size;
            }
        }
        else{
            data[nextIndex] = element;
            ++nextIndex;
            ++size;
        }
        return;
    }
    t pop(){
        if(firstIndex == -1) {
            cout<<"queues is empty"<<endl;
            return 0;
        }
        int temp = firstIndex;
        ++firstIndex;
        --size;
        return data[temp];
    }
    t top(){
        return data[firstIndex];
    }
    int Size(){
        return size;
    }
    bool isEmpty(){
        return size == 0;
    }
    
};
