#include<iostream>
using namespace std;
class dynamicArray{
private:
    int startIndex;
    int capacity;       //total size
    int *data;
public:
    dynamicArray(){
        capacity = 5;
        data = new int[5];
        startIndex = 0;
    }
    
    dynamicArray(dynamicArray const &d){
        // (shallow copy)  this->data = d.data;
        
        this->data = new int [d.capacity];
        for(int i=0;i<d.startIndex;++i){
            this->data[i]=d.data[i];
        }
        this->capacity = d.capacity;
        this->startIndex = d.startIndex;
    }
    
    //assingment copy constructor
    void operator=(dynamicArray const &d){
        this->data = new int [d.capacity];
        for(int i=0;i<d.startIndex;++i){
            this->data[i]=d.data[i];
        }
        this->capacity = d.capacity;
        this->startIndex = d.startIndex;
    }
    
    void print() const{
        for(int i=0;i<startIndex;++i){
            cout<<data[i]<<" ";
        }
        cout<<endl;
    }
    
    
    void addNumber(int n){
        if(startIndex == capacity){
            int * newdata = new int [2*capacity];
            for(int i=0;i<capacity;++i){
                newdata[i] = data[i];
            }
            delete []data;
            data = newdata;
            data[startIndex] = n;
            ++startIndex;
            
        }
        else{
            data[startIndex] = n;
            ++startIndex;
        }
    }
    
    int getNumberAtIndex(int n){
        if(n<startIndex){
            return data[n];
        }
        else
            return -1;
    }
    
    void replace_number(int index,int element){
        if(index<startIndex){
            data[index] = element;
        }
        else return ;
    }
    
    
    
};

int main(){
    
    dynamicArray d1;
    d1.addNumber(1);
    d1.addNumber(2);
    d1.addNumber(3);
    d1.addNumber(4);
    d1.addNumber(5);
    d1.addNumber(6);
    d1.addNumber(7);
    d1.addNumber(8);
    d1.addNumber(9);
    
    d1.print();

    cout<<d1.getNumberAtIndex(3)<<endl;
    d1.replace_number(2,0);
    
    d1.print();
    
    // NOTE : by default copy constructor & assigment copy constructor do shallow copy
    dynamicArray d2(d1);        //copy constructor
    d1.replace_number(0,0);
    dynamicArray d3;            //assigment copy constructor
    d3=d1;
    
    
    d1.print();
    d2.print();
    d3.print();
}
